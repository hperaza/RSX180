$ALLOC	equ	019FDh	; allocate pool memory
$ALUN	equ	0161Ch	; assign LUN to device
$ASGN	equ	0148Ch	; assign logical name to physical device
$CHKPT	equ	0280Bh	; initiate task checkpoint
$CLASN	equ	01506h	; delete all logical dev assignments of the given type
$CLIST	equ	053F5h	; list of CLI control blocks
$CLKQ	equ	053F3h	; ptr to head of clock queue
$CONN	equ	0179Eh	; connect to task
$CPCB	equ	053F1h	; address of PCB of current task
$CPLST	equ	053E7h	; ptr to head of checkpoint PCB list
$CTCB	equ	053EFh	; address of TCB of current task
$DEASN	equ	014EFh	; delete logical device assignment
$ERSEQ	equ	05404h	; error sequence number
$FCBS	equ	05423h	; ptr to head of FCB list
$FEAT	equ	053D8h	; feature bits
$FIXTK	equ	030CAh	; fix task in memory
$FNDEV	equ	01547h	; find device and get UCB address
$FNPAR	equ	025DDh	; find partition by name
$FNTCB	equ	010C8h	; find TCB by name
$FNTSK	equ	0109Dh	; find task by name
$FORKQ	equ	0540Fh	; pointer to list of fork blocks
$FREE	equ	01A5Ch	; free pool memory
$GTUCB	equ	01607h	; get UCB address
$HOSTN	equ	053CFh	; host/node name
$IOEND	equ	01DA3h	; end I/O processing for ASTs
$LGOUT	equ	01750h	; logout user
$LKTCB	equ	008C6h	; link TCB to the specified list
$LOGDV	equ	053E3h	; ptr to head of logical device assignment list
$LOGIN	equ	016E7h	; login user
$MCOPY	equ	0F22Eh	; inter-bank memory copy routine
$MEMSZ	equ	053DFh	; total memory size
$MFLGS	equ	0540Eh	; MCR flags
$MVTBL	equ	05411h	; ptr to head of mounted device list
$PHYDV	equ	053E1h	; ptr to head of physical device list
$PLIST	equ	053E5h	; ptr to list of partitions
$REMTK	equ	030C1h	; remove task from STD
$RLIST	equ	053EBh	; ptr to head of ready tasks list
$RNDC	equ	053F7h	; round-robin interval in ticks
$RNDH	equ	053F9h	; highest priority for round-robin scheduling
$RNDL	equ	053FAh	; lowest priority for round-robin scheduling
$SCRBF	equ	05413h	; scratch buffer address
$SWPC	equ	053FCh	; swapping interval in ticks
$SWPCT	equ	053FDh	; swapping interval counter
$SWPRI	equ	053FBh	; priority range for swapping
$TLIST	equ	053E9h	; ptr to head of installed tasks list
$UNFTK	equ	030D3h	; unfix task
$WLIST	equ	053EDh	; ptr to head of waiting tasks list
BUFFER	equ	05425h	; ptr to file I/O buffer area
IODONE	equ	01D7Dh	; end I/O processing
ITBL	equ	0F481h	; space for interrupt table
ITBLP	equ	0F47Fh	; interrupt table pointer
LDCKR	equ	00AC6h	; resume task after checkpoint read
LDCKW	equ	00AF8h	; queue task to partition after chkpnt write
LDGO	equ	00A37h	; start task after load
LDRTCB	equ	05400h	; LDR... TCB
MCRTCB	equ	053FEh	; MCR... TCB
M_EPT	equ	0F7C5h	; debugger-monitor normal entry point
NVOK	equ	04EB7h	; P112 NV RAM OK flag
NVRAM	equ	04E9Fh	; P112 NV RAM contents
POOL	equ	053DDh	; ptr to start of pool area
POOLSZ	equ	053DBh	; size of pool area
SCBAR	equ	0F47Eh	; supervisor mode CBAR value
SETFLG	equ	01242h	; set task's event flag
SFLAGS	equ	05406h	; system flags
SWSTK	equ	05427h	; stub to call kernel routines
SYSBBR	equ	0F47Bh	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	053C7h	; start of system data area
SYSEND	equ	05470h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSTOP	equ	053D9h	; top of pool area
SYSVER	equ	053CDh	; system version number
TICCNT	equ	0F470h	; absolute time count in ticks
TICSEC	equ	0F46Fh	; ticks per second
TKILL	equ	00C82h	; abort task
TM_EPT	equ	0FA63h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E5h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Dh	; user mode CBAR value
UCBNAM	equ	016D4h	; get device name from UCB
UGETB	equ	0F3B1h	; inter-bank get byte routine
UGETBB	equ	0F41Ah	; inter-bank get byte routine
UGETWB	equ	0F451h	; inter-bank get word routine
UPTIME	equ	0F474h	; system up time (ticks and seconds)
UPUTB	equ	0F3D5h	; inter-bank put byte routine
UPUTBB	equ	0F3FDh	; inter-bank put byte routine
UPUTWB	equ	0F433h	; inter-bank put word routine
USRBBR	equ	0F47Ch	; BBR of current executing task
