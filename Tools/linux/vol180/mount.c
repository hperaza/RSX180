/***********************************************************************

   This file is part of vol180, an utility to handle RSX180 volumes.
   Copyright (C) 2008-2020, Hector Peraza.

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

#include "buffer.h"
#include "fileio.h"
#include "blockio.h"
#include "mount.h"
#include "misc.h"


/*-----------------------------------------------------------------------*/

FILE *imgf = NULL;

unsigned short nblocks = 0;
unsigned short bmblock = 0;
unsigned short ixblock = 0;
unsigned short mdirblk = 0;
unsigned short defprot = 0;

struct FCB *mdfcb = NULL, *cdfcb = NULL;

int mount_disk(char *imgname) {
  unsigned char buf[512], vh, vl, *inode;
  unsigned short mdfid;

  dismount_disk();

  imgf = fopen(imgname, "r+");
  if (!imgf) {
    fprintf(stderr, "Could not open disk image \"%s\": %s\n",
                    imgname, strerror(errno));
    return 1;
  }

  init_bufs();

  /* read the volume id block */
  read_block(1, buf);
  
  if (strncmp((char *) buf, "VOL180", 6) != 0) {
    fprintf(stderr, "Invalid volume type\n");
    fclose(imgf);
    imgf = NULL;
    return 1;
  }
  
  vl = buf[8];
  vh = buf[9];
  
  if ((vh != FVER_H) || ((vl != FVER_L) && (vl != FVER_L-1))) {
    fprintf(stderr, "Invalid filesystem version\n");
    fclose(imgf);
    imgf = NULL;
    return 1;
  }
  
  nblocks = buf[32] | (buf[33] << 8);
  defprot = buf[36] | (buf[37] << 8);
  ixblock = buf[64] | (buf[65] << 8);
  bmblock = buf[68] | (buf[69] << 8);
  mdirblk = buf[72] | (buf[73] << 8);

  printf("\n");
  printf("Volume label: %s\n", &buf[16]);
  printf("Created:      %s\n", timestamp_str(&buf[40]));
  printf("Version:      %d.%d\n", vh, vl);
  printf("Disk size:    %u blocks (%lu bytes)\n", nblocks, nblocks * 512L);
  printf("\n");

  /* read the first block of the index file */
  read_block(ixblock, buf);

  /* open the master directory */
  mdfid = (vl == FVER_L) ? 5 : 4;
  inode = &buf[(mdfid-1)*32]; /* !!! assumes MASTER.DIR has not moved! */
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
  mdfcb->byteptr = 0;

  cdfcb = open_md_file("MASTER.DIR");
  
  return 0;
}

int dismount_disk(void) {

  if (cdfcb) { close_file(cdfcb); free(cdfcb); }
  cdfcb = NULL;
  if (mdfcb) { close_file(mdfcb); free(mdfcb); }
  mdfcb = NULL;

  flush_buffers();

  if (imgf) fclose(imgf);
  imgf = NULL;

  return 1;
}
