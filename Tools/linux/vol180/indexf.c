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
#include <time.h>

#include "buffer.h"
#include "bitmap.h"
#include "indexf.h"
#include "misc.h"

extern unsigned short ixblock;

/*-----------------------------------------------------------------------*/

void set_inode(unsigned char *entry, unsigned short lnkcnt, char attrib,
               char group, char user, unsigned short block, unsigned nalloc,
               unsigned short nused, unsigned short lbcount,
               unsigned short perm) {
  int seqno;
  
  entry[0] = lnkcnt & 0xFF;
  entry[1] = (lnkcnt >> 8) & 0xFF;
  entry[2] = attrib;
  entry[3] = 0;
  seqno = entry[4] | (entry[5] << 8);
  ++seqno;
  entry[4] = seqno & 0xFF;
  entry[5] = (seqno >> 8) & 0xFF;
  entry[6] = user;
  entry[7] = group;
  entry[8] = block & 0xFF;
  entry[9] = (block >> 8) & 0xFF;
  entry[10] = nalloc & 0xFF;
  entry[11] = (nalloc >> 8) & 0xFF;
  entry[12] = nused & 0xFF;
  entry[13] = (nused >> 8) & 0xFF;
  entry[14] = lbcount & 0xFF;
  entry[15] = (lbcount >> 8) & 0xFF;
  entry[30] = perm & 0xFF;
  entry[31] = (perm >> 8) & 0xFF;
}

int read_inode(unsigned short num, unsigned char *entry) {
  unsigned short blkno, offset;
  struct BUFFER *buf;

  --num;  /* inodes are 1-based */
  blkno = ixblock + (num / 16);
  offset = (num % 16) * 32;
  buf = get_block(blkno);
  if (!buf) return 0;
  
  memcpy(entry, &buf->data[offset], 32);
  release_block(buf);
  
  return 1;
}

int write_inode(unsigned short num, unsigned char *entry) {
  unsigned short blkno, offset;
  struct BUFFER *buf;

  --num;  /* inodes are 1-based */
  blkno = ixblock + (num / 16);
  offset = (num % 16) * 32;
  buf = get_block(blkno);
  if (!buf) return 0;
  
  memcpy(&buf->data[offset], entry, 32);
  buf->modified = 1;
  release_block(buf);
  /* TODO: update modified timestamp of INDEXF.SYS file (inode 0)? */
  
  return 1;
}

int new_inode(void) {
  unsigned char inode[32];
  unsigned short i, nblks, nfiles;
  
  if (read_inode(1, inode) == 0) return 0;
  /* get number of index file used blocks */
  nblks = inode[12] | (inode[13] << 8);
  
  nfiles = nblks * 16;
  for (i = 1; i <= nfiles; ++i) { /* we can start from 2, since we know INDEXF.SYS is immutable */
    if (read_inode(i, inode) == 0) return 0;
    if ((inode[0] == 0) && (inode[1] == 0)) return i;
  }
  return 0;  /* index file full */
}

void set_date(unsigned char *buf, time_t t) {
  struct tm *tms;
  char temp[16];
  int  i;

  tms = localtime(&t);
  
  snprintf(temp, 15, "%04d%02d%02d%02d%02d%02d", tms->tm_year + 1900,
                    tms->tm_mon + 1, tms->tm_mday,
                    tms->tm_hour, tms->tm_min, tms->tm_sec);

  for (i = 0; i < 7; ++i) {
    buf[i] = ((temp[2*i] - '0') << 4) + (temp[2*i+1] - '0');
  }
}

void set_cdate(unsigned char *entry, time_t t) {
  set_date(&entry[16], t);
}

void set_mdate(unsigned char *entry, time_t t) {
  set_date(&entry[23], t);
}

void dump_inode(unsigned short num) {
  unsigned short blkno, offset;
  unsigned char *entry;
  struct BUFFER *buf;

  --num;  /* inodes are 1-based */
  blkno = ixblock + (num / 16);
  offset = (num % 16) * 32;

  printf("Index File entry %04X (virtual block %04X offset %04X):\n",
         num + 1, blkno, offset);

  buf = get_block(blkno);
  if (!buf) {
    printf("Unable to read block\n");
    return;
  }

  entry = &buf->data[offset];
  
  printf("\n");
  
  printf("  Link count             %04X\n", entry[0] | (entry[1] << 8));
  printf("  Attributes               %02X\n", entry[2]);
  printf("  Seq number             %04X\n", entry[4] | (entry[5] << 8));
  printf("  User ID                  %02X\n", entry[6]);
  printf("  Group ID                 %02X\n", entry[7]);
  printf("  Start block            %04X\n", entry[8] | (entry[9] << 8));
  printf("  Alloc blocks           %04X\n", entry[10] | (entry[11] << 8));
  printf("  Used blocks            %04X\n", entry[12] | (entry[13] << 8));
  printf("  Last block byte count  %04X\n", entry[14] | (entry[15] << 8));
  printf("  File created           %s\n", timestamp_str(&entry[16]));
  printf("  Last modified          %s\n", timestamp_str(&entry[23]));
  printf("  Access permissions     %04X\n", entry[30] | (entry[31] << 8));
  
  printf("\n");

  release_block(buf);
}
