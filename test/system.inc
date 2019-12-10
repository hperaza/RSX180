$ALLOC	equ	01875h	; allocate pool memory
$ALUN	equ	01494h	; assign LUN to device
$ASGN	equ	01304h	; assign logical name to physical device
$CLASN	equ	0137Eh	; delete all logical dev assignments of the given type
$CLIST	equ	04F2Dh	; list of CLI control blocks
$CLKQ	equ	04F2Bh	; ptr to head of clock queue
$CONN	equ	01616h	; connect to task
$CPCB	equ	04F29h	; address of PCB of current task
$CPLST	equ	04F1Fh	; ptr to head of checkpoint PCB list
$CTCB	equ	04F27h	; address of TCB of current task
$DEASN	equ	01367h	; delete logical device assignment
$ERSEQ	equ	04F37h	; error sequence number
$FCBS	equ	04F56h	; ptr to head of FCB list
$FEAT	equ	04F10h	; feature bits
$FIXTK	equ	02C3Bh	; fix task in memory
$FNDEV	equ	013BFh	; find device and get UCB address
$FNPAR	equ	02402h	; find partition by name
$FNTCB	equ	00F34h	; find TCB by name
$FNTSK	equ	00F09h	; find task by name
$FORKQ	equ	04F42h	; pointer to list of fork blocks
$FREE	equ	018D4h	; free pool memory
$GTUCB	equ	0147Fh	; get UCB address
$HOSTN	equ	04F07h	; host/node name
$LGOUT	equ	015C8h	; logout user
$LKTCB	equ	0083Fh	; link TCB to the specified list
$LOGDV	equ	04F1Bh	; ptr to head of logical device assignment list
$LOGIN	equ	0155Fh	; login user
$MCOPY	equ	0F22Bh	; inter-bank memory copy routine
$MEMSZ	equ	04F17h	; total memory size
$MFLGS	equ	04F41h	; MCR flags
$MVTBL	equ	04F44h	; ptr to head of mounted device list
$PHYDV	equ	04F19h	; ptr to head of physical device list
$PLIST	equ	04F1Dh	; ptr to list of partitions
$REMTK	equ	02C32h	; remove task from STD
$RLIST	equ	04F23h	; ptr to head of ready tasks list
$RNDC	equ	04F2Fh	; round-robin interval in ticks
$SCRBF	equ	04F46h	; scratch buffer address
$TLIST	equ	04F21h	; ptr to head of installed tasks list
$UNFTK	equ	02C44h	; unfix task
$WLIST	equ	04F25h	; ptr to head of waiting tasks list
BUFFER	equ	04F58h	; ptr to file I/O buffer area
IODONE	equ	01BF5h	; end I/O processing
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
LDRTCB	equ	04F33h	; LDR... TCB
MCRTCB	equ	04F31h	; MCR... TCB
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NUMBFS	equ	04F5Ah	; number of file I/O buffers
NVOK	equ	049EFh	; P112 NV RAM OK flag
NVRAM	equ	049D7h	; P112 NV RAM contents
POOL	equ	04F15h	; ptr to start of pool area
POOLSZ	equ	04F13h	; size of pool area
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SETFLG	equ	010AFh	; set task's event flag
SFLAGS	equ	04F39h	; system flags
SWSTK	equ	04F5Bh	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04EFFh	; start of system data area
SYSEND	equ	04FA4h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	04F11h	; top of pool area
SYSVER	equ	04F05h	; system version number
TGO	equ	009ACh	; start task after being loaded
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	00B82h	; abort task
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	0154Ch	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
