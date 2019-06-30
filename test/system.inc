ALUN	equ	017A7h	; assign LUN to device
ASSIGN	equ	01611h	; assign logical name to physical device
BUFFER	equ	05042h	; ptr to file I/O buffer area
CLASGN	equ	0168Fh	; delete all logical dev assignments of the given type
CLIST	equ	05029h	; list of CLI control blocks
CLKQ	equ	05027h	; ptr to head of clock queue
CONN	equ	01929h	; connect to task
CPCB	equ	05025h	; address of PCB of current task
CTCB	equ	05023h	; address of TCB of current task
DEASGN	equ	01676h	; delete logical device assignment
ERRSEQ	equ	05031h	; error sequence number
FCBS	equ	05040h	; ptr to head of FCB linked list
FIXTSK	equ	02DD5h	; fix task in memory
FNDDEV	equ	016D2h	; find device and get UCB address
FNDTCB	equ	011FBh	; find TCB by name
FORKQ	equ	0503Ch	; pointer to list of fork blocks
GETUCB	equ	01792h	; get UCB address
HOSTNM	equ	05006h	; host/node name
IHPOOL	equ	0F6C2h	; interrupt handler pool
IHPTR	equ	0F6C0h	; ptr to free space in IHPOOL
IHSP	equ	0F6BEh	; saved SP when servicing interrupts
IHSTK	equ	0F6BEh	; top of stack for interrupt service routines
INSTSK	equ	02DC6h	; enter task into STD
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
KALLOC	equ	01B85h	; allocate pool memory
KFREE	equ	01BE4h	; free pool memory
LDRTCB	equ	0502Dh	; LDR... TCB
LOGDEV	equ	05019h	; ptr to head of logical device assignment list
LOGIN	equ	01872h	; login user
LOGOUT	equ	018DBh	; logout user
MCRTCB	equ	0502Bh	; MCR... TCB
MEMCPY	equ	0F22Bh	; inter-bank memory copy routine
MEMSZ	equ	05015h	; total memory size
MFLAGS	equ	0503Bh	; MCR flags
MVTBL	equ	0503Eh	; ptr to head of mounted device linked list
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NUMBFS	equ	05044h	; number of file I/O buffers
NVOK	equ	04B0Bh	; P112 NV RAM OK flag
NVRAM	equ	04AF3h	; P112 NV RAM contents
PHYDEV	equ	05017h	; ptr to head of physical device linked list
PLIST	equ	0501Bh	; ptr to list of partitions
POOL	equ	05013h	; ptr to start of pool area
POOLSZ	equ	05011h	; size of pool area
REMTSK	equ	02DCCh	; remove task from STD
RLIST	equ	0501Fh	; ptr to head of ready tasks list
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SETFLG	equ	013B0h	; set task's event flag
SFLAGS	equ	05033h	; system flags
SWSTK	equ	05045h	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04FFEh	; start of system data area
SYSEND	equ	0508Eh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	0500Fh	; top of pool area
SYSVER	equ	05004h	; system version number
TGO	equ	00B25h	; start task after being loaded
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	00E3Bh	; abort task
TLIST	equ	0501Dh	; ptr to head of installed tasks list
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	0185Fh	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UNFTSK	equ	02DDEh	; unfix task
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
WLIST	equ	05021h	; ptr to head of waiting tasks list
