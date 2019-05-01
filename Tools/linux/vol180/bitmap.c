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

#include "fileio.h"
#include "buffer.h"
#include "bitmap.h"

extern unsigned short nblocks;
extern unsigned short bmblock;

/*-----------------------------------------------------------------------*/

/* Allocate single disk block: find free block in bitmap file, mark it
   as allocated and return its number. Returns zero if disk full */

unsigned alloc_block(void) {
  struct BUFFER *buf;
  unsigned char bmp, mask;
  unsigned short cnt, bmblk;
  unsigned i;

  /* nblocks is obtained from volume id (second block of BOOT.SYS) */
  cnt = BMHDRSZ;  /* skip header */
  bmblk = bmblock;
  buf = get_block(bmblk);
  if (!buf) return 0;
  mask = 0x80;
  bmp = buf->data[cnt];
  for (i = 0; i < nblocks; ++i) {
    if ((bmp & mask) == 0) {
      /* mark this block as used */
      bmp |= mask;
      buf->data[cnt] = bmp;
      buf->modified = 1;
      release_block(buf);
      return i;
    }
    mask >>= 1;
    if (mask == 0) {
      if (++cnt == 512) {
        release_block(buf);
        buf = get_block(++bmblk);
        if (!buf) return 0;
        cnt = 0;
      }
      bmp = buf->data[cnt];
      mask = 0x80;
    }
  }

  return 0;
}

/* Allocate contiguous disk space: find free contiguos blocks in bitmap
   file, mark them as allocated and return the number of the starting
   block. Returns zero on failure */

unsigned alloc_blocks(unsigned nblks) {
  struct BUFFER *buf;
  unsigned char bmp, mask;
  unsigned i, j, cstart;
  unsigned short cnt, bmblk;
  
  /* nblocks is obtained from volume id (second block of BOOT.SYS) */
  cstart = 0;     /* start of contiguous segment */
  j = 0;          /* contiguous block count */
  cnt = BMHDRSZ;  /* skip header */
  bmblk = bmblock;
  buf = get_block(bmblk);
  if (!buf) return 0;
  mask = 0x80;
  bmp = buf->data[cnt];
  for (i = 0; i < nblocks; ++i) {
    if ((bmp & mask) == 0) {
      /* free block, keep looking to see if we have enough in a row */
      if (j == 0) cstart = i;
      if (++j == nblks) break; /* found enough contiguous space */
    } else {
      /* block in use, reset search */
      j = 0;
    }
    mask >>= 1;
    if (mask == 0) {
      if (++cnt == 512) {
        release_block(buf);
        buf = get_block(++bmblk);
        if (!buf) return 0;
        cnt = 0;
      }
      bmp = buf->data[cnt];
      mask = 0x80;
    }
  }
  release_block(buf);

  if (j < nblks) return 0;
  
  /* now mark blocks as allocated */

  mask = (0x80 >> (cstart & 7));
  cnt = ((cstart >> 3) + BMHDRSZ) & 0x1FF;
  bmblk = bmblock + ((((cstart >> 3) + BMHDRSZ) >> 9) & 0x1F);

  buf = get_block(bmblk);
  if (!buf) return 0;
  bmp = buf->data[cnt];
  /* TODO: check this!!! */
  for (i = 0; i < nblks; ++i) {
    /* mark this block as used */
    bmp |= mask;
    mask >>= 1;
    if (mask == 0) {
      buf->data[cnt] = bmp;
      buf->modified = 1;
      if (++cnt == 512) {
        release_block(buf);
        buf = get_block(++bmblk);
        if (!buf) return 0;
        cnt = 0;
      }
      bmp = buf->data[cnt];
      mask = 0x80;
    }
  }
  if (mask != 0x80) {
    buf->data[cnt] = bmp;
    buf->modified = 1;
  }
  release_block(buf);

  return cstart;
}

int free_block(unsigned blkno) {
  struct BUFFER *buf;
  unsigned char mask;
  unsigned short cnt, bmblk;

  mask = (0x80 >> (blkno & 7));
  cnt = ((blkno >> 3) + BMHDRSZ) & 0x1FF;
  bmblk = bmblock + ((((blkno >> 3) + BMHDRSZ) >> 9) & 0x1F);
  
  buf = get_block(bmblk);
  if (!buf) return 0;
  
  buf->data[cnt] &= ~mask;
  buf->modified = 1;
  
  release_block(buf);

  //printf("freeing block %u\n", blkno);

  return 1;
}
