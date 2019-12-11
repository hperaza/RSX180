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
#include "dirio.h"
#include "indexf.h"
#include "mkdisk.h"
#include "bitmap.h"
#include "misc.h"


/*-----------------------------------------------------------------------*/

int create_disk(char *fname, unsigned nblocks, unsigned nfiles) {
  FILE *f;
  unsigned bmsize, bmblocks, ixblocks, blkcnt;
  unsigned ixstblk, bmstblk, mdstblk, dfprot;
  unsigned char block[512], mask, bmask;
  int i, j;
  time_t now;
  
  if (nblocks < 32) {
    fprintf(stderr, "too few blocks for disk image \"%s\": %d\n",
                    fname, nblocks);
    return 1;
  }

  if (nblocks > 65536) {
    fprintf(stderr, "too many blocks for disk image \"%s\": %d\n",
                    fname, nblocks);
    return 1;
  }
  
  if (nfiles < 32) {
    fprintf(stderr, "too few files for disk image \"%s\": %d\n",
                    fname, nfiles);
    return 1;
  }

  if (nfiles > nblocks / 2) {
    fprintf(stderr, "too many files for disk image \"%s\": %d\n",
                    fname, nfiles);
    return 1;
  }

  f = fopen(fname, "w");
  if (!f) {
    fprintf(stderr, "could not create disk image \"%s\": %s\n",
                    fname, strerror(errno));
    return 1;
  }
  
  dfprot = 0xffff;
  
  bmsize = (nblocks + 7) / 8 + BMHDRSZ;
  bmblocks = (bmsize + 511) / 512;

  ixblocks = (nfiles + 15) / 16;
  
  ixstblk = 2;
  bmstblk = ixstblk + ixblocks;
  mdstblk = bmstblk + bmblocks;

  blkcnt = nblocks;
  
  time(&now);

  /* write boot block */
  memset(block, 0, 512);
  fwrite(block, 1, 512, f); /* block 0 */
  --blkcnt;
  
  /* write volume id */
  memcpy(block, "VOL180", 6);
  block[8] = FVER_L;             /* filesystem version */
  block[9] = FVER_H;
  strcpy((char *) &block[16], "RSX180 DISK");  /* volume label */
  block[32] = nblocks & 0xFF;    /* disk size */
  block[33] = (nblocks >> 8) & 0xFF;
  block[36] = dfprot & 0xFF;     /* default file protection */
  block[37] = (dfprot >> 8) & 0xFF;
  set_date(&block[40], now);     /* created timestamp */
  block[64] = ixstblk & 0xFF;    /* starting index file block */
  block[65] = (ixstblk >> 8) & 0xFF;
  block[68] = bmstblk & 0xFF;    /* starting bitmap block */
  block[69] = (bmstblk >> 8) & 0xFF;
  block[72] = mdstblk & 0xFF;    /* starting master directory block */
  block[73] = (mdstblk >> 8) & 0xFF;
  block[76] = 0;                 /* starting system image block, none yet */
  block[77] = 0;
  fwrite(block, 1, 512, f); /* block 1 */
  --blkcnt;

  /* write the index file */
  memset(block, 0, 512);
  set_inode(&block[0],  1, _FA_FILE | _FA_CTG,     /* INDEXF.SYS */
            1, 1, ixstblk, ixblocks, ixblocks, 512, 0xCCC8);
  set_cdate(&block[0], now);
  set_mdate(&block[0], now);
  set_inode(&block[32], 1, _FA_FILE | _FA_CTG,     /* BITMAP.SYS */
            1, 1, bmstblk, bmblocks, bmblocks, bmsize & 0x1FF, 0xCCC8);
  set_cdate(&block[32], now);
  set_mdate(&block[32], now);
  set_inode(&block[64], 1, _FA_FILE | _FA_CTG,     /* BOOT.SYS */
            1, 1, 0, 2, 2, 512, 0xCCC8);
  set_cdate(&block[64], now);
  set_mdate(&block[64], now);
  set_inode(&block[96], 1, _FA_DIR,                /* MASTER.DIR */
            1, 1, mdstblk, 2, 2, 512, 0xCCC8);
  set_cdate(&block[96], now);
  set_mdate(&block[96], now);
  set_inode(&block[128], 1, _FA_FILE | _FA_CTG,    /* CORIMG.SYS */
            1, 1, mdstblk + 2 + 1, 0, 0, 0, 0xDDD8);
  set_cdate(&block[128], now);
  set_mdate(&block[128], now);
  set_inode(&block[160], 1, _FA_FILE,              /* SYSTEM.SYS */
            1, 1, mdstblk + 2 + 1, 0, 0, 0, 0xDDD8);
  set_cdate(&block[160], now);
  set_mdate(&block[160], now);
  fwrite(block, 1, 512, f); /* block 2 */
  --blkcnt;
  memset(block, 0, 512);
  for (i = 1; i < ixblocks; ++i) {
    fwrite(block, 1, 512, f); /* remaining index file blocks */
    --blkcnt;
  }

  /* write the bitmap file (max 8K file), blocks 0 to mdstblk+2+1 are
   * already allocated to system files.
   *  note that max allowed index file size = ((max disk blocks) / 2) / 16
   *                                        = 65536 / 2 / 16 = 256 blocks,
   *  and max bitmap file size = (((max disk blocks) / 8) + 16) / 512
                               = 17 blocks,
   *  and boot block + initial master dir = 2 + 2 + 1 = 5 blocks,
   *  thus in the worst case we need to set here 256 + 17 + 5 = 278 bits in 
   *  the bitmap, all of which fit in one block */
  memset(block, 0, 512);
  block[0] = nblocks & 0xFF;        /* set device size in header */
  block[1] = (nblocks >> 8) & 0xFF;
  bmask = 0x00;
  mask = 0x80;
  for (i = 0, j = BMHDRSZ; i <= mdstblk + 2 + 1; ++i) {
    bmask |= mask;
    mask >>= 1;
    if (mask == 0) {
      block[j++] = bmask;
      bmask = 0x00;
      mask = 0x80;
    }
  }
  block[j] = bmask;
  fwrite(block, 1, 512, f);
  --blkcnt;
  memset(block, 0, 512);
  for (i = 1; i < bmblocks; ++i) {
    fwrite(block, 1, 512, f); /* remaining bitmap blocks */
    --blkcnt;                 /*   (nothing allocated)   */
  }

  /* create an alloc block for master directory */
  memset(block, 0, 512);
  block[4] = (mdstblk + 1) & 0xFF;
  block[5] = ((mdstblk + 1) >> 8) & 0xFF;
  block[6] = (mdstblk + 2) & 0xFF;
  block[7] = ((mdstblk + 2) >> 8) & 0xFF;
  fwrite(block, 1, 512, f); /* block mdstblk */
  --blkcnt;
  
  /* write master directory */
  memset(block, 0, 512);
  set_dir_entry(&block[0],  1, "INDEXF", "SYS", 1);
  set_dir_entry(&block[16], 2, "BITMAP", "SYS", 1);
  set_dir_entry(&block[32], 3, "BOOT",   "SYS", 1);
  set_dir_entry(&block[48], 4, "MASTER", "DIR", 1);
  set_dir_entry(&block[64], 5, "CORIMG", "SYS", 1);
  set_dir_entry(&block[80], 6, "SYSTEM", "SYS", 1);
  fwrite(block, 1, 512, f); /* block mdstblk + 1 */
  --blkcnt;
  memset(block, 0, 512);
  fwrite(block, 1, 512, f); /* block mdstblk + 2 */
  --blkcnt;
  
  /* create an empty alloc block for system image */
  memset(block, 0, 512);
  fwrite(block, 1, 512, f); /* block mdstblk + 3 */
  --blkcnt;

  /* fill the remaining of the disk with "formatted" bytes */
  while (blkcnt > 0) {
    memset(block, 0xE5, 512);
    fwrite(block, 1, 512, f); /* block n..end */
    --blkcnt;
  }
  
  fclose(f);

  return 0;
}
