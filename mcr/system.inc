ASSIGN	equ	01CF9h	; assign logical name to physical device
BUFFER	equ	05C25h	; ptr to file I/O buffer area
BUFMEM	equ	05C27h	; size of file I/O buffer area
CLASGN	equ	01D77h	; delete all logical dev assignments of the given type
CLIST	equ	0A501h	; list of CLI control blocks
CLKQ	equ	0A4FFh	; ptr to head of clock queue
CONN	equ	02011h	; connect to task
CPCB	equ	0A4FDh	; address of PCB of current task
CTCB	equ	0A4FBh	; address of TCB of current task
DEASGN	equ	01D5Eh	; delete logical device assignment
ERRSEQ	equ	0A509h	; error sequence number
FCBS	equ	05C23h	; ptr to head of FCB linked list
FIXTSK	equ	034B4h	; fix task in memory
FNDDEV	equ	01DBAh	; find device and get UCB address
FORKQ	equ	0A514h	; pointer to list of fork blocks
GETUCB	equ	01E7Ah	; get UCB address
HOSTNM	equ	0A4DEh	; host/node name
IHPOOL	equ	0F6C2h	; interrupt handler pool
IHPTR	equ	0F6C0h	; ptr to free space in IHPOOL
IHSP	equ	0F6BEh	; saved SP when servicing interrupts
IHSTK	equ	0F6BEh	; top of stack for interrupt service routines
INSTSK	equ	034A5h	; enter task into STD
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
KALLOC	equ	0227Eh	; allocate pool memory
KFREE	equ	022DDh	; free pool memory
LDRTCB	equ	0A505h	; LDR... TCB
LOGDEV	equ	0A4F1h	; ptr to head of logical device assignment list
LOGIN	equ	01F5Ah	; login user
LOGOUT	equ	01FC3h	; logout user
MCRTCB	equ	0A503h	; MCR... TCB
MEMCPY	equ	0F22Bh	; inter-bank memory copy routine
MEMSZ	equ	0A4EDh	; total memory size
MFLAGS	equ	0A513h	; MCR flags
MVTBL	equ	0A516h	; ptr to head of mounted device linked list
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NVOK	equ	09FE3h	; P112 NV RAM OK flag
NVRAM	equ	09FCBh	; P112 NV RAM contents
PHYDEV	equ	0A4EFh	; ptr to head of physical device linked list
PLIST	equ	0A4F3h	; ptr to list of partitions
POOL	equ	0A4EBh	; ptr to start of pool area
POOLSZ	equ	0A4E9h	; size of pool area
REMTSK	equ	034ABh	; remove task from STD
RLIST	equ	0A4F7h	; ptr to head of ready tasks list
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SFLAGS	equ	0A50Bh	; system flags
SWSTK	equ	0A518h	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0A4D6h	; start of system data area
SYSEND	equ	0A561h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	0A4E7h	; top of pool area
SYSVER	equ	0A4DCh	; system version number
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	0154Dh	; abort task
TLIST	equ	0A4F5h	; ptr to head of installed tasks list
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	01F47h	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UNFTSK	equ	034BDh	; unfix task
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
WLIST	equ	0A4F9h	; ptr to head of waiting tasks list
