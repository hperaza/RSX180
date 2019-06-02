ASSIGN	equ	01D1Dh	; assign logical name to physical device
BUFFER	equ	05C3Fh	; ptr to file I/O buffer area
BUFMEM	equ	05C41h	; size of file I/O buffer area
CLILST	equ	0AB80h	; list of CLI control blocks
CLKQ	equ	0AB67h	; ptr to head of clock queue
CONN	equ	02061h	; connect to task
CPCB	equ	0AB65h	; address of PCB of current task
CTCB	equ	0AB63h	; address of TCB of current task
DEASGN	equ	01D87h	; delete logical device assignment
ERRSEQ	equ	0AB73h	; error sequence number
FCBS	equ	05C3Dh	; ptr to head of FCB linked list
FIXTSK	equ	034B7h	; fix task in memory
FNDDEV	equ	01DC2h	; find device and get DCB address
FORKQ	equ	0AB82h	; pointer to list of fork blocks
GETUCB	equ	01E28h	; get UCB address
HOSTNM	equ	0AB4Ah	; host/node name
IHPOOL	equ	0F6C2h	; interrupt handler pool
IHPTR	equ	0F6C0h	; ptr to free space in IHPOOL
IHSP	equ	0F6BEh	; saved SP when servicing interrupts
IHSTK	equ	0F6BEh	; top of stack for interrupt service routines
INSTSK	equ	034A8h	; enter task into STD
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
KALLOC	equ	022CEh	; allocate pool memory
KFREE	equ	0232Dh	; free pool memory
LCBLST	equ	0AB7Eh	; ptr to head of session linked list
LDRTCB	equ	0AB6Bh	; LDR... TCB
LOGDEV	equ	0AB71h	; ptr to head of logical device assignment list
LOGIN	equ	01FB3h	; login user
LOGOUT	equ	0201Fh	; logout user
MCRTCB	equ	0AB69h	; MCR... TCB
MEMCPY	equ	0F22Bh	; inter-bank memory copy routine
MEMSZ	equ	0AB59h	; total memory size
MFLAGS	equ	0AB7Dh	; MCR flags
MVTBL	equ	0AB84h	; ptr to head of mounted device linked list
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NVOK	equ	0A212h	; P112 NV RAM OK flag
NVRAM	equ	0A1FAh	; P112 NV RAM contents
PHYDEV	equ	0AB6Fh	; ptr to head of physical device linked list
PLIST	equ	0AB5Bh	; ptr to list of partitions
POOL	equ	0AB57h	; ptr to start of pool area
POOLSZ	equ	0AB55h	; size of pool area
REMTSK	equ	034AEh	; remove task from STD
RLIST	equ	0AB5Fh	; ptr to head of ready tasks list
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SFLAGS	equ	0AB75h	; system flags
SWSTK	equ	0AB86h	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0AB42h	; start of system data area
SYSEND	equ	0ABCFh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	0AB53h	; top of pool area
SYSVER	equ	0AB48h	; system version number
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	01569h	; abort task
TLIST	equ	0AB5Dh	; ptr to head of installed tasks list
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UNFTSK	equ	034C0h	; unfix task
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
WLIST	equ	0AB61h	; ptr to head of waiting tasks list
