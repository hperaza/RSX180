ASSIGN	equ	01D1Ch	; assign logical name to physical device
BUFFER	equ	05C3Eh	; ptr to file I/O buffer area
BUFMEM	equ	05C40h	; size of file I/O buffer area
CLILST	equ	0AB7Fh	; list of CLI control blocks
CLKQ	equ	0AB66h	; ptr to head of clock queue
CONN	equ	02060h	; connect to task
CPCB	equ	0AB64h	; address of PCB of current task
CTCB	equ	0AB62h	; address of TCB of current task
DEASGN	equ	01D86h	; delete logical device assignment
ERRSEQ	equ	0AB72h	; error sequence number
FCBS	equ	05C3Ch	; ptr to head of FCB linked list
FIXTSK	equ	034B6h	; fix task in memory
FNDDEV	equ	01DC1h	; find device and get DCB address
FORKQ	equ	0AB81h	; pointer to list of fork blocks
GETUCB	equ	01E27h	; get UCB address
HOSTNM	equ	0AB49h	; host/node name
IHPOOL	equ	0F6A0h	; interrupt handler pool
IHPTR	equ	0F69Eh	; ptr to free space in IHPOOL
IHSP	equ	0F69Ch	; saved SP when servicing interrupts
IHSTK	equ	0F69Ch	; top of stack for interrupt service routines
INSTSK	equ	034A7h	; enter task into STD
ITBL	equ	0F45Ch	; space for interrupt table
ITBLP	equ	0F45Ah	; interrupt table pointer
KALLOC	equ	022CDh	; allocate pool memory
KFREE	equ	0232Ch	; free pool memory
LCBLST	equ	0AB7Dh	; ptr to head of session linked list
LDRTCB	equ	0AB6Ah	; LDR... TCB
LOGDEV	equ	0AB70h	; ptr to head of logical device assignment list
LOGIN	equ	01FB2h	; login user
LOGOUT	equ	0201Eh	; logout user
MCRTCB	equ	0AB68h	; MCR... TCB
MEMCPY	equ	0F209h	; inter-bank memory copy routine
MEMSZ	equ	0AB58h	; total memory size
MFLAGS	equ	0AB7Ch	; MCR flags
MVTBL	equ	0AB83h	; ptr to head of mounted device linked list
M_EPT	equ	0F7A0h	; debugger-monitor normal entry point
NVOK	equ	0A211h	; P112 NV RAM OK flag
NVRAM	equ	0A1F9h	; P112 NV RAM contents
PHYDEV	equ	0AB6Eh	; ptr to head of physical device linked list
PLIST	equ	0AB5Ah	; ptr to list of partitions
POOL	equ	0AB56h	; ptr to start of pool area
POOLSZ	equ	0AB54h	; size of pool area
REMTSK	equ	034ADh	; remove task from STD
RLIST	equ	0AB5Eh	; ptr to head of ready tasks list
SCBAR	equ	0F459h	; supervisor mode CBAR value
SFLAGS	equ	0AB74h	; system flags
SWSTK	equ	0AB85h	; stub to call kernel routines
SYSBBR	equ	0F456h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0AB41h	; start of system data area
SYSEND	equ	0ABC7h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSTOP	equ	0AB52h	; top of pool area
SYSVER	equ	0AB47h	; system version number
TICCNT	equ	0F44Bh	; absolute time count in ticks
TICSEC	equ	0F44Ah	; ticks per second
TKILL	equ	01568h	; abort task
TLIST	equ	0AB5Ch	; ptr to head of installed tasks list
TM_EPT	equ	0FA3Eh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C0h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F458h	; user mode CBAR value
UGETB	equ	0F38Ch	; inter-bank get byte routine
UGETBB	equ	0F3F5h	; inter-bank get byte routine
UGETWB	equ	0F42Ch	; inter-bank get word routine
UNFTSK	equ	034BFh	; unfix task
UPTIME	equ	0F44Fh	; system up time (ticks and seconds)
UPUTB	equ	0F3B0h	; inter-bank put byte routine
UPUTBB	equ	0F3D8h	; inter-bank put byte routine
UPUTWB	equ	0F40Eh	; inter-bank put word routine
USRBBR	equ	0F457h	; BBR of current executing task
WLIST	equ	0AB60h	; ptr to head of waiting tasks list
