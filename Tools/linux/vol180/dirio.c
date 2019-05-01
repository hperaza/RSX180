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

#include "fileio.h"
#include "buffer.h"
#include "bitmap.h"
#include "indexf.h"
#include "dirio.h"

extern struct FCB *mdfcb, *cdfcb;

/*-----------------------------------------------------------------------*/

void set_dir_entry(unsigned char *entry, unsigned short inode,
                   char *fname, char *ext, unsigned short vers) {
  int i;

  entry[0] = inode & 0xFF;
  entry[1] = (inode >> 8) & 0xFF;
  for (i = 0; i < 9; ++i) entry[i+2] = *fname ? *fname++ : ' ';
  for (i = 0; i < 3; ++i) entry[i+11] = *ext   ? *ext++   : ' ';
  entry[14] = vers & 0xFF;
  entry[15] = (vers >> 8) & 0xFF;
}

int match(unsigned char *dirent, char *fname) {
  int  i;
  char *p;
  unsigned short vers;
  
  p = fname;
  for (i = 0; i < 9; ++i) {
    if (!*p || (*p == '.')) {
      if (dirent[i+2] == ' ') break;
    }
    if (dirent[i+2] != *p++) return 0;
  }
  
  while (*p && *p != '.') ++p;
  if (*p == '.') ++p;

  for (i = 0; i < 3; ++i) {
    if (!*p || (*p == ';')) {
      if (dirent[i+11] == ' ') break;
    }
    if (dirent[i+11] != *p++) return 0;
  }
  
  while (*p && *p != ';') ++p;
  if (*p == ';') ++p;
  if (*p) {
    vers = atoi(p);
    return ((dirent[14] | (dirent[15] << 8)) == vers);
  }

  return 1;
}

int match_fcb(unsigned char *dirent, struct FCB *fcb) {
  int i;
  
  for (i = 0; i < 9; ++i) {
    if (dirent[i+2] != fcb->fname[i]) return 0;
  }
  for (i = 0; i < 3; ++i) {
    if (dirent[i+11] != fcb->ext[i]) return 0;
  }
  if ((dirent[14] | (dirent[15] << 8)) != fcb->vers) return 0;

  return 1;
}

int create_dir(char *filename, char group, char user) {
  unsigned char dirent[16];
  unsigned char inode[32];
  unsigned blkno;
  char fname[13], *ext, *pvers;
  unsigned short ino, vers;
  unsigned long fpos;
  time_t now;

  if (!mdfcb) return 0;

  strncpy(fname, filename, 13);
  fname[13] = '\0';
  
  ext = strchr(fname, '.');
  if (ext) {
    *ext++ = '\0';
  } else {
    ext = "DIR";
  }

  pvers = strchr(ext ? ext : fname, ';');
  if (pvers) {
    *pvers++ = '\0';
  }
  vers = 1;  /* TODO: do not allow duplicate or new version of dirs */

  /* find a free inode */
  ino = new_inode();
  if (ino == 0) {
    fprintf(stderr, "Index file full\n");
    return 0;
  }

  /* find a free directory entry */
  file_seek(mdfcb, 0L);
  for (;;) {
    fpos = file_pos(mdfcb);
    if (file_read(mdfcb, dirent, 16) == 16) {
      if ((dirent[0] == 0) && (dirent[1] == 0)) break;  /* free dir entry */
    } else {
      break; /* at the end of directory */
    }
  }

  /* create the first alloc block for the new directory */
  blkno = alloc_block();
  if (blkno == 0) {
    fprintf(stderr, "No more space\n");
    return 0;
  }
  
  time(&now);
  
  release_block(new_block(blkno));
  set_inode(inode, 1, _FA_DIR, group, user, blkno, 0, 0, 0, 0xFFF8);
  set_cdate(inode, now);
  set_mdate(inode, now);
  write_inode(ino, inode);
  set_dir_entry(dirent, ino, fname, ext, vers);
  file_seek(mdfcb, fpos);
  file_write(mdfcb, dirent, 16);

  return 1;
}

int change_dir(char *filename) {
  struct FCB *fcb;

  fcb = open_md_file(filename);
  if (!fcb) return 0;

  if (!(fcb->attrib & _FA_DIR)) {
    /* not a directory */
    free(fcb);
    return 0;
  }

  if (cdfcb) {
    close_file(cdfcb);
    free(cdfcb);
  }
  cdfcb = fcb;
  
  return 1;
}
