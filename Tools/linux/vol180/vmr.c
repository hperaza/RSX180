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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#include "fileio.h"
#include "misc.h"
#include "vmr.h"
#include "rsx180.h"

extern FILE *imgf;

struct symbol {
  char name[8];
  address value;
  int  set;
};

struct symbol symtab[] = {
  { "SYSDAT", 0, 0 },
  { "SYSVER", 0, 0 },
  { "SYSTOP", 0, 0 },
  { "HOSTNM", 0, 0 },
  { "SYSEND", 0, 0 },
  { "POOL",   0, 0 },
  { "POOLSZ", 0, 0 },
  { "PLIST",  0, 0 },
  { "TLIST",  0, 0 },
  { "CLIST",  0, 0 },
  { "CLKQ",   0, 0 },
  { "MCRTCB", 0, 0 },
  { "LDRTCB", 0, 0 },
  { "TKNTCB", 0, 0 },
  { "PHYDEV", 0, 0 },
  { "LOGDEV", 0, 0 },
  { "MFLAGS", 0, 0 },
  { "IDDTBL", 0, 0 },
  { "MVTBL",  0, 0 }
};

#define NSYM (sizeof(symtab)/sizeof(symtab[0]))

byte system_image[65536];
int system_size;

/*--------------------------------------------------------------------*/

/* Symbol table routines */

address read_value(struct FCB *f) {
  int i, c, value;

  value = 0;
  for (i = 0; i < 4; ++i) {
    c = 0;
    file_read(f, (byte *) &c, 1);
    c = toupper(c);
    value <<= 4;
    if ((c >= '0') && (c <= '9')) {
      value += (c - '0');
    } else if ((c >= 'A') && (c <= 'F')) {
      value += (c - 'A' + 10);
    }
  }

  file_read(f, (byte *) &c, 1);  /* skip following space */
  
  return value;
}

char *read_name(struct FCB *f) {
  static char str[16];
  int i, c;
  
  for (i = 0; i < 16; ++i) {
    c = 0;
    file_read(f, (byte *) &c, 1);
    if (!isspace(c)) str[i] = c; else break;
  }
  str[i] = '\0';
  if (c == '\r') file_read(f, (byte *) &c, 1);
  
  return str;
}

int load_symbols(struct FCB *f) {
  address value;
  char *name;
  int  i, retc;

#if 1
  for (i = 0; i < NSYM; ++i) symtab[i].set = 0;
#endif

  retc = 0;  
  while (!end_of_file(f)) {
    value = read_value(f);
    name = read_name(f);
    if (name[0] == '\x1A') break;
    for (i = 0; i < NSYM; ++i) {
      if (strcmp(symtab[i].name, name) == 0) {
        if (symtab[i].set) {
          printf("Duplicate symbol \"%s\"\n", name);
          retc = 1;
        } else {
          symtab[i].value = value;
          symtab[i].set = 1;
        }
      }
    }
  }

  for (i = 0; i < NSYM; ++i) {
    if (!symtab[i].set) {
      printf("Undefined symbol \"%s\"\n", symtab[i].name);
      retc = 1;
    }
  }

  return retc;
}

address get_sym(char *name) {
  int i;
  
  for (i = 0; i < NSYM; ++i) {
    if (strcmp(symtab[i].name, name) == 0) return symtab[i].value;
  }
  /* should not happen */
  printf("Unknown symbol \"%s\"\n", name);

  return 0;
}

/*--------------------------------------------------------------------*/

/* System image read/write routines */

int load_system(struct FCB *f) {
  system_size = file_read(f, system_image, 65536);
  return system_size;
}

int save_system(struct FCB *f) {
  file_seek(f, 0L);
  if (file_write(f, system_image, system_size) != system_size) {
    printf("Error saving system image\n");
    return 0;
  }
  return 1;
}

byte sys_getb(address addr) {
  return system_image[addr];
}

address sys_getw(address addr) {
  return system_image[addr] | (system_image[addr+1] << 8);
}

void sys_putb(address addr, byte val) {
  system_image[addr] = val & 0xff;
}

void sys_putw(address addr, address val) {
  system_image[addr] = val & 0xff;
  system_image[addr+1] = (val >> 8) & 0xff;
}

/*--------------------------------------------------------------------*/

/* Pool management routines */

void pool_init(void) {
  address sysend_addr, systop_addr, poolsize_addr, pool_addr;
  address poolsize, pool_start, pool_end;
  
  sysend_addr = get_sym("SYSEND");
  systop_addr = get_sym("SYSTOP");
  poolsize_addr = get_sym("POOLSZ");
  pool_addr = get_sym("POOL");
  
  poolsize = sys_getw(poolsize_addr);
  if (poolsize != 0) return; /* already initialized */
  
  printf("System not yet configured\n");

  pool_start = (sysend_addr + 3) & 0xfffc;
  pool_end   = 0xf000 & 0xfffc;  /* being politically correct ;) */
  
  poolsize = pool_end - pool_start;
  sys_putw(pool_addr, pool_start);
  sys_putw(systop_addr, pool_end);
  sys_putw(poolsize_addr, poolsize);
  
  sys_putw(pool_start, 0);  /* clear next pointer */
  sys_putw(pool_start + 2, poolsize);  /* set size */
}

address pool_alloc(address size) {
  address pool_addr, prev, next, link, blksz;
  
  size = (size + 3) & 0xfffc;  /* ensure 4-byte granularity */
  if (size == 0) {
    printf("Attempting to allocate block of zero size\n");
    return 0;
  }

  pool_addr = get_sym("POOL");

  prev = pool_addr;
  next = sys_getw(prev);
  while (1) {
    if (!next) {
      printf("No pool space\n");
      return 0;
    }
    link  = sys_getw(next);  /* get link */
    blksz = sys_getw(next + 2);  /* get size */
    if (blksz >= size) break;
    prev = next;
    next = link;
  }
  if (blksz == size) {
    /* exact match, update prev ptr */
    sys_putw(prev, link);
  } else {
    sys_putw(prev, next + size);  /* set prev ptr to new free block */
    sys_putw(next + size, link);  /* set next ptr on new block */
    sys_putw(next + size + 2, blksz - size);  /* set size field of new blk */
  }
  return next;
}

void pool_free(address addr, address size) {
  address pool_addr, prev, next, link, blksz;

  size = (size + 3) & 0xfffc;  /* ensure 4-byte granularity */
  if (size == 0) {
    printf("Attempting to free block of zero size\n");
    return;
  }

  pool_addr = get_sym("POOL");
  
  /* figure out where to reinsert the block */
  prev = pool_addr;
  next = sys_getw(prev);
  while (1) {
    next = sys_getw(prev);
    if (!next) break;  /* after end of free chain */
    if (next > addr) break;  /* or just here, between prev and next */
    prev = next;
  }
  sys_putw(prev, addr);
  sys_putw(addr, next);
  sys_putw(addr + 2, size);
  
  /* see if we can merge with prev */
  if (prev != pool_addr) {
    blksz = sys_getw(prev + 2);
    if (prev + blksz == addr) {
      size += blksz;
      sys_putw(prev, next); /* restore */
      sys_putw(prev + 2, size);
      addr = prev;
    }
  }
  
  /* see if we can merge with next */
  if (addr + size == next) {
    link = sys_getw(next);
    blksz = sys_getw(next + 2);
    size += blksz;
    sys_putw(addr, link);
    sys_putw(addr + 2, size);
  }
}

address pool_avail(void) {
  address poolsize, pool, total;

  poolsize = get_sym("POOLSZ");
  if (!poolsize) return 0;

  total = 0;  
  pool = get_sym("POOL");
  pool = sys_getw(pool);
  
  while (pool) {
    total += sys_getw(pool + 2);
    pool = sys_getw(pool);
  }
  return total;
}

/*--------------------------------------------------------------------*/

/* Device driver routines */

void load_devices(void) {
  address phydev, iddtbl, ddptr, dcb, ucb;
  
  phydev = get_sym("PHYDEV");
  if (sys_getw(phydev) != 0) return; /* device drivers already loaded */

  iddtbl = get_sym("IDDTBL");
  ddptr = sys_getw(iddtbl);
  while (ddptr) {
    dcb = pool_alloc(DCBSZ);
    if (!dcb) {
      printf("Out of pool space\n");
      return;
    }
    sys_putw(phydev + D_LNK, dcb); /* link DCB */
    sys_putw(dcb + D_LNK, 0);
    sys_putb(dcb + D_ST, 0);
    sys_putw(dcb + D_TCNT, 0);
    sys_putw(dcb + D_NAME, sys_getw(ddptr + 0));
    sys_putb(dcb + D_UNITS, sys_getw(ddptr + 2));
    sys_putw(dcb + D_UCBL, sys_getw(ddptr + 3));
    sys_putb(dcb + D_BANK, 0);
    sys_putw(dcb + D_START, ddptr);
    sys_putw(dcb + D_END, 0);
    sys_putw(dcb + D_EPT, ddptr + 5);
    
    ucb = sys_getw(dcb + D_UCBL);
    while (ucb) {
      sys_putw(ucb + U_DCB, dcb); /* set DCB back pointer in UCB */
      ucb = sys_getw(ucb + U_LNK);
    }
    phydev = dcb;
    iddtbl += 2;
    ddptr = sys_getw(iddtbl);
  }
}

//address find_device(char *name, char *ttdev) {
//}

void assign(char *pdev, char *ldev, byte type, char *ttdev) {
}

void deassign(char *ldev, byte type, char *ttdev) {
}

/*--------------------------------------------------------------------*/

/* Task-related routines */

address find_task(char *name) {
  address poolsize, tlist, prev;
  char tname[6];
  int i;

  poolsize = sys_getw(get_sym("POOLSZ"));
  if (poolsize == 0) return 0; /* virgin system - no tasks installed yet */

  prev = get_sym("TLIST");
  tlist = sys_getw(prev);

  while (tlist) {
    for (i = 0; i < 6; ++i) tname[i] = sys_getb(tlist + T_NAME + i);
    if (strncmp(name, tname, 6) == 0) return tlist;
    prev = tlist + T_TCBL;
    tlist = sys_getw(prev);
  }
  return 0;
}

void install_task(char *filename) {
  struct FCB *fcb;
  byte attr, thdr[THSZ];
  address tcb, tlist, prev, pcb;
  unsigned long tsize;
  char *p, pname[6];
  int i;
  
  fcb = open_file(filename);
  if (!fcb) {
    printf("File not found\n");
    return;
  }
  
  if (!(fcb->attrib & _FA_CTG)) {
    printf("File not contiguous\n");
    close_file(fcb);
    return;
  }
  
  //printf("Install device not LB0:\n");
  
  if (file_read(fcb, thdr, THSZ) != THSZ) {
    printf("Error reading Task Header\n");
    close_file(fcb);
    return;
  }

  close_file(fcb);

  if (strncmp((char *) &thdr[TH_HDR], "TSK180", 6) != 0) {
    printf("Invalid Task Header\n");
    return;
  }
  
  if ((thdr[TH_VER] != 2) && (thdr[TH_VER + 1] != 1)) {
    printf("Invalid Task File version\n");
    return;
  }

  /* check for existing installed task with the same name */
  if (find_task((char *) &thdr[TH_NAME])) {
    printf("Task name in use\n");
    return;
  }

  for (i = 0; i < 6; ++i) pname[i] = thdr[TH_PAR + i];
  pcb = find_partition(pname);
  if (!pcb) {
    printf("Partition not in system\n");
    return;
  }
  
  tcb = pool_alloc(TCBSZ);
  if (!tcb) {
    printf("Out of pool space\n");
    return;
  }
  
  sys_putw(tcb + T_LNK, 0);
  attr = 0;
  if (thdr[TH_PRV]) attr |= (1 << TA_PRV);
  sys_putb(tcb + T_ATTR, attr);
  sys_putb(tcb + T_ST, 0);
  sys_putb(tcb + T_DPRI, thdr[TH_PRI]);
  sys_putb(tcb + T_PRI, thdr[TH_PRI]);
  sys_putb(tcb + T_PRV, 0);
  for (i = 0; i < 6; ++i) sys_putb(tcb + T_NAME + i, thdr[TH_NAME + i]);
  for (i = 0; i < 6; ++i) sys_putb(tcb + T_VID + i, thdr[TH_VID + i]);
  sys_putw(tcb + T_CMD, 0);
  sys_putb(tcb + T_IOC, 0);
  sys_putw(tcb + T_RCVL, 0);
  sys_putw(tcb + T_OCBL, 0);
  sys_putw(tcb + T_ASTL, 0);
  sys_putw(tcb + T_ASTP, 0);
  sys_putw(tcb + T_SAST, 0);
  for (i = 0; i < 4; ++i) sys_putb(tcb + T_FLGS + i, 0);
  for (i = 0; i < 4; ++i) sys_putb(tcb + T_WAIT + i, 0);
  sys_putw(tcb + T_CTX, 0);
  sys_putw(tcb + T_TI, 0);
  sys_putb(tcb + T_CON, 'T');
  sys_putb(tcb + T_CON + 1, 'T');
  sys_putb(tcb + T_CON + 2, 0);
  sys_putb(tcb + T_LIB, 'L');
  sys_putb(tcb + T_LIB + 1, 'B');
  sys_putb(tcb + T_LIB + 2, 0);
#if 1
  sys_putw(tcb + T_SBLK, fcb->stablk);
#else
  sys_putw(tcb + T_SBLK, fcb->inode);
#endif
  sys_putw(tcb + T_SBLK + 2, 0);
  sys_putw(tcb + T_NBLK, fcb->nused);
  sys_putw(tcb + T_PCB, pcb);
  tsize = ((fcb->nused - 1) * 512 + fcb->lbcount) - THSZ;
#if 0
  if (increment) {
    tsize += increment;
  } else {
    tsize += thdr[TH_INC] | (thdr[TH_INC + 1] << 8);
  }
#else
  tsize += thdr[TH_INC] | (thdr[TH_INC + 1] << 8);
#endif
  tsize += (4095 + 0x100);  // (pagesize - 1) + code start
  if (tsize > 0xf000) {
    printf("Program too big\n");
    return;
  }
  tsize &= 0xf000;  // round to page size
  sys_putw(tcb + T_STRT, 0);
  sys_putw(tcb + T_END, tsize - 1);
  sys_putw(tcb + T_SP, tsize);
  sys_putw(tcb + T_EPT, 0x100);
  sys_putb(tcb + T_SVST, 0);
  
  /* link TCB */
  prev = get_sym("TLIST");
  tlist = sys_getw(prev);

  while (tlist) {
    if (sys_getb(tlist + T_PRI) < thdr[TH_PRI]) break;
    prev = tlist + T_TCBL;
    tlist = sys_getw(prev);
  }
  sys_putw(prev, tcb);
  sys_putw(tcb + T_TCBL, tlist);
}

void remove_task(char *name) {
  address poolsize, tlist, prev, next;
  byte attr;
  char tname[6];
  int i;

  poolsize = sys_getw(get_sym("POOLSZ"));
  if (poolsize == 0) return; /* virgin system - no tasks installed yet */

  prev = get_sym("TLIST");
  tlist = sys_getw(prev);

  while (tlist) {
    attr = sys_getb(tlist + T_ATTR);
    for (i = 0; i < 6; ++i) tname[i] = sys_getb(tlist + T_NAME + i);
    if (strncmp(name, tname, 6) == 0) {
      if (attr & (1 << TA_FIX)) {
        printf("Task fixed in memory\n");
        return;
      }
      /* unlink TCB */
      next = sys_getw(tlist + T_TCBL);
      sys_putw(prev, next);
      /* free TCB */
      pool_free(tlist, TCBSZ);
      return;
    }
    prev = tlist + T_TCBL;
    tlist = sys_getw(prev);
  }
  printf("Task not in system\n");
}

void list_tasks(char *name) {
  address poolsize, tlist, pcb;
  unsigned long sblk, nblk;
  byte pri, attr;
  char tname[6], ident[6], par[6], dv[3];
  int i;

  poolsize = sys_getw(get_sym("POOLSZ"));
  if (poolsize == 0) return; /* virgin system - no tasks installed yet */

  tlist = sys_getw(get_sym("TLIST"));

  while (tlist) {
    if (sys_getb(tlist + T_NAME) != '*') {
      attr = sys_getb(tlist + T_ATTR);
      for (i = 0; i < 6; ++i) tname[i] = sys_getb(tlist + T_NAME + i);
      for (i = 0; i < 6; ++i) ident[i] = sys_getb(tlist + T_VID + i);
      pcb = sys_getw(tlist + T_PCB);
      for (i = 0; i < 6; ++i) par[i] = sys_getb(pcb + P_NAME + i);
      pri = sys_getb(tlist + T_PRI);
      dv[0] = sys_getb(tlist + T_LIB);
      dv[1] = sys_getb(tlist + T_LIB + 1);
      dv[2] = sys_getb(tlist + T_LIB + 2);
      sblk = sys_getw(tlist + T_SBLK) + (sys_getw(tlist + T_SBLK + 2) << 16);
      nblk = sys_getw(tlist + T_NBLK);
      
      if (!name || !*name || (strncmp(name, tname, 6) == 0)) {
#if 1
        printf("%.6s %.6s %04X %.6s %3d %08lX %c%c%d:%08lX %s\n",
               tname, ident, tlist, par, pri, nblk * 512, dv[0], dv[1], dv[2],
               sblk, (attr & (1 << TA_FIX)) ? "FIXED" : "");
#else
        printf("%.6s %.6s %04X %.6s %3d %08lX %c%c%d:- FILE ID:%ld %s\n",
               tname, ident, tlist, par, pri, nblk * 512, dv[0], dv[1], dv[2],
               sblk, (attr & (1 << TA_FIX)) ? "FIXED" : "");
#endif
      }
    }
    tlist = sys_getw(tlist + T_TCBL);
  }
}

/*--------------------------------------------------------------------*/

/* Partition-related routines */

address find_partition(char *name) {
  address poolsize, plist, prev;
  char pname[6];
  int i;

  poolsize = sys_getw(get_sym("POOLSZ"));
  if (poolsize == 0) return 0; /* virgin system - no tasks installed yet */

  prev = get_sym("PLIST");
  plist = sys_getw(prev);

  while (plist) {
    for (i = 0; i < 6; ++i) pname[i] = sys_getb(plist + P_NAME + i);
    if (strncmp(name, pname, 6) == 0) return plist;
    prev = plist + P_LNK;
    plist = sys_getw(prev);
  }
  return 0;
}

void add_partition(char *name, address base, address size, byte type) {
  address poolsize, plist, prev, pcb;
  int i;
  
  poolsize = sys_getw(get_sym("POOLSZ"));
  if (poolsize == 0) return; /* virgin system - hst not been setup yet */

  /* check for existing partition with the same name */
  pcb = find_partition(name);
  if (pcb) {
    printf("Partition name in use\n");
    return;
  }

  /* create main partition */
  pcb = pool_alloc(PCBSZ);
  if (!pcb) {
    printf("Out of pool space\n");
    return;
  }
  
  sys_putw(pcb + P_BASE, base);
  sys_putw(pcb + P_SIZE, size);
  sys_putw(pcb + P_MAIN, pcb);
  for (i = 0; i < 6; ++i) sys_putb(pcb + P_NAME + i, name[i]);
  sys_putw(pcb + P_SUB, 0);
  sys_putb(pcb + P_ATTR, type);
  sys_putb(pcb + P_STAT, 0);
  sys_putw(pcb + P_TCB, 0);

  /* link partition into partition list */
  prev = get_sym("PLIST");
  plist = sys_getw(prev);
  while (plist) {
    if (sys_getw(plist + P_BASE) > base) break;
    prev = plist + P_LNK;
    plist = sys_getw(prev);
  }
  sys_putw(prev + P_LNK, pcb);
  sys_putw(pcb + P_LNK, plist);
}

void remove_partition(char *name) {
}

void list_partitions(void) {
  address poolsize, plist, sublist, pbase, psize, tcb;
  byte attr;
  char pname[6], tname[6];
  int i;

  poolsize = sys_getw(get_sym("POOLSZ"));
  if (poolsize == 0) return; /* virgin system - no partitions yet */

  plist = sys_getw(get_sym("PLIST"));

  while (plist) {
    attr = sys_getb(plist + P_ATTR);
    for (i = 0; i < 6; ++i) pname[i] = sys_getb(plist + P_NAME + i);
    pbase = sys_getw(plist + P_BASE);
    psize = sys_getw(plist + P_SIZE);
    
    printf("%.6s %04X %03X000 %03X000 %-4s %-4s\n",
           pname, plist, pbase, psize,
           (attr & (1 << PA_SUB)) ? "SUB" : "MAIN",
           (attr & (1 << PA_SYS)) ? "SYS" : "TASK");
    sublist = sys_getw(plist + P_SUB);
    while (sublist) {
      tcb = sys_getw(sublist + P_TCB);
      if (tcb) {
        for (i = 0; i < 6; ++i) tname[i] = sys_getb(tcb + T_NAME + i);
      }
      printf("      %04X %03X000 %03X000 %-4s (%.6s)\n",
              plist, pbase, psize,
              (attr & (1 << PA_SUB)) ? "SUB" : "MAIN",
              tname);
      sublist = sys_getw(sublist + P_LNK);
    }
    plist = sys_getw(plist + P_LNK);
  }
}

/*-----------------------------------------------------------------------*/

/* Open system image */
int open_system_image(char *imgfile, char *symfile) {
  struct FCB *fcb;
  unsigned char b1, b2;
  unsigned short addr;
  char *p, *signature = "SYSDAT";
  int i, syssz;
  
  fcb = open_file(imgfile);
  if (fcb) {
    syssz = load_system(fcb);
    close_file(fcb);
    free(fcb);
  } else {
    printf("Could not open system image file\n");
    return 0;
  }
  
  fcb = open_file(symfile);
  if (fcb) {
    load_symbols(fcb);
    close_file(fcb);
    free(fcb);
  } else {
    printf("Could not open symbol file\n");
    return 0;
  }
  
  /* validate signature */
  addr = get_sym("SYSDAT");
  p = signature;
  for (i = 0; i < 6; ++i) {
    if (sys_getb(addr++) != *p++) {
      printf("Invalid system image signature\n");
      return 0;
    }
  }
  addr = get_sym("SYSVER");
  b2 = sys_getb(addr++);
  b1 = sys_getb(addr);
  printf("System image V%d.%02d, size 0%04Xh\n", b1, b2, syssz);

  pool_init();
  load_devices();
  
  return 1;
}

/* Save system image */
int save_system_image(char *imgfile) {
  struct FCB *fcb;

#if 0
  fcb = create_file(imgfile, 1, 1, 0, 0);
#else
  fcb = open_file(imgfile);
#endif
  if (fcb) {
    save_system(fcb);
    close_file(fcb);
    free(fcb);
  } else {
    printf("Could not open/create system image file\n");
    return 0;
  }
  
  return 1;
}

void pool_trace(void) {
  unsigned short pool, next, size;
  int n;
  
  pool = get_sym("POOL");

  pool = sys_getw(pool);
  printf("Pool: %04X", pool);
  
  n = 0;
  while (pool) {
    next = sys_getw(pool);
    size = sys_getw(pool + 2);
    printf(" -> %04X (%04X)", next, size);
    if (++n == 4) {
      printf("\n          ");
      n = 0;
    }
    pool = next;
  }
  printf("\n");
  printf("Free: %04X\n", pool_avail());
}

void test(void) {
  char str[256], cmd[256], arg[256];
  unsigned short blks[20], size[20];
  int i;
  
  for (i = 0; i < 20; ++i) blks[i] = 0;

  for (;;) {
    pool_trace();
    for (i = 0; i < 20; ++i) {
      if (blks[i]) printf("%2d. %04X (%04X)\n", i, blks[i], size[i]);
    }
    printf("POOL>");
    fflush(stdout);
    fgets(str, 255, stdin);
    str[strlen(str)-1] = '\0';  // strip newline
    if (feof(stdin)) break;

    cmd[0] = arg[0] = '\0';
    sscanf(str, "%s %s", cmd, arg);
        
    if (!*cmd) {
      continue;
    } else if (strcmp(cmd, "alloc") == 0) {
      for (i = 0; i < 20; ++i) if (blks[i] == 0) break;
      if (i == 20) {
        printf("Table full\n");
        continue;
      }
      size[i] = atoi(arg);
      if (size[i] == 0) continue;
      blks[i] = pool_alloc(size[i]);
      if (blks[i] == 0) {
        printf("Alloc failed\n");
        continue;
      }
    } else if (strcmp(cmd, "free") == 0) {
      i = atoi(arg);
      if ((i < 0) || (i >= 20)) continue;
      if (blks[i] == 0) continue;
      pool_free(blks[i], size[i]);
      blks[i] = 0;
    } else if (strcmp(cmd, "end") == 0) {
      for (i = 0; i < 20; ++i) {
        if (blks[i]) pool_free(blks[i], size[i]);
      }
      return;
    }
  }
}

/*-----------------------------------------------------------------------*/

int get_line(struct FCB *fcb, char *str, int maxlen) {
  int c, len;
  
  len = 0;
  for (;;) {
    c = 0;
    if (file_read(fcb, (byte *) &c, 1) != 1) break;
    if (c == '\r') continue;
    if (c == '\n') break;
    if (len < maxlen) str[len++] = c;
  }
  str[len] = '\0';
  return len;
}

int vmr_command(char *cmd, char *args) {
  char *p;

  strupr(cmd);
  if (strcmp(cmd, "INS") == 0) {
    p = strchr(args, '/');
    if (p) *p = '\0';
    p = strchr(args, '.');
    if (!p) strcat(args, ".tsk");
    strupr(args);
    install_task(args);
  } else if (strcmp(cmd, "REM") == 0) {
    int i = strlen(args);
    strupr(args);
    for (; i < 6; ++i) args[i] = ' ';
    remove_task(args);
  } else if (strcmp(cmd, "TAS") == 0) {
    strupr(args);
    list_tasks(args);
  } else if (strcmp(cmd, "SET") == 0) {
    unsigned short base, size;
    unsigned char type;
    char pname[6];
    int i;
      
    strupr(args);
    if (strncmp(args, "/PAR=", 5) == 0) {
      p = args + 5;
      for (i = 0; i < 6; ++i) {
        if (*p && (*p != ':')) pname[i] = *p++; else pname[i] = ' ';
      }
      if (*p == ':') ++p;
      base = strtol(p, &p, 10);
      if (*p == ':') ++p;
      size = strtol(p, &p, 10);
      if (*p == ':') ++p;
      if (strcmp(p, "SYS") == 0) type = (1 << PA_SYS); else type = 0;
      add_partition(pname, base, size, type);
    } else {
      fprintf(stderr, "Invalid SET command\n");
      return 0;
    }
  } else if (strcmp(cmd, "PAR") == 0) {
    list_partitions();
  } else if (strcmp(cmd, "TST") == 0) {
    test();
  } else {
    fprintf(stderr, "Unknown command: %s\n", cmd);
    return 0;
  }
  return 1;
}

int vmr(char *cmdstr) {
  int  n;
  char *p, imgnam[256], symnam[256], cmd[256], args[256];

  imgnam[0] = cmd[0] = args[0] = '\0';
  n = 0;
  sscanf(cmdstr, "%s %s %n", imgnam, cmd, &n);
  if (n > 0) strcpy(args, cmdstr + n);
        
  if (!*imgnam) return 0;

  if (imgnam[0] == '@') {
    /* process command file */
    struct FCB *fcb;
    int  len;
    char line[256];

    p = strchr(imgnam, '.');
    if (!p) strcat(imgnam, ".cmd");
    strupr(imgnam);
    
    fcb = open_file(imgnam + 1);
    if (!fcb) {
      fprintf(stderr, "File not found\n");
      return 0;
    }
    /* first line contains the name of the system image file */
    len = get_line(fcb, imgnam, 256);
    if (len == 0) {
      fprintf(stderr, "Command file empty\n");
      close_file(fcb);
      free(fcb);
      return 0;
    }

    strcpy(symnam, imgnam);
    p = strchr(symnam, '.');
    if (p) *p = '\0';
    strcat(symnam, ".sym");

    p = strchr(imgnam, '.');
    if (!p) strcat(imgnam, ".sys");
    strupr(imgnam);
    strupr(symnam);

    if (!open_system_image(imgnam, symnam)) {
      fprintf(stderr, "File not found\n");
      close_file(fcb);
      free(fcb);
      return 0;
    }
   
    for (;;) {
      /* get line */
      len = get_line(fcb, line, 256);
      if (len == 0) break;
      cmd[0] = args[0] = '\0';
      n = 0;
      sscanf(line, "%s %n", cmd, &n);
      if (n > 0) strcpy(args, line + n);
      vmr_command(cmd, args);
    }
    save_system_image(imgnam);
    close_file(fcb);
    free(fcb);
    
  } else {
    /* process single command */
    if (!*cmd) return 0;

    strcpy(symnam, imgnam);
    p = strchr(symnam, '.');
    if (p) *p = '\0';
    strcat(symnam, ".sym");

    p = strchr(imgnam, '.');
    if (!p) strcat(imgnam, ".sys");
    strupr(imgnam);
    strupr(symnam);
    open_system_image(imgnam, symnam);
    
    strupr(cmd);
    cmd[3] = '\0';
    
    vmr_command(cmd, args);

    save_system_image(imgnam);
  }

  return 1;
}
