ASSIGN	equ	01CDEh	; assign logical name to physical device
BUFFER	equ	05BFAh	; ptr to file I/O buffer area
BUFMEM	equ	05BFCh	; size of file I/O buffer area
CLASGN	equ	01D5Eh	; delete all logical dev assignments of the given type
CLILST	equ	0A4E7h	; list of CLI control blocks
CLKQ	equ	0A4D0h	; ptr to head of clock queue
CONN	equ	01FE6h	; connect to task
CPCB	equ	0A4CEh	; address of PCB of current task
CTCB	equ	0A4CCh	; address of TCB of current task
DEASGN	equ	01D42h	; delete logical device assignment
ERRSEQ	equ	0A4DCh	; error sequence number
FCBS	equ	05BF8h	; ptr to head of FCB linked list
FIXTSK	equ	03489h	; fix task in memory
FNDDEV	equ	01DA1h	; find device and get UCB address
FORKQ	equ	0A4E9h	; pointer to list of fork blocks
GETUCB	equ	01E5Eh	; get UCB address
HOSTNM	equ	0A4B3h	; host/node name
IHPOOL	equ	0F6C2h	; interrupt handler pool
IHPTR	equ	0F6C0h	; ptr to free space in IHPOOL
IHSP	equ	0F6BEh	; saved SP when servicing interrupts
IHSTK	equ	0F6BEh	; top of stack for interrupt service routines
INSTSK	equ	0347Ah	; enter task into STD
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
KALLOC	equ	02253h	; allocate pool memory
KFREE	equ	022B2h	; free pool memory
LDRTCB	equ	0A4D4h	; LDR... TCB
LOGDEV	equ	0A4DAh	; ptr to head of logical device assignment list
LOGIN	equ	01F3Eh	; login user
LOGOUT	equ	01FB1h	; logout user
MCRTCB	equ	0A4D2h	; MCR... TCB
MEMCPY	equ	0F22Bh	; inter-bank memory copy routine
MEMSZ	equ	0A4C2h	; total memory size
MFLAGS	equ	0A4E6h	; MCR flags
MVTBL	equ	0A4EBh	; ptr to head of mounted device linked list
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NVOK	equ	09FB8h	; P112 NV RAM OK flag
NVRAM	equ	09FA0h	; P112 NV RAM contents
PHYDEV	equ	0A4D8h	; ptr to head of physical device linked list
PLIST	equ	0A4C4h	; ptr to list of partitions
POOL	equ	0A4C0h	; ptr to start of pool area
POOLSZ	equ	0A4BEh	; size of pool area
REMTSK	equ	03480h	; remove task from STD
RLIST	equ	0A4C8h	; ptr to head of ready tasks list
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SFLAGS	equ	0A4DEh	; system flags
SWSTK	equ	0A4EDh	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0A4ABh	; start of system data area
SYSEND	equ	0A536h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	0A4BCh	; top of pool area
SYSVER	equ	0A4B1h	; system version number
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	0152Ah	; abort task
TLIST	equ	0A4C6h	; ptr to head of installed tasks list
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	01F2Bh	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UNFTSK	equ	03492h	; unfix task
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
WLIST	equ	0A4CAh	; ptr to head of waiting tasks list
