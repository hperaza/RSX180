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
#include <ctype.h>

#include "check.h"
#include "indexf.h"
#include "fileio.h"
#include "dirio.h"
#include "blockio.h"
#include "buffer.h"
#include "bitmap.h"
#include "misc.h"

//#define DEBUG

unsigned short nblocks = 0;  /* total disk blocks */
unsigned short bmblock = 0;  /* bitmap file starting block number */
unsigned short ixblock = 0;  /* index file starting block number */
unsigned short mdirblk = 0;  /* master directory starting block number */

struct FCB *mdfcb = NULL, *cdfcb = NULL;

FILE *imgf = NULL;

static unsigned short ixblks = 0;  /* *current* index file size in blocks */
static unsigned short inodes = 0;  /* inode capacity of index file */
static unsigned short bmsize = 0;  /* bitmap file size in bytes */
static unsigned short bmblks = 0;  /* bitmap file size in blocks */

static int errcnt;

static int read_only = 0;

/*-----------------------------------------------------------------------*/

void usage(char *p) {
  fprintf(stderr, "usage: %s [-n] filename\n", p);
}

int main(int argc, char *argv[]) {
  char *name, *mode;
  
  if (argc < 2) {
    usage(argv[0]);
    return 1;
  }

  name = argv[1];
  mode = "r+";
  if (strcmp(argv[1], "-n") == 0) {
    if (argc < 3) {
      usage(argv[0]);
      return 1;
    }
    read_only = 1;
    name = argv[2];
    mode = "r";
  }
  
  imgf = fopen(name, mode);
  if (!imgf) {
    fprintf(stderr, "%s: could not open %s\n", argv[0], argv[1]);
    return 1;
  }
  
  init_bufs();
  
  check();

//  if (cdfcb) { close_file(cdfcb); free(cdfcb); }
//  cdfcb = NULL;

  if (mdfcb) { close_file(mdfcb); free(mdfcb); }
  mdfcb = NULL;
  cdfcb = NULL;

  flush_buffers();

  if (imgf) fclose(imgf);
  imgf = NULL;
  
  return 0;
}

/*-----------------------------------------------------------------------*/

int check(void) {

  errcnt = 0;

  printf("1. Checking Volume ID\n");
  if (!check_volume_id()) return 0;

  printf("2. Checking Index File\n");
  if (!check_index_file()) return 0;

  printf("3. Checking Master Directory\n");
  if (!check_master_dir()) return 0;

  printf("4. Checking Files and Directories\n");
  if (!check_directories()) return 0;

  printf("5. Checking Allocation Bitmap\n");
  if (!check_alloc_map()) return 0;
  
  if (errcnt == 0) {
    printf("No errors were found.\n");
  } else {
    if (read_only) {
      printf("%d error%s found.\n", errcnt, (errcnt == 1) ? "" : "s");
    } else {
      printf("%d error%s fixed.\n", errcnt, (errcnt == 1) ? "" : "s");
    }
  }
  
  return 1;
}

/* Check Volume ID block */
int check_volume_id(void) {
  unsigned char buf[512], *inode;
//  char s[80];
  
  /*
   * Volume ID check:
   * 1) ensure block 0 pass P112 checksum test (if bootable)
   * 2) ensure Volume ID is valid on block 1, else abort operation
   * 3) ensure filesystem version number is valid, else abort operation
   */
  
  /* read the volume ID block */
  read_block(1, buf);

  /* set variables to be used by this and other routines */
  nblocks = buf[32] | (buf[33] << 8);
  ixblock = buf[64] | (buf[65] << 8);
  bmblock = buf[68] | (buf[69] << 8);
  mdirblk = buf[72] | (buf[73] << 8);
  
  if (strncmp((char *) buf, "VOL180", 6) != 0) {
    /* this can happen only in the following situations:
     * 1) the user may be trying to fix a non-RSX180 disk or partition
     * 2) the volume ID block got somehow overwritten
     * we can't proceed in case 1 (obviously) because there is no valid
     * disk structure and the user may lose valuable data;
     * we can't proceed in case 2 either because pointers to important
     * system files have been lost (manually recovery with a disk editor
     * still possible).
     */
    printf("*** Invalid volume signature, aborting.\n");
    return 0;
  }
  
  if ((buf[9] != FVER_H) || (buf[8] != FVER_L)) {
    /* cannot convert an older filesystem version to the current one,
       differences are too large to fix here */
    printf("*** Invalid filesystem version, aborting.\n");
    return 0;
//    fgets(s, 80, stdin);
//    if (toupper(s[0]) == 'Y') {
//      buf[8] = 4;
//    }
  }
  
  /* check nblocks */
//  if ((nblocks == 0) || (nblocks > dev_blocks) {
//  }
  
  /* check ixblock */
  if ((ixblock < 2) || (ixblock >= nblocks)) {
  }

  /* check bmblock */
  if ((bmblock < 2) || (bmblock >= nblocks)) {
  }
  
  /* check mdirblk */
  if ((mdirblk < 2) || (mdirblk >= nblocks)) {
  }
  
  /* save changes back */
  if (!read_only) write_block(1, buf);
  
  /* read the first block of the index file */
  read_block(ixblock, buf);

  /* open the master directory, so we can use later on the file I/O routines */
  /* basically, we're 'mounting' the volume at this point */
  inode = &buf[96]; /* !!! assumes MASTER.DIR has not moved! */
                    /* test for stablk == mdirblk and lnkcnt != 0 ? */
  mdfcb = calloc(1, sizeof(struct FCB));
  mdfcb->attrib = inode[2];
  strncpy(mdfcb->fname, "MASTER   ", 9);
  strncpy(mdfcb->ext, "DIR", 3);
  mdfcb->user = inode[6];
  mdfcb->group = inode[7];
  mdfcb->inode = 4;
  mdfcb->lnkcnt = inode[0] | (inode[1] << 8);
  mdfcb->seqno = inode[4] | (inode[5] << 8);
  mdfcb->nalloc = inode[10] | (inode[11] << 8);
  mdfcb->nused = inode[12] | (inode[13] << 8);
  mdfcb->lbcount = inode[14] | (inode[15] << 8);
  mdfcb->stablk = inode[8] | (inode[9] << 8);
  mdfcb->curblk = 0;
  mdfcb->blkptr = 4;  /* !!! assumes MASTER.DIR is not contiguous! */
  mdfcb->byteptr = 0;
  mdfcb->allocbuf = get_block(mdfcb->stablk);
  mdfcb->filbuf = NULL;
  cdfcb = mdfcb;

  //cdfcb = open_md_file("MASTER.DIR");
  
  return 1;
}

/* Check index file */
int check_index_file(void) {
  unsigned char inode[32], attrib;
  unsigned short lcnt, blkno, nalloc, nused, lbcnt, i;
//  char s[80];
  
  /*
   * Index file check:
   * 1) check reserved inodes for valid data (block number values, etc.)
   * 2) check all other inodes for valid data:
   *    - check contiguous files for valid block numbers and ranges (i.e.
   *      ensure they fall within disk limits.)
   *    - for non-contiguous files check allocation maps, etc.
   *    - .DIR files in [MASTER] should have the 'dir' attrib set.
   * [Move to file and directory check:]
   * 3a) build an array with link count of all inode entries in index file.
   * 3b) scan all directories and compare inode number of every valid (used)
   *     dir entry with array built in 3a). If value > 1, --value. If value
   *     == 0, report the filename on dir entry and mark the directory entry
   *     as deleted.
   * 3c) check the array for any remaining values > 0. For each one, create
   *     an entry in [MASTER]LOSTFOUND.DIR. If value > 1, force value = 1.
   */

  if (!read_inode(1, inode)) {  /* INDEXF.SYS */
    printf("*** Could not read inode 1, aborting.\n");
    return 0;
  }
  lcnt   = inode[0]  | (inode[1]  << 8);
  attrib = inode[2];
  blkno  = inode[8]  | (inode[9]  << 8);
  nalloc = inode[10] | (inode[11] << 8);
  nused  = inode[12] | (inode[13] << 8);
  lbcnt  = inode[14] | (inode[15] << 8);
  if (lcnt == 0) {
    printf("*** INDEXF.SYS has a link count of 0, fixing.\n");
    inode[0] = 1;
    inode[1] = 0;
    ++errcnt;
  }
  if (blkno != ixblock) {
    /* which one to use? */
  }
  if (nalloc != nused) {
  }
  ixblks = nused;

  if (!read_inode(2, inode)) {  /* BITMAP.SYS */
    printf("*** Could not read inode 2, aborting.\n");
    return 0;
  }
  lcnt   = inode[0]  | (inode[1]  << 8);
  attrib = inode[2];
  blkno  = inode[8]  | (inode[9]  << 8);
  nalloc = inode[10] | (inode[11] << 8);
  nused  = inode[12] | (inode[13] << 8);
  lbcnt  = inode[14] | (inode[15] << 8);
  if (lcnt == 0) {
    printf("*** BITMAP.SYS has a link count of 0, fixing.\n");
    inode[0] = 1;
    inode[1] = 0;
    ++errcnt;
  }
  if (blkno != bmblock) {
    /* which one to use? */
  }
  /* compute nused from disk size and compare with stored value */
  bmsize = (nblocks + 7) / 8 + BMHDRSZ;
  bmblks = (bmsize + 511) / 512;
  if (nalloc != bmblks) {
    printf("*** Wrong bitmap file size, fixing.\n");
    inode[10] = bmblks & 0xFF;
    inode[11] = (bmblks >> 8) & 0xFF;
    ++errcnt;
  }
  /* TODO: check also lbcnt! */
  if (nused != nalloc) {
    inode[12] = inode[10];
    inode[13] = inode[11];
  }
  if (!read_only) {
    if (!write_inode(2, inode)) {
      printf("*** Could not write inode 2, aborting.\n");
      return 0;
    }
  }

  if (!read_inode(3, inode)) {  /* BOOT.SYS */
    printf("*** Could not read inode 3, aborting.\n");
    return 0;
  }
  lcnt   = inode[0]  | (inode[1]  << 8);
  attrib = inode[2];
  blkno  = inode[8]  | (inode[9]  << 8);
  nalloc = inode[10] | (inode[11] << 8);
  nused  = inode[12] | (inode[13] << 8);
  lbcnt  = inode[14] | (inode[15] << 8);
  if (lcnt == 0) {
    printf("*** BOOT.SYS has a link count of 0, fixing.\n");
    inode[0] = 1;
    inode[1] = 0;
    ++errcnt;
  }
  if (blkno != 0) {
    inode[8] = 0;
    inode[9] = 0;
  }
  if (nalloc != 2) {
    printf("*** BOOT.SYS allocated block count is wrong, fixing.\n");
    inode[10] = 2;
    inode[11] = 0;
    ++errcnt;
  }
  if (nused != nalloc) {
    printf("*** BOOT.SYS used block count is wrong, fixing.\n");
    inode[12] = inode[10];
    inode[13] = inode[11];
    ++errcnt;
  }
  if (!read_only) {
    if (!write_inode(3, inode)) {
      printf("*** Could not write inode 3, aborting.\n");
      return 0;
    }
  }

  if (!read_inode(4, inode)) {  /* MASTER.DIR */
    printf("*** Could not read inode 4, aborting.\n");
    return 0;
  }
  lcnt  = inode[0] | (inode[1] << 8);
  blkno = inode[8] | (inode[9] << 8);
  if (lcnt == 0) {
    printf("*** MASTER.DIR has a link count of 0, fixing.\n");
    inode[0] = 1;
    inode[1] = 0;
    ++errcnt;
  }
  if (blkno != mdirblk) {
    /* which one to use? */
  }
  
  inodes = ixblks * 16;  /* there are 16 inodes in a block */
  
  for (i = 0; i < inodes; ++i) {
    if (!read_inode(i+1, inode)) {
      printf("*** Could not read inode %d, aborting.\n", i+1);
      return 0;
    }
    lcnt   = inode[0]  | (inode[1]  << 8);
    attrib = inode[2];
    blkno  = inode[8]  | (inode[9]  << 8);
    nalloc = inode[10] | (inode[11] << 8);
    nused  = inode[12] | (inode[13] << 8);
    lbcnt  = inode[14] | (inode[15] << 8);
    if (lcnt > 0) {
      if (attrib & _FA_CTG) {
        /* contiguous file */
        if (blkno >= nblocks) {
          printf("*** Inode %d: invalid starting block number of contiguous file, deleting.\n", i+1);
          /* invalid starting block number, delete the file */
          lcnt = 0;
          ++errcnt;
        } else {
          if (blkno + nalloc >= nblocks) {
            /* truncate the file */
            nalloc = nblocks - blkno - 1;
            if (nalloc == 0) {
              /* delete the file if nalloc became 0 */
              lcnt = 0;
              printf("*** Inode %d: contiguous file outside of volume limits, truncating.\n", i+1);
            } else {
              printf("*** Inode %d: contiguous file extends beyond end of volume, truncating.\n", i+1);
            }
            ++errcnt;
          }
          if (nused > nalloc) {
            printf("*** Inode %d: wrong block count of contiguous file, fixing.\n", i+1);
            nused = nalloc;
            ++errcnt;
          }
        }
      } else {
        /* non-contiguous file */
        if (blkno == 0) {
          if (nalloc > 0) {
            /* nalloc must be zero if blkno is zero */
            /* delete the file */
            printf("*** Inode %d: null allocation block on non-empty file, deleting.\n", i+1);
            lcnt = 0;
            ++errcnt;
          }
        } else if ((blkno < 2) || (blkno >= nblocks)) {
          /* invalid starting allocation block number, delete the file; */
          /* any lost blocks will be recovered in phase 5 */
          printf("*** Inode %d: invalid allocation block number, deleting.\n", i+1);
          lcnt = 0;
          ++errcnt;
        }
      }
      if (lbcnt > 512) {
        printf("*** Inode %d: last block byte count larger than block size, truncating.\n", i+1);
        lbcnt = 512;
        ++errcnt;
      }
      inode[0] = lcnt & 0xFF;
      inode[1] = (lcnt >> 8) & 0xFF;
      inode[8] = blkno & 0xFF;
      inode[9] = (blkno >> 8) & 0xFF;
      inode[10] = nalloc & 0xFF;
      inode[11] = (nalloc >> 8) & 0xFF;
      inode[12] = nused & 0xFF;
      inode[13] = (nused >> 8) & 0xFF;
      inode[14] = lbcnt & 0xFF;
      inode[15] = (lbcnt >> 8) & 0xFF;
      if (!read_only) {
        if (!write_inode(i+1, inode)) {
          printf("*** Could not write inode %d, aborting.\n", i+1);
          return 0;
        }
      }
    }
  }
  
  return 1;
}

/* Check master directory */
int check_master_dir(void) {
  int vifound = 0, ixfound = 0, bmfound = 0, mdfound = 0;
  unsigned char dirent[16];
  unsigned short ino;
  unsigned long fpos;

  /*
   * Master directory check:
   * 1) ensure the boot, index, bitmap and master directory file exist.
   * 2) check the boot and label/home block, ensure location is correct
   *    in the special master directory files, and ensure that the location
   *    of the special files is correct in the home block.
   */

  /* ensure boot, index, bitmap and master dir files exist */
  file_seek(mdfcb, 0L);
  for (;;) {
    fpos = file_pos(mdfcb);
    if (file_read(mdfcb, dirent, 16) != 16) break; /* EOF */
    ino = dirent[0] | (dirent[1] << 8);
    switch (ino) {
      case 1:
        ixfound = 1;
        break;
      
      case 2:
        bmfound = 1;
        break;
        
      case 3:
        vifound = 1;
        break;
        
      case 4:
        mdfound = 1;
        if (!match(dirent, "MASTER.DIR")) {
          printf("*** MASTER.DIR entry has wrong name, restoring.\n");
          file_seek(mdfcb, fpos);
          set_dir_entry(dirent, 1, "INDEXF", "SYS", 1);
          if (!read_only) {
            if (file_write(mdfcb, dirent, 16) != 16) {
              printf("*** Could not enter file into Master Directory, aborting.\n");
              return 0;
            }
          }
          ++errcnt;
        }
        break;
    }
  }

  file_seek(mdfcb, fpos);
  if (!ixfound) {
    printf("*** INDEXF.SYS entry not found in Master Directory, restoring.\n");
    set_dir_entry(dirent, 1, "INDEXF", "SYS", 1);
    if (!read_only) {
      if (file_write(mdfcb, dirent, 16) != 16) {
        printf("*** Could not enter file into Master Directory, aborting.\n");
        return 0;
      }
    }
    ++errcnt;
  }
  if (!bmfound) {
    printf("*** BITMAP.SYS entry not found in Master Directory, restoring.\n");
    set_dir_entry(dirent, 2, "BITMAP", "SYS", 1);
    if (!read_only) {
      if (file_write(mdfcb, dirent, 16) != 16) {
        printf("*** Could not enter file into Master Directory, aborting.\n");
        return 0;
      }
    }
    ++errcnt;
  }
  if (!vifound) {
    printf("*** BOOT.SYS entry not found in Master Directory, restoring.\n");
    set_dir_entry(dirent, 3, "BOOT", "SYS", 1);
    if (!read_only) {
      if (file_write(mdfcb, dirent, 16) != 16) {
        printf("*** Could not enter file into Master Directory, aborting.\n");
        return 0;
      }
    }
    ++errcnt;
  }
  if (!mdfound) {
    printf("*** MASTER.DIR entry not found in Master Directory, restoring.\n");
    set_dir_entry(dirent, 4, "MASTER", "DIR", 1);
    if (!read_only) {
      if (file_write(mdfcb, dirent, 16) != 16) {
        printf("*** Could not enter file into Master Directory, aborting.\n");
        return 0;
      }
    }
    ++errcnt;
  }
  
  /* ensure bitmap and master dir block info in directory matches values
     in volume ID block */
  
  return 1;
}

static char *file_name(unsigned char *dirent) {
  static char str[20];
  int i;
  unsigned short vers;
  char *p;
  
  p = str;
  for (i = 0; i < 9; ++i) if (dirent[2+i] != ' ') *p++ = dirent[2+i];
  *p++ = '.';
  for (i = 0; i < 3; ++i) if (dirent[11+i] != ' ') *p++ = dirent[11+i];
  *p++ = ';';
  vers = dirent[14] | (dirent[15] << 8);
  snprintf(p, 3, "%d", vers);

  return str;
}

static unsigned char valid_char(unsigned char c) {
  static char *invalid = "%?*:;.,()<>[]{}/\\|";
  c = toupper(c);
  if (strchr(invalid, c)) c = '_';
  return c;
}

static int valid_name(unsigned char *dirent) {
  int i, space, valid;
  unsigned char c;
  
  valid = 1;
  space = -1;
  for (i = 0; i < 9; ++i) {
    c = dirent[2+i];
    if (c == ' ') {
      if (space < 0) space = i;
      continue;
    } else {
      if (space >= 0) {
        /* found invalid embedded space */
        i = space;  /* restart from there */
        space = -1;
        dirent[2+i] = '_';
        valid = 0;
      } else {
        /* check for valid char */
        c = valid_char(c);
        if (c != dirent[2+i]) {
          dirent[2+i] = c;
          valid = 0;
        }
      }
    }
  }
  if (space == 0) {
    dirent[2] = '_';
    valid = 0;
  }
    
  space = -1;
  for (i = 0; i < 3; ++i) {
    c = dirent[11+i];
    if (c == ' ') {
      if (space < 0) space = i;
      continue;
    } else {
      if (space >= 0) {
        /* found invalid embedded space */
        i = space;  /* restart from there */
        space = -1;
        dirent[11+i] = '_';
        valid = 0;
      } else {
        /* check for valid char */
        c = valid_char(c);
        if (c != dirent[11+i]) {
          dirent[11+i] = c;
          valid = 0;
        }
      }
    }
  }
  if (space == 0) {
    dirent[11] = '_';
    valid = 0;
  }
  
  if (!valid) {
    printf("*** Invalid filename in directory entry, changed to %s\n", file_name(dirent));
    ++errcnt;
  }

  return valid;
}

/* Check a single directory */
static int check_directory(char *filename, unsigned short *ixmap) {
  unsigned char dirent[16], inode[32], attrib;
  struct FCB *fcb;
  unsigned short ino, lcnt;
  unsigned long fpos;
  int save;
  
  fcb = open_file(filename);
  if (!fcb) {
    printf("*** Could not open %s directory, aborting.\n", filename);
    return 0;
  }

  /* check filenames for valid characters, illegal embedded spaces,
     duplicate version numbers, etc. */
  file_seek(fcb, 0L);
  for (;;) {
    fpos = file_pos(fcb);
    if (file_read(fcb, dirent, 16) != 16) break; /* EOF */
    ino = dirent[0] | (dirent[1] << 8);
    if (ino == 0) continue; /* deleted entry */
    save = 0;
    if (ino >= inodes) {
      printf("*** %s on %s has invalid inode number, deleting.\n",
             file_name(dirent), filename);
      dirent[0] = 0;
      dirent[1] = 0;
      save = 1;
      ++errcnt;
    } else {
      if (!read_inode(ino, inode)) {
        printf("*** Could not read inode %d, aborting.\n", ino);
        return 0;
      }
      lcnt = inode[0] | (inode[1] << 8);
      if (lcnt == 0) {
        /* TODO: check that inode blocks are released in bitmap; if not,
           recover the file? */
        printf("*** File %s has a link count of zero, deleting.\n", file_name(dirent));
        dirent[0] = 0;
        dirent[1] = 0;
        save = 1;
        ++errcnt;
      } else {
        ++ixmap[ino-1];
        attrib = inode[2];
        if (attrib & _FA_DIR) {
          /* nested dirs allowed by the specs, but not supported by the
             standard SYSFCP */
        }
        save |= !valid_name(dirent);
      }
    }
    if (save && !read_only) {
      file_seek(fcb, fpos);
      if (file_write(fcb, dirent, 16) != 16) {
        printf("*** Could not update entry in Master Directory, aborting.\n");
        return 0;
      }
    }
  }
     
  return 1;
}
  
/* Scan the Master Directory and check all directories */
int check_directories(void) {
  unsigned char dirent[16], inode[32], attrib;
  unsigned short i, ino, lcnt, *ixmap;
  unsigned long fpos;
  int save;
  
  ixmap = calloc(inodes, sizeof(unsigned short));
  if (!ixmap) {
    printf("*** Not enough memory, aborting.\n");
    return 0;
  }
  
  /* open each directory and check filenames for valid characters,
     illegal embedded spaces, duplicate version numbers, etc. */
  file_seek(mdfcb, 0L);
  for (;;) {
    fpos = file_pos(mdfcb);
    if (file_read(mdfcb, dirent, 16) != 16) break; /* EOF */
    ino = dirent[0] | (dirent[1] << 8);
    if (ino == 0) continue; /* deleted entry */
    save = 0;
    if (ino >= inodes) {
      printf("*** %s on Master Directory has invalid inode number, deleting.\n",
             file_name(dirent));
      dirent[0] = 0;
      dirent[1] = 0;
      ++errcnt;
    } else {
      if (!read_inode(ino, inode)) {
        printf("*** Could not read inode %d, aborting.\n", ino);
        free(ixmap);
        return 0;
      }
      lcnt = inode[0] | (inode[1] << 8);
      if (lcnt == 0) {
        printf("*** File %s has a link count of zero, deleting.\n", file_name(dirent));
        dirent[0] = 0;
        dirent[1] = 0;
        save = 1;
        ++errcnt;
      } else {
        // ++ixmap[ino-1]; -- don't do this here, since the master directory
        //                    will be checked again in check_directory()
        attrib = inode[2];
        if (attrib & _FA_DIR) {
          char temp[20];
        
          strcpy(temp, file_name(dirent));
          if (!check_directory(temp, ixmap)) {
            free(ixmap);
            return 0;
          }
        }
        save |= valid_name(dirent);
      }
    }
    if (save && !read_only) {
      file_seek(mdfcb, fpos);
      if (file_write(mdfcb, dirent, 16) != 16) {
        printf("*** Could not update entry in Master Directory, aborting.\n");
        free(ixmap);
        return 0;
      }
    } else {
      /* need this since md file position can change in check_directory() */
      file_seek(mdfcb, fpos+16L);
    }
  }
  
  /* check for lost files */
  for (i = 0; i < inodes; ++i) {
    if (!read_inode(i+1, inode)) {
      printf("*** Could not read inode %d, aborting.\n", i+1);
      free(ixmap);
      return 0;
    }
    save = 0;
    lcnt = inode[0] | (inode[1] << 8);
    if (lcnt != ixmap[i]) {
      printf("*** Inode %d has a link count of %d (%d expected)\n",
             i+1, lcnt, ixmap[i]);
      if (lcnt < ixmap[i]) {
        /* there are more references to the file than what the inode
         * says, thus set inode's link count to ixmap[i].
         */
        lcnt = ixmap[i];
        inode[0] = lcnt & 0xff;
        inode[1] = (lcnt >> 8) & 0xff;
        save = 1;
      } else {  /* lcnt > ixmap[i] */
        if (ixmap[i] != 0) {
          /* there is at least one directory entry out there that references
           * the file; thus update inode's link count as above.
           */
          lcnt = ixmap[i];
          inode[0] = lcnt & 0xff;
          inode[1] = (lcnt >> 8) & 0xff;
          save = 1;
        } else {  /* ixmap[i] == 0 */
          /* no file is referencing the inode and we must either recover
           * the file (preferably, since lcnt > 0), or set the count to
           * zero (safest).
           * - to recover the file, a new entry needs to be created in
           *   [lostfiles] and assigned to that inode; then, the blocks
           *   assigned to the file must be validated - if they are free
           *   then the file was deleted and the inode count set to zero,
           *   if they are not, then if the file is non-contiguous the
           *   allocation block(s) must be validated, which is not easy
           *   as they do not have a magic number or any safe to do the
           *   validation - the only way is to ensure that 1) the block
           *   numbers are within disk limits, and 2) that the bitmap bit
           *   is set for the block and no other file is using that block.
           * - In principle, one could set lcount to zero and then let
           *   the bitmap check routine to create new (contiguous) files
           *   in [lostfiles] containing chunks of allocated, but not
           *   referenced, blocks (and maybe a block map report?). There
           *   some allocation blocks may appear, and further recovery
           *   could be done by copying + concatenating + deleting
           *   lost file contents.
           * - Another possibility would be to dump the block contents
           *   and let the user decide?
           */
          /* TODO */
        }
      }
      ++errcnt;
      if (save && !read_only) {
        if (!write_inode(i+1, inode)) {
          printf("*** Could not write inode %d, aborting.\n", i+1);
          free(ixmap);
          return 0;
        }
      }
    }
  }
  
  free(ixmap);
     
  return 1;
}

int check_alloc_map(void) {
  unsigned char inode[32], *bm;
  unsigned short i, j, k, l, lcnt, mask;

  /*
   * Block allocation check:
   * 1) loop through each file (inode) and create an allocation bitmap from
   *    scratch:
   *    a) when allocating a block in the new bitmap for a file, if the bit
   *       is set that means the block is already allocated and so the file
   *       is cross-linked to another (it won't be simple to figure out to
   *       which one - rescan will have to be restarted).
   * 2) compare the new bitmap to the one saved on disk:
   *    a) if there are less blocks allocated on the disk bitmap, report it
   *       (it won't be easy to find out affected files unless in step 1
   *       above each file is compared to the old bitmap as well).
   *    b) if there are more blocks in the old bitmap, report it and create
   *       a (possibly contiguous?) file to claim the orphaned blocks. When
   *       creating the new file, use the new bitmap for allocation of file
   *       allocation map blocks (in case the file could not be contiguous).
   * 3) save the new bitmap to the disk, overwriting the old one.
   */

#ifdef DEBUG
  printf("%d inodes in %d blocks\n", inodes, ixblks);
#endif
  
  bm = calloc(bmsize, sizeof(unsigned char)); /* initialized to zero */
  if (!bm) {
    printf("*** Not enough memory, aborting.\n");
    return 0;
  }
  
  for (i = 0; i < inodes; ++i) {
    if (!read_inode(i+1, inode)) {
      printf("*** Could not read inode %d, aborting.\n", i+1);
      free(bm);
      return 0;
    }
    lcnt = inode[0] | (inode[1] << 8);
    if (lcnt > 0) {  /* inode in use */
      unsigned short blkno, nalloc;
      unsigned char attrib;
      
      attrib = inode[2];
      blkno  = inode[8]  | (inode[9]  << 8);
      nalloc = inode[10] | (inode[11] << 8);
#ifdef DEBUG
      printf("processing inode %04X: %d block(s) allocated\n", i+1, nalloc);
#endif
      if (attrib & _FA_CTG) {
        /* contiguous file: simply mark 'nalloc' bits starting from 'blkno' */
        mask = (0x80 >> (blkno & 7));
        k = blkno / 8;
        // if (k >= bmsize) ...
        for (j = 0; j < nalloc; ++j) {
          if (bm[k] & mask) {
            printf("*** Multiple allocation of block %d, inode %d.\n", blkno+j, i+i);
            ++errcnt;
          } else {
#ifdef DEBUG
            printf("set block %04X, offset %04X bit mask %02X\n", blkno+j, k, mask);
#endif
            bm[k] |= mask;
          }
          mask >>= 1;
          if (mask == 0) {
            mask = 0x80;
            ++k;
            // if (k >= bmsize) ...
          }
        }
      } else {
        /* non-contiguous file: walk the chain of allocated blocks */
        unsigned short next;
        struct BUFFER *buf = NULL;
        int blkptr;

        if (blkno > 0) {  /* allocation block allocated */
          buf = get_block(blkno);
          if (!buf) {
            printf("*** Could not read block %d, aborting.\n", next);
            free(bm);
            return 0;
          }
          /* mark the allocation block in the bitmap */
          mask = (0x80 >> (blkno & 7));
          k = blkno / 8;
          // if (k >= bmsize) ...
          if (bm[k] & mask) {
            printf("*** Multiple allocation of block %d, inode %d.\n", blkno, i+i);
            ++errcnt;
          } else {
#ifdef DEBUG
            printf("set block %04X, offset %04X bit mask %02X (alloc blk)\n", blkno, k, mask);
#endif
            bm[k] |= mask;
          }
          next = buf->data[2] | (buf->data[3] << 8);
          blkptr = 4;
        } else {
          next = 0;
          blkptr = 512;
          buf = NULL;
        }
        
        for (j = 0; j < nalloc; ++j) {
          if (blkptr > 510) {
            if (next == 0) {
              /* this should have been fixed during index file check:
                 stblk = 0 when nalloc != 0 and file is not contiguous -
                 the inode should be marked as deleted - then in the
                 directory check pass the file will be reported and
                 deleted as well */
              printf("*** Null allocation block number, aborting.\n");
              if (buf) release_block(buf);
              free(bm);
              return 0;
            }
            if (buf) release_block(buf);
            buf = get_block(next);
            if (!buf) {
              printf("*** Could not read block %d, aborting.\n", next);
              free(bm);
              return 0;
            }
            /* mark the allocation block in the bitmap */
            mask = (0x80 >> (next & 7));
            k = next / 8;
            // if (k >= bmsize) ...
            if (bm[k] & mask) {
              printf("*** Multiple allocation of block %d, inode %d.\n", next, i+i);
              ++errcnt;
            } else {
#ifdef DEBUG
              printf("set block %04X, offset %04X bit mask %02X (alloc blk)\n", blkno, k, mask);
#endif
              bm[k] |= mask;
            }
            next = buf->data[2] | (buf->data[3] << 8);
            blkptr = 4;
          }
          blkno = buf->data[blkptr] | (buf->data[blkptr+1] << 8);
          blkptr += 2;
          /* mark 'blkno' in bitmap */
          mask = (0x80 >> (blkno & 7));
          k = blkno / 8;
          // if (k >= bmsize) ...
          if (bm[k] & mask) {
            printf("*** Multiple allocation of block %d, inode %d.\n", blkno, i+i);
            ++errcnt;
          } else {
#ifdef DEBUG
            printf("set block %04X, offset %04X bit mask %02X\n", blkno, k, mask);
#endif
            bm[k] |= mask;
          }
        }
        
        if (buf) release_block(buf);
      }
    }
  }
  
  /* compare bitmaps */
  k = 0;
  j = BMHDRSZ;
  for (i = 0; i < bmblks; ++i) {
    struct BUFFER *buf;

    buf = get_block(bmblock + i);
    if (!buf) {
      printf("*** Could not read block %d, aborting.\n", bmblock + i);
      free(bm);
      return 0;
    }
    if (i == 0) {
      int bmsz = buf->data[0] | (buf->data[1] << 8);
      if (bmsz != nblocks) {
        printf("*** Block count in bitmap header wrong, fixing.\n");
        buf->data[0] = nblocks & 0xFF;
        buf->data[1] = (nblocks >> 8) & 0xFF;
        buf->modified = 1;
      }
    }
    for ( ; j < 512; ++j) {
      if (k >= bmsize) break;
      if (bm[k] != buf->data[j]) {
        for (l = 0, mask = 0x80; l < 8; ++l, mask >>= 1) {
          int blkno = k * 8 + l;
          if ((bm[k] & mask) != (buf->data[j] & mask)) {
            if (bm[k] & mask) {
              printf("*** Allocated block %d appears free in bitmap.\n", blkno);
              /* TODO: which file? if we do the comparison in the loop above
               * then we could at least report the affected inode number */
              /* When scanning dirs we could also build a reverse lookup table
                 inode->file name (or inode->file direntry [dirblk+ofs]) */
              /* For large devices, may require creating a vm array on another
                 (scratch) disk */
            } else {
              printf("*** Free block %d appears allocated in bitmap.\n", blkno);
              /* See note in the check_directories() routine. The blocks might
                 originate from an orphaned inode, in which case they should
                 be assigned to a new file. Assignment should be done only
                 *after* all unset bits are set (maybe we should split this
                 loop in two?) in order to avoid damaging a block that is
                 allocated to a file */
            }
            ++errcnt;
          }
        }
        buf->data[j] = bm[k];
        buf->modified = 1;
      }
      ++k;
    }
    release_block(buf);
    j = 0;
  }
  
  free(bm);

  return 1;
}

/*-----------------------------------------------------------------------*/

/* Since the volume is not mounted, we can't use the read/write file
   routines directly, so we do our own I/O here.
   
   What we need:
   1) Read directory entries.
   2) Read file allocation blocks.
*/

/* Scan through all directories and read all directory entries.
   We start from MASTER.DIR, which has a known inode number.
   For every directory, we call the routine recursively.
*/

/* Fixing cross-linked files: the inode numbers should be saved during
   the bitmap check pass. In the final pass, bad inodes should be examined
   again:
   * if non-contiguous file, replace the cross-linked block in the
     file allocation map with a newly allocated block, copying the
     contents from the cross-linked block.
     If the cross-linked block is an allocation block, the file should
     be deleted and all non-cross-linked blocks freed.
   * if contiguous file, allocate a new chain of contiguous blocks of
     the same size as the original file and copy the contents from
     cross-linked blocks, then free all blocks that are not cross-linked.
     If not enough contiguous space, delete the file and free all non-
     cross-linked blocks.
   After this, the bitmap allocation check should be run again.
   
   [Wouldn't be better to copy the whole file in each case to a new one
   and delete the old one? After that, the bitmap check pass should be
   run again to re-allocate the cross-linked blocks.]
   
   Another possible way:
    - 1st pass of bitmap check walks through all files and forces all
      allocated bits to one (any zero bits should be reported). After
      this pass we can use the bitmap to allocate new blocks to replace
      multiple-allocated ones, etc.
    - 2nd pass starting from a blank bitmap to discover multiple-allocated
      blocks. Every time a such one is found, a fresh block should be
      allocated from the bitmap rebuilt in pass 1 and contents from old
      block copied (if contiguous file, a whole new file will have to
      be reallocated). Note that old blocks (or block chains in case of
      contiguous files) are not removed from the bitmap.
    - 3rd pass starting again from a blank bitmap. This time no multiple-
      allocated blocks should be discovered, but this pass will serve to
      locate free blocks that are still set on the bitmap, either from
      original errors, or as result of pass 2. These blocks do not have to
      be reported - perhaps only how much space was (or how many blocks
      were) freed (if > 0) or recovered (if < 0) relative to the original
      bitmap size.

   Anything else? e.g. timestamps, permissions, user/group numbers?

*/
