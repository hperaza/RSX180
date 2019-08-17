$ALLOC	equ	01861h	; allocate pool memory
$ALUN	equ	01485h	; assign LUN to device
$ASGN	equ	012F5h	; assign logical name to physical device
$CLASN	equ	0136Fh	; delete all logical dev assignments of the given type
$CLIST	equ	04E4Fh	; list of CLI control blocks
$CLKQ	equ	04E4Dh	; ptr to head of clock queue
$CONN	equ	01607h	; connect to task
$CPCB	equ	04E4Bh	; address of PCB of current task
$CTCB	equ	04E49h	; address of TCB of current task
$DEASN	equ	01358h	; delete logical device assignment
$ERSEQ	equ	04E57h	; error sequence number
$FCBS	equ	04E76h	; ptr to head of FCB list
$FIXTK	equ	02B5Ah	; fix task in memory
$FNDEV	equ	013B0h	; find device and get UCB address
$FNPAR	equ	023F1h	; find partition by name
$FNTCB	equ	00EE5h	; find TCB by name
$FNTSK	equ	00EBAh	; find task by name
$FORKQ	equ	04E62h	; pointer to list of fork blocks
$FREE	equ	018C0h	; free pool memory
$GTUCB	equ	01470h	; get UCB address
$HOSTN	equ	04E2Ch	; host/node name
$LGOUT	equ	015B9h	; logout user
$LKTCB	equ	0083Ch	; link TCB to the specified list
$LOGDV	equ	04E3Fh	; ptr to head of logical device assignment list
$LOGIN	equ	01550h	; login user
$MCOPY	equ	0F22Bh	; inter-bank memory copy routine
$MEMSZ	equ	04E3Bh	; total memory size
$MFLGS	equ	04E61h	; MCR flags
$MVTBL	equ	04E64h	; ptr to head of mounted device list
$PHYDV	equ	04E3Dh	; ptr to head of physical device list
$PLIST	equ	04E41h	; ptr to list of partitions
$RLIST	equ	04E45h	; ptr to head of ready tasks list
$SCRBF	equ	04E66h	; scratch buffer address
$TLIST	equ	04E43h	; ptr to head of installed tasks list
$UNFTK	equ	02B63h	; unfix task
$WLIST	equ	04E47h	; ptr to head of waiting tasks list
BUFFER	equ	04E78h	; ptr to file I/O buffer area
IODONE	equ	01BE1h	; end I/O processing
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
LDRTCB	equ	04E53h	; LDR... TCB
MCRTCB	equ	04E51h	; MCR... TCB
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NUMBFS	equ	04E7Ah	; number of file I/O buffers
NVOK	equ	04914h	; P112 NV RAM OK flag
NVRAM	equ	048FCh	; P112 NV RAM contents
POOL	equ	04E39h	; ptr to start of pool area
POOLSZ	equ	04E37h	; size of pool area
REMTSK	equ	02B51h	; remove task from STD
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SETFLG	equ	0109Ah	; set task's event flag
SFLAGS	equ	04E59h	; system flags
SWSTK	equ	04E7Bh	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04E24h	; start of system data area
SYSEND	equ	04EC4h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	04E35h	; top of pool area
SYSVER	equ	04E2Ah	; system version number
TGO	equ	009B1h	; start task after being loaded
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	00B27h	; abort task
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	0153Dh	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
