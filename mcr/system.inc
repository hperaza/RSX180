ASSIGN	equ	01D1Fh	; assign logical name to physical device
BUFFER	equ	05C33h	; ptr to file I/O buffer area
BUFMEM	equ	05C35h	; size of file I/O buffer area
CLILST	equ	0A507h	; list of CLI control blocks
CLKQ	equ	0A4EEh	; ptr to head of clock queue
CONN	equ	02062h	; connect to task
CPCB	equ	0A4ECh	; address of PCB of current task
CTCB	equ	0A4EAh	; address of TCB of current task
DEASGN	equ	01D89h	; delete logical device assignment
ERRSEQ	equ	0A4FAh	; error sequence number
FCBS	equ	05C31h	; ptr to head of FCB linked list
FIXTSK	equ	034B8h	; fix task in memory
FNDDEV	equ	01DC4h	; find device and get UCB address
FORKQ	equ	0A509h	; pointer to list of fork blocks
GETUCB	equ	01E2Eh	; get UCB address
HOSTNM	equ	0A4D1h	; host/node name
IHPOOL	equ	0F6C2h	; interrupt handler pool
IHPTR	equ	0F6C0h	; ptr to free space in IHPOOL
IHSP	equ	0F6BEh	; saved SP when servicing interrupts
IHSTK	equ	0F6BEh	; top of stack for interrupt service routines
INSTSK	equ	034A9h	; enter task into STD
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
KALLOC	equ	022CFh	; allocate pool memory
KFREE	equ	0232Eh	; free pool memory
LCBLST	equ	0A505h	; ptr to head of session linked list
LDRTCB	equ	0A4F2h	; LDR... TCB
LOGDEV	equ	0A4F8h	; ptr to head of logical device assignment list
LOGIN	equ	01FB4h	; login user
LOGOUT	equ	02020h	; logout user
MCRTCB	equ	0A4F0h	; MCR... TCB
MEMCPY	equ	0F22Bh	; inter-bank memory copy routine
MEMSZ	equ	0A4E0h	; total memory size
MFLAGS	equ	0A504h	; MCR flags
MVTBL	equ	0A50Bh	; ptr to head of mounted device linked list
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NVOK	equ	09FF4h	; P112 NV RAM OK flag
NVRAM	equ	09FDCh	; P112 NV RAM contents
PHYDEV	equ	0A4F6h	; ptr to head of physical device linked list
PLIST	equ	0A4E2h	; ptr to list of partitions
POOL	equ	0A4DEh	; ptr to start of pool area
POOLSZ	equ	0A4DCh	; size of pool area
REMTSK	equ	034AFh	; remove task from STD
RLIST	equ	0A4E6h	; ptr to head of ready tasks list
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SFLAGS	equ	0A4FCh	; system flags
SWSTK	equ	0A50Dh	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0A4C9h	; start of system data area
SYSEND	equ	0A556h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	0A4DAh	; top of pool area
SYSVER	equ	0A4CFh	; system version number
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	0156Bh	; abort task
TLIST	equ	0A4E4h	; ptr to head of installed tasks list
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UNFTSK	equ	034C1h	; unfix task
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
WLIST	equ	0A4E8h	; ptr to head of waiting tasks list
