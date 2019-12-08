$ALLOC	equ	0186Dh	; allocate pool memory
$ALUN	equ	0148Ch	; assign LUN to device
$ASGN	equ	012FCh	; assign logical name to physical device
$CLASN	equ	01376h	; delete all logical dev assignments of the given type
$CLIST	equ	04F20h	; list of CLI control blocks
$CLKQ	equ	04F1Eh	; ptr to head of clock queue
$CONN	equ	0160Eh	; connect to task
$CPCB	equ	04F1Ch	; address of PCB of current task
$CTCB	equ	04F1Ah	; address of TCB of current task
$DEASN	equ	0135Fh	; delete logical device assignment
$ERSEQ	equ	04F2Ah	; error sequence number
$FCBS	equ	04F49h	; ptr to head of FCB list
$FIXTK	equ	02C33h	; fix task in memory
$FNDEV	equ	013B7h	; find device and get UCB address
$FNPAR	equ	023FAh	; find partition by name
$FNTCB	equ	00F13h	; find TCB by name
$FNTSK	equ	00EE8h	; find task by name
$FORKQ	equ	04F35h	; pointer to list of fork blocks
$FREE	equ	018CCh	; free pool memory
$GTUCB	equ	01477h	; get UCB address
$HOSTN	equ	04EFDh	; host/node name
$LGOUT	equ	015C0h	; logout user
$LKTCB	equ	0083Fh	; link TCB to the specified list
$LOGDV	equ	04F10h	; ptr to head of logical device assignment list
$LOGIN	equ	01557h	; login user
$MCOPY	equ	0F22Bh	; inter-bank memory copy routine
$MEMSZ	equ	04F0Ch	; total memory size
$MFLGS	equ	04F34h	; MCR flags
$MVTBL	equ	04F37h	; ptr to head of mounted device list
$PHYDV	equ	04F0Eh	; ptr to head of physical device list
$PLIST	equ	04F12h	; ptr to list of partitions
$REMTK	equ	02C2Ah	; remove task from STD
$RLIST	equ	04F16h	; ptr to head of ready tasks list
$RNDC	equ	04F22h	; round-robin interval in ticks
$SCRBF	equ	04F39h	; scratch buffer address
$TLIST	equ	04F14h	; ptr to head of installed tasks list
$UNFTK	equ	02C3Ch	; unfix task
$WLIST	equ	04F18h	; ptr to head of waiting tasks list
BUFFER	equ	04F4Bh	; ptr to file I/O buffer area
IODONE	equ	01BEDh	; end I/O processing
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
LDRTCB	equ	04F26h	; LDR... TCB
MCRTCB	equ	04F24h	; MCR... TCB
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NUMBFS	equ	04F4Dh	; number of file I/O buffers
NVOK	equ	049E5h	; P112 NV RAM OK flag
NVRAM	equ	049CDh	; P112 NV RAM contents
POOL	equ	04F0Ah	; ptr to start of pool area
POOLSZ	equ	04F08h	; size of pool area
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SETFLG	equ	010A7h	; set task's event flag
SFLAGS	equ	04F2Ch	; system flags
SWSTK	equ	04F4Eh	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04EF5h	; start of system data area
SYSEND	equ	04F97h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	04F06h	; top of pool area
SYSVER	equ	04EFBh	; system version number
TGO	equ	0098Dh	; start task after being loaded
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	00B5Dh	; abort task
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	01544h	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
