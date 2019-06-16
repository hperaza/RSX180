/***********************************************************************

   This file is part of vol180, an utility to handle RSX180 volumes.
   Copyright (C) 2008-2019, Hector Peraza.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

#include "buffer.h"
#include "bitmap.h"
#include "fileio.h"
#include "indexf.h"
#include "dirio.h"

extern struct FCB *mdfcb, *cdfcb;

/* TODO:
 * - set lock bit in inode attrib when file is opened, in case this
 *   application is killed while a file transfer is in progress
 * - ensure seq number is still valid for r/w/seek/etc. operations
 * - update inode when block is allocated/freed
 * - update inode mdate when file is written to
 */

/*-----------------------------------------------------------------------*/

void dump(unsigned char *buf, int len) {  /* for debug */
  int i, c;
  unsigned addr;
  
  if (!buf) return;
  
  len = (len + 15) & 0xFFF0;
          
  for (addr = 0; addr < len; addr += 16) {
    printf("%04X: ", addr);
    for (i = 0; i < 16; ++i)
      printf("%02X ", buf[addr+i]);
    printf("   ");
    for (i = 0; i < 16; ++i)
      c = buf[addr+i], fputc(((c >= 32) && (c < 128)) ? c : '.', stdout);
    printf("\n");
  }
}

/* Return a string representing the file name stored in a FCB */
char *get_file_name(struct FCB *fcb) {
  static char str[30];
  int i;
  char *p;
  
  if (!fcb) return "";

  p = str;
  if (*fcb->dirname) {
    *p++ = '[';
    for (i = 0; i < 9; ++i) if (fcb->dirname[i] != ' ') *p++ = fcb->dirname[i];
    *p++ = ']';
  }
  for (i = 0; i < 9; ++i) if (fcb->fname[i] != ' ') *p++ = fcb->fname[i];
  *p++ = '.';
  for (i = 0; i < 3; ++i) if (fcb->ext[i] != ' ') *p++ = fcb->ext[i];
  *p++ = ';';
  snprintf(p, 5, "%d", fcb->vers);

  return str;
}

/* Return a string containing the directory name stored in a FCB,
 * excluding the brackets */
char *get_dir_name(struct FCB *fcb) {
  static char str[10];
  int i;
  char *p;
  
  if (!fcb) return "";

  p = str;
  for (i = 0; i < 9; ++i) if (fcb->fname[i] != ' ') *p++ = fcb->fname[i];
  *p = '\0';

  return str;
}

/* Parse file name */
int parse_name(char *str, char *dirname, char *fname, char *ext, short *vers) {
  char *p, *q, *r;
  int  len, maxlen;
  
  *dirname = *fname = *ext = '\0';
  *vers = 0;
  p = str;
  if (*p == '[') {
    q = strchr(++p, ']');
    if (!q) return 0;
    len = q - p;
    if (len > 9) len = 9;
    strncpy(dirname, p, len);
    dirname[len] = '\0';
    p = q + 1;
  }
  q = strchr(p, '.');
  r = fname;
  maxlen = 9;
  if (q) {
    len = q - p;
    if (len > 9) len = 9;
    strncpy(fname, p, len);
    fname[len] = '\0';
    p = q + 1;
    r = ext;
    maxlen = 3;
  }
  q = strchr(p, ';');
  if (q) {
    len = q - p;
    if (len > maxlen) len = maxlen;
    strncpy(r, p, len);
    r[len] = '\0';
    *vers = atoi(q + 1);
  } else {
    len = strlen(p);
    if (len > maxlen) len = maxlen;
    strncpy(r, p, len);
    r[len] = '\0';
  }
  
  return 1;
}

#ifndef FILEIO_READ_ONLY
/* Flush file contents to disk image */
int flush_file(struct FCB *fcb) {
  if (!fcb) return 1;

  if (fcb->filbuf) flush_block(fcb->filbuf);
  if (fcb->allocbuf) flush_block(fcb->allocbuf);
  
  return 0;
}
#endif

/* Seek file to absolute byte position */
int file_seek(struct FCB *fcb, unsigned long pos) {
  unsigned blkno;
  
  if (!fcb) return 1;

  blkno = (pos >> 9);          /* block number = pos / 512 */
  fcb->byteptr = pos & 0x1FF;  /* byte pos in block = pos % 512 */
  
  if (fcb->nused == 0) {
    /* file is empty */
    fcb->curblk = 0;
    fcb->byteptr = 0;
    return 1;
  } else if (blkno + 1 == fcb->nused) {
    /* on last block */
    if (fcb->byteptr > fcb->lbcount) fcb->byteptr = fcb->lbcount;
  } else if (blkno + 1 > fcb->nused) {
    /* beyond the end of file */
    blkno = fcb->nused - 1;
    fcb->byteptr = fcb->lbcount;
  }
  
  if (blkno != fcb->curblk) {
    /* need to load new block */
    fcb->curblk = blkno;
    if (fcb->attrib & _FA_CTG) {
      /* compute absolute block number for contiguous file */
      blkno = fcb->stablk + fcb->curblk;
    } else {
      /* for non-contiguous files, find absolute block number in alloc map */
      fcb->curalloc = fcb->stablk;  /* start from the beginning */
      release_block(fcb->allocbuf);
      fcb->allocbuf = get_block(fcb->stablk);

      while (blkno >= 254) {
        /* traverse list of blocks: skip first complete alloc blocks
           until blkno is in the 0..253 range */
        fcb->curalloc = fcb->allocbuf->data[2] | (fcb->allocbuf->data[3] << 8);
        if (fcb->curalloc == 0) return 1;
        release_block(fcb->allocbuf);
        fcb->allocbuf = get_block(fcb->curalloc);
        blkno -= 254;
      }

      /* set pointer to current block index in alloc buf */
      fcb->blkptr = blkno * 2 + 4;
      /* fetch the absolute block number */
      blkno = fcb->allocbuf->data[fcb->blkptr] |
             (fcb->allocbuf->data[fcb->blkptr+1] << 8);

    }
    release_block(fcb->filbuf);
    fcb->filbuf = get_block(blkno);  /* load the new data buffer */
    return 0;  /* success */
  } else {
    /* we're already on the correct block */
    return 0;
  }

  return 1;
}

/* Return the current file position */
unsigned long file_pos(struct FCB *fcb) {
  unsigned long fpos;
  
  if (!fcb) return 0;

  if (fcb->nused == 0) {
    fpos = 0;
  } else {
    fpos = (unsigned long) fcb->curblk * 512L + (unsigned long) fcb->byteptr;
  }
  
  return fpos;
}

/* Read 'len' bytes from file, returns the actual number of bytes read.
 * Note that a max of 65536 bytes can be read (full 8080 address space,
 * anyway). Handles both contiguous and non-contiguous files. */
int file_read(struct FCB *fcb, unsigned char *buf, unsigned len) {
  unsigned nbytes, nread, buflen;

  if (!fcb) return 0;

  /* empty file? */
  if (fcb->nused == 0) return 0;
  
  /* see if we are already at the end of file */
  if (end_of_file(fcb)) return 0;
  
  if (fcb->filbuf == NULL) {
    /* first time read */
    if (!first_data_block(fcb, 0)) {
      return 0;
    }
  }

  nread = 0;
  for (;;) {
    /* buflen = how many bytes we've in current block */
    buflen = (fcb->curblk + 1 == fcb->nused) ? fcb->lbcount : 512;
    if (fcb->byteptr + len <= buflen) {
      /* all the data we need is on this block */
      memcpy(buf, &fcb->filbuf->data[fcb->byteptr], len);
      /* advance pointers and we're done */
      fcb->byteptr += len;
      nread += len;
      break;
    } else {
      /* nbytes = how many bytes are left on this block */
      nbytes = buflen - fcb->byteptr;
      if (nbytes > 0) {
        /* copy whaterver we have to dest buffer */
        memcpy(buf, &fcb->filbuf->data[fcb->byteptr], nbytes);
        /* advance pointers */
        buf += nbytes;
        len -= nbytes;
        nread += nbytes;
      }
      if (buflen < 512) {
        /* last block is incomplete, done reading (end of file) */
        fcb->byteptr = buflen;
        break;
      }
      /* time to read from next block */
      if (!next_data_block(fcb, 0)) {
         break; /* eof */
      }
    }
  }

  return nread;
}

#ifndef FILEIO_READ_ONLY
/* Write 'len' bytes to file, returns the actual number of bytes written.
 * Note that a max of 65536 bytes can be written (full 8080 address space,
 * anyway) */
int file_write(struct FCB *fcb, unsigned char *buf, unsigned len) {
  unsigned nbytes, nwritten;

  if (!fcb) return 0;
  
  if (fcb->filbuf == NULL) {
    /* first time write */
    if (!first_data_block(fcb, 1)) {
      return 0;
    }
  }

  nwritten = 0;
  for (;;) {
    if (fcb->byteptr + len <= 512) {
      /* data to write fits entirely in the current block */
      memcpy(&fcb->filbuf->data[fcb->byteptr], buf, len);
      fcb->filbuf->modified = 1;
      fcb->byteptr += len;
      if (fcb->nused == fcb->curblk + 1) {
        /* we're on last block: adjust lbcount if necessary */
        if (fcb->byteptr > fcb->lbcount) fcb->lbcount = fcb->byteptr;
      }
      nwritten += len;
      break;
    } else {
      /* data to write will overflow to next block(s) */
      nbytes = 512 - fcb->byteptr;  /* how many bytes left on this block */
      if (nbytes > 0) {
        /* fill the rest of this block */
        memcpy(&fcb->filbuf->data[fcb->byteptr], buf, nbytes);
        fcb->filbuf->modified = 1;
        buf += nbytes;
        len -= nbytes;
        nwritten += nbytes;
      }
      if (!next_data_block(fcb, 1)) {
        break; /* no more disk space */
      }
    }
  }

  return nwritten;
}
#endif

/* Return 1 if file position is at or beyond the end */
int end_of_file(struct FCB *fcb) {
  if (fcb->curblk + 1 > fcb->nused) {
    /* beyond last block */
    return 1;
  } else if (fcb->curblk + 1 == fcb->nused) {
    /* on last block, see if we're beyond byte count */
    if (fcb->byteptr >= fcb->lbcount) return 1;
  }
  return 0;
}

/* Retrieve first data block of file. Used by the fileread (allocnew == 0)
 * and filewrite (allocnew != 0) routines above. */
int first_data_block(struct FCB *fcb, int allocnew) {
  unsigned int blkno;
  
  if (fcb->filbuf != NULL) return 1;  /* already have it */

  if (fcb->attrib & _FA_CTG) {
    /* contiguous files */
    if (fcb->curblk + 1 > fcb->nused) {
#ifndef FILEIO_READ_ONLY
      if (!allocnew) return 0;  /* read operation: eof */
      if (fcb->nalloc > fcb->nused) {
        ++fcb->nused;
        blkno = fcb->stablk + fcb->curblk;
        fcb->lbcount = 0;
        release_block(fcb->filbuf);
        fcb->filbuf = new_block(blkno);
        fcb->filbuf->modified = 1;
        return 1;
      } else {
        return 0; /* TODO: try to extend contiguous space */
      }
#else
      return 0;
#endif
    } else {
      blkno = fcb->stablk + fcb->curblk; // fcb->stablk;
      fcb->filbuf = get_block(blkno);  /* load data block */
      return 1; /* success */
    }
  } else {
    /* non-contiguous files */
    blkno = fcb->allocbuf->data[fcb->blkptr] |
           (fcb->allocbuf->data[fcb->blkptr+1] << 8);
    if (blkno == 0) {
#ifndef FILEIO_READ_ONLY
      if (!allocnew) return 0; /* read operation: eof */
      /* allocate a new data block */
      blkno = alloc_block();
      if (blkno == 0) {
        /* no more disk space */
        return 0;
      }
      ++fcb->nused;
      fcb->nalloc = fcb->nused;
      fcb->lbcount = 0;
      fcb->allocbuf->data[fcb->blkptr] = blkno & 0xFF;
      fcb->allocbuf->data[fcb->blkptr+1] = (blkno >> 8) & 0xFF;
      fcb->allocbuf->modified = 1;
      fcb->filbuf = new_block(blkno);
      fcb->filbuf->modified = 1;
      return 1;
#else
      return 0;
#endif
    }
    fcb->filbuf = get_block(blkno);  /* load data block */
    return 1; /* success */
  }
}

/* Retrieve next data block of file. Used by the fileread (allocnew == 0)
 * and filewrite (allocnew != 0) routines above. */
int next_data_block(struct FCB *fcb, int allocnew) {
  unsigned int blkno, allocblk;

  ++fcb->curblk;
  fcb->byteptr = 0;

  if (fcb->attrib & _FA_CTG) {
    /* contiguous files */
    if (fcb->curblk + 1 > fcb->nused) {
#ifndef FILEIO_READ_ONLY
      if (!allocnew) return 0; /* read operation: eof */
      if (fcb->nalloc > fcb->nused) {
        ++fcb->nused;
        blkno = fcb->stablk + fcb->curblk;
        fcb->lbcount = 0;
        release_block(fcb->filbuf);
        fcb->filbuf = new_block(blkno);
        fcb->filbuf->modified = 1;
      } else {
        return 0;  /* TODO: try to extend contiguous space */
      }
#else
      return 0;
#endif
    } else {
      blkno = fcb->stablk + fcb->curblk;
      release_block(fcb->filbuf);
      fcb->filbuf = get_block(blkno);
    }
  } else {
    if (fcb->curblk + 1 > fcb->nused) {
#ifndef FILEIO_READ_ONLY
      if (!allocnew) return 0; /* reached end of file */
#else
      return 0;
#endif
    }
    /* non-contiguous file: follow the chain of alloc blocks */
    if (fcb->blkptr == 510) {
      /* time to load next alloc block */
      /* get 'next' pointer from alloc map */
      allocblk = fcb->allocbuf->data[2] | (fcb->allocbuf->data[3] << 8);
      if (allocblk == 0) {
#ifndef FILEIO_READ_ONLY
        /* 'next' pointer is null */
        if (!allocnew) return 0; /* read operation: eof */
        /* write operation: create a new block */
        allocblk = alloc_block();
        if (allocblk == 0) {
          /* no more space */
          --fcb->curblk;
          fcb->byteptr = 512;
          return 0;
        }
        /* set 'next' link on old alloc block */
        fcb->allocbuf->data[2] = allocblk & 0xFF;
        fcb->allocbuf->data[3] = (allocblk >> 8) & 0xFF;
        fcb->allocbuf->modified = 1;
        release_block(fcb->allocbuf);
        fcb->allocbuf = new_block(allocblk);
        /* set 'prev' link on new block */
        fcb->allocbuf->data[0] = fcb->curalloc & 0xFF;
        fcb->allocbuf->data[1] = (fcb->curalloc >> 8) & 0xFF;
        fcb->allocbuf->modified = 1;
#else
        return 0;
#endif
      } else {
        /* 'next' pointer is valid */
        release_block(fcb->allocbuf);
        fcb->allocbuf = get_block(allocblk);
      }
      fcb->curalloc = allocblk;
      fcb->blkptr = 4;
    } else {
      /* point to next block in alloc map */
      fcb->blkptr += 2;
    }

    /* fetch absolute block number from alloc map */
    blkno = fcb->allocbuf->data[fcb->blkptr] |
           (fcb->allocbuf->data[fcb->blkptr+1] << 8);
    release_block(fcb->filbuf);
    
    if (blkno == 0) {
#ifndef FILEIO_READ_ONLY
      if (!allocnew) { fcb->filbuf = NULL; return 0; } /* read operation: eof */
      /* allocate a new data block */
      blkno = alloc_block();
      if (blkno == 0) {
        /* no more disk space */
#if 0
        fcb->curblk = fcb->nused;
        fcb->byteptr = 0;
#else
        --fcb->curblk;
        fcb->byteptr = 512;
#endif
        return 0;
      }
      ++fcb->nused;
      fcb->nalloc = fcb->nused;
      fcb->lbcount = 0;
      fcb->allocbuf->data[fcb->blkptr] = blkno & 0xFF;
      fcb->allocbuf->data[fcb->blkptr+1] = (blkno >> 8) & 0xFF;
      fcb->allocbuf->modified = 1;
      fcb->filbuf = new_block(blkno);
      fcb->filbuf->modified = 1;
#else
      fcb->filbuf = NULL;
      return 0;
#endif
    } else {
      fcb->filbuf = get_block(blkno);  /* load next data block */
    }
  }

  return 1; /* success */
}

/* Close file. The FCB is not freed. */
int close_file(struct FCB *fcb) {
  unsigned char inode[32];
  unsigned short ino;
  time_t now;

  if (!fcb) return 0;
  
  time(&now);

  release_block(fcb->allocbuf);
  release_block(fcb->filbuf);

  ino = fcb->inode;
  if (ino == 0) return 0;

  if (read_inode(ino, inode) == 0) return 0; /* panic */
  if ((inode[0] == 0) && (inode[1] == 0)) return 0; /* panic */
  inode[10] = fcb->nalloc & 0xFF;
  inode[11] = (fcb->nalloc >> 8) & 0xFF;
  inode[12] = fcb->nused & 0xFF;
  inode[13] = (fcb->nused >> 8) & 0xFF;
  inode[14] = fcb->lbcount & 0xFF;
  inode[15] = (fcb->lbcount >> 8) & 0xFF;
  set_mdate(inode, now);
#ifndef FILEIO_READ_ONLY
  write_inode(ino, inode);
#endif

  return 1;
}

/* Set file dates. */
int set_file_dates(struct FCB *fcb, time_t created, time_t modified) {
  unsigned char inode[32];
  unsigned short ino;

  if (!fcb) return 0;

  ino = fcb->inode;
  if (ino == 0) return 0;

  if (read_inode(ino, inode) == 0) return 0; /* panic */
  if ((inode[0] == 0) && (inode[1] == 0)) return 0; /* panic */
  set_cdate(inode, created);
  set_mdate(inode, modified);
#ifndef FILEIO_READ_ONLY
  write_inode(ino, inode);
#endif

  return 1;
}

/* Open file in master directory */
struct FCB *open_md_file(char *name) {
  struct FCB *fcb;
  unsigned char dirent[16];
  unsigned char inode[32];
  unsigned short ino;
  char dname[10], fname[10], ext[4];
  short vers;
  
  if (!parse_name(name, dname, fname, ext, &vers)) {
    printf("Invalid file name\n");
    return NULL;
  }

  if (!mdfcb) return NULL;

  file_seek(mdfcb, 0L);
  for (;;) {
    if (file_read(mdfcb, dirent, 16) != 16) return NULL;
    ino = dirent[0] | (dirent[1] << 8);
    if ((ino != 0) && match(dirent, fname, ext, vers)) {
      if (read_inode(ino, inode) == 0) return NULL; /* panic */
      if ((inode[0] == 0) && (inode[1] == 0)) return NULL; /* panic */

      fcb = (struct FCB *) calloc(1, sizeof(struct FCB));
      fcb->attrib = inode[2];
      strcpy(fcb->dirname, "MASTER");
      strncpy(fcb->fname, (char *) &dirent[2], 9);
      strncpy(fcb->ext, (char *) &dirent[11], 3);
      fcb->vers = dirent[14] | (dirent[15] << 8);
      fcb->user = inode[6];
      fcb->group = inode[7];
      fcb->inode = ino;
      fcb->lnkcnt = inode[0] | (inode[1] << 8);
      fcb->seqno = inode[4] | (inode[5] << 8);
      fcb->curblk = 0;
      fcb->byteptr = 0;
      fcb->nalloc = inode[10] | (inode[11] << 8);
      fcb->nused = inode[12] | (inode[13] << 8);
      fcb->lbcount = inode[14] | (inode[15] << 8);
      fcb->stablk = inode[8] | (inode[9] << 8);
      if (fcb->attrib & _FA_CTG) {
        fcb->blkptr = 0;
        fcb->allocbuf = NULL;
        fcb->curalloc = 0;
      } else {
        fcb->blkptr = 4;
        fcb->allocbuf = get_block(fcb->stablk);
        fcb->curalloc = fcb->stablk;
      }
      fcb->filbuf = NULL;
      return fcb;
    }
  }
  
  return NULL;
}

/* Open file, returns a newly allocated FCB. */
struct FCB *open_file(char *name) {
  struct FCB *fcb, *dirfcb;
  char dname[10], fname[10], ext[4];
  unsigned char temp[16], dirent[16], inode[32];
  unsigned short ino;
  short vers, dvers, hivers;
  int found, dir_close_flag;

  if (!parse_name(name, dname, fname, ext, &vers)) {
    printf("Invalid file name\n");
    return NULL;
  }

  if (*dname) {
    char mdfile[20];
    strcpy(mdfile, dname);
    strcat(mdfile, ".DIR");
    dirfcb = open_md_file(mdfile);
    dir_close_flag = 1;
  } else {
    dirfcb = cdfcb;
    dir_close_flag = 0;
  }

  if (!dirfcb) return NULL;
  
  /* if no version specified, open the highest version */
  found = 0;
  hivers = 0;  /* to track highest version number */
  file_seek(dirfcb, 0L);
  for (;;) {
    if (file_read(dirfcb, temp, 16) != 16) break;
    ino = temp[0] | (temp[1] << 8);
    dvers = temp[14] | (temp[15] << 8);
    if ((ino != 0) && match(temp, fname, ext, vers)) {
      if ((vers > 0) || (dvers > hivers)) {
        /* note that this works also in case of explicit version,
         * since 'match' also matches the version number if > 0,
         * and there will be just one single match. */
        memcpy(dirent, temp, 16);
        hivers = dvers;
        found = 1;
      }
    }
  }
  
  if (!found) return NULL;

  ino = dirent[0] | (dirent[1] << 8);
  if (ino == 0) return NULL;  /* should not happen */
  if (read_inode(ino, inode) == 0) return NULL;
  if ((inode[0] == 0) && (inode[1] == 0)) return NULL;

  fcb = (struct FCB *) calloc(1, sizeof(struct FCB));
  fcb->attrib = inode[2];
  strncpy(fcb->dirname, dirfcb->fname, 9);
  strncpy(fcb->fname, (char *) &dirent[2], 9);
  strncpy(fcb->ext, (char *) &dirent[11], 3);
  fcb->vers = dirent[14] | (dirent[15] << 8);
  fcb->user = inode[6];
  fcb->group = inode[7];
  fcb->inode = ino;
  fcb->lnkcnt = inode[0] | (inode[1] << 8);
  fcb->seqno = inode[4] | (inode[5] << 8);
  fcb->curblk = 0;
  fcb->byteptr = 0;
  fcb->nalloc = inode[10] | (inode[11] << 8);
  fcb->nused = inode[12] | (inode[13] << 8);
  fcb->lbcount = inode[14] | (inode[15] << 8);
  fcb->stablk = inode[8] | (inode[9] << 8);
  if (fcb->attrib & _FA_CTG) {
    fcb->blkptr = 0;
    fcb->allocbuf = NULL;
    fcb->curalloc = 0;
  } else {
    fcb->blkptr = 4;
    fcb->allocbuf = get_block(fcb->stablk);
    fcb->curalloc = fcb->stablk;
  }
  fcb->filbuf = NULL;
  
  if (dir_close_flag) {
    close_file(dirfcb);
    free(dirfcb);
  }

  return fcb;
}

#ifndef FILEIO_READ_ONLY
/* Create a file. If the file is contiguous, allocate the specified number
 * of blocks. If not contiguous, allocate just the first allocation block. */
struct FCB *create_file(char *filename, char group, char user,
                        int contiguous, unsigned csize) {
  unsigned char dirent[16], inode[32], found;
  char dname[10], fname[10], ext[4], newname[256];
  unsigned long cpos, fpos;
  unsigned short ino, blkno;
  short dvers, vers, hivers;
  time_t now;
  struct FCB *dirfcb;
  int dir_close_flag;
  
  if (!parse_name(filename, dname, fname, ext, &vers)) {
    printf("Invalid file name\n");
    return NULL;
  }

  /* find a free inode */
  ino = new_inode();
  if (ino == 0) {
    fprintf(stderr, "Index file full\n");
    return NULL;
  }
  
  if (*dname) {
    char mdfile[20];
    strcpy(mdfile, dname);
    strcat(mdfile, ".DIR");
    dirfcb = open_md_file(mdfile);
    dir_close_flag = 1;
  } else {
    dirfcb = cdfcb;
    dir_close_flag = 0;
  }

  if (!dirfcb) return NULL;
  
  /* create a new version if file exists */
  file_seek(dirfcb, 0L);
  found = 0;
  hivers = 0;  /* to track highest version */
  for (;;) {
    cpos = file_pos(dirfcb);
    if (file_read(dirfcb, dirent, 16) != 16) break; /* at end of directory */
    if ((dirent[0] == 0) && (dirent[1] == 0)) {
      if (!found) fpos = cpos;  /* remember this free dir entry */
      found = 1;
    } else if (match(dirent, fname, ext, 0)) {
      dvers = dirent[14] | (dirent[15] << 8);
      if ((vers > 0) && (vers == dvers)) {
        fprintf(stderr, "File exists\n");
        if (dir_close_flag) {
          close_file(dirfcb);
          free(dirfcb);
        }
        return NULL;
      }
      if (dvers > hivers) hivers = dvers;
    }
  }
  /* no free entry found, we'll create a new one at the end */
  if (!found) fpos = cpos;
  /* new file version */
  vers = hivers + 1;

  time(&now);
  set_dir_entry(dirent, ino, fname, ext, vers);
  
  if (contiguous) {
    /* pre-allocate csize blocks for the file */
    blkno = alloc_blocks(csize);
    if (blkno == 0) {
      fprintf(stderr, "No contiguous space\n");
      if (dir_close_flag) {
        close_file(dirfcb);
        free(dirfcb);
      }
      return NULL;
    }
    set_inode(inode, 1, _FA_FILE | _FA_CTG, group, user,
              blkno, csize, 0, 0, 0xFFFF);
  } else {
    /* create the first alloc block for the file */
    blkno = alloc_block();
    if (blkno == 0) {
      fprintf(stderr, "No space left on device\n");
      if (dir_close_flag) {
        close_file(dirfcb);
        free(dirfcb);
      }
      return NULL;
    }
    release_block(new_block(blkno));  /* clear the first alloc block */
    set_inode(inode, 1, _FA_FILE, group, user,
              blkno, 0, 0, 0, 0xFFFF);
  }
  set_cdate(inode, now);
  set_mdate(inode, now);
  file_seek(dirfcb, fpos);
  if (file_write(dirfcb, dirent, 16) != 16) {
    /* failed to extend the directory */
    if (contiguous) {
      while (csize > 0) {
        free_block(blkno++);
        --csize;
      }
    } else {
      free_block(blkno);
    }
    fprintf(stderr, "Could not enter file, no space left on device\n");
    if (dir_close_flag) {
      close_file(dirfcb);
      free(dirfcb);
    }
    return NULL;
  }
  
  write_inode(ino, inode);

  if (dir_close_flag) {
    close_file(dirfcb);
    free(dirfcb);
  }

  newname[0] = '\0';
  if (*dname) {
    snprintf(newname, 20, "[%s]", dname);
  }
  snprintf(newname + strlen(newname), 200, "%s.%s;%d", fname, ext, vers);

  return open_file(newname);
}
#endif

#ifndef FILEIO_READ_ONLY
/* Delete file in current directory */
int delete_file(char *name) {
  unsigned char dirent[16], inode[32];
  char dname[10], fname[10], ext[10];
  short vers;
  unsigned long fpos;
  unsigned short ino, blkno, nblks, blkptr;
  struct BUFFER *buf;
  struct FCB *dirfcb;
  int retc, dir_close_flag;

  if (!parse_name(name, dname, fname, ext, &vers)) {
    printf("Invalid file name\n");
    return 0;
  }

  if (*dname) {
    char mdfile[20];
    strcpy(mdfile, dname);
    strcat(mdfile, ".DIR");
    dirfcb = open_md_file(mdfile);
    dir_close_flag = 1;
  } else {
    dirfcb = cdfcb;
    dir_close_flag = 0;
  }

  if (!dirfcb) return 0;
  
  retc = 0;
  file_seek(dirfcb, 0L);
  for (;;) {
    fpos = file_pos(dirfcb);
    if (file_read(dirfcb, dirent, 16) != 16) return 0; /* file not found */
    ino = dirent[0] | (dirent[1] << 8);
    if ((ino != 0) && match(dirent, fname, ext, vers)) {  /* TODO: do not remove dirs */
      if (read_inode(ino, inode) == 0) return 0;  /* index error */
      if ((inode[0] == 0) && (inode[1] == 0)) return 0; /* index error */
      blkno = inode[8] | (inode[9] << 8);
      if (inode[2] & _FA_CTG) {
        nblks = inode[10] | (inode[11] << 8);  // nalloc
        while (nblks > 0) {
          free_block(blkno++);
          --nblks;
        }
      } else {
        while (blkno > 0) {
          buf = get_block(blkno);
          for (blkptr = 4; blkptr < 512; blkptr += 2) {
            blkno = buf->data[blkptr] | (buf->data[blkptr+1] << 8);
            if (blkno > 0) free_block(blkno);
          }
          blkno = buf->data[2] + (buf->data[3] << 8);
          release_block(buf);
          free_block(buf->blkno);
        }
      }
      file_seek(dirfcb, fpos);
      dirent[0] = 0;
      dirent[1] = 0;
      file_write(dirfcb, dirent, 16);  /* TODO: set dirfcb mdate */
      inode[0] = 0;
      inode[1] = 0;
      write_inode(ino, inode);
      retc = 1;
      break;
    }
  }

  if (dir_close_flag) {
    close_file(dirfcb);
    free(dirfcb);
  }
  
  return retc;
}
#endif
