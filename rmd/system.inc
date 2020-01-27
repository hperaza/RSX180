$ALLOC	equ	019BFh	; allocate pool memory
$ALUN	equ	015D2h	; assign LUN to device
$ASGN	equ	01432h	; assign logical name to physical device
$ASNTP	equ	02790h	; assign next task to partition
$CHKPT	equ	02978h	; initiate task checkpoint
$CLASN	equ	014ACh	; delete all logical dev assignments of the given type
$CLIST	equ	05677h	; list of CLI control blocks
$CLKQ	equ	05675h	; ptr to head of clock queue
$CONN	equ	0173Fh	; connect to task
$CPCB	equ	05673h	; address of PCB of current task
$CPLST	equ	05669h	; ptr to head of checkpoint PCB list
$CTCB	equ	05671h	; address of TCB of current task
$DEASN	equ	01495h	; delete logical device assignment
$ERSEQ	equ	05684h	; error sequence number
$FEAT	equ	0565Ah	; feature bits
$FILBF	equ	056A3h	; ptr to file I/O buffer area
$FIXTK	equ	032A6h	; fix task in memory
$FNDEV	equ	014EDh	; find device and get UCB address
$FNPAR	equ	02738h	; find partition by name
$FNTCB	equ	01095h	; find TCB by name
$FNTSK	equ	0106Ah	; find task by name
$FORKQ	equ	0568Fh	; pointer to list of fork blocks
$FREE	equ	01A1Eh	; free pool memory
$GTUCB	equ	015BDh	; get UCB address
$HOSTN	equ	05651h	; host/node name
$IOEND	equ	01D69h	; end I/O processing for ASTs
$LGOUT	equ	0170Ah	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	05665h	; ptr to head of logical device assignment list
$LOGIN	equ	016A1h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05661h	; total memory size
$MFLGS	equ	0568Eh	; MCR flags
$MVTBL	equ	05691h	; ptr to head of mounted device list
$PHYDV	equ	05663h	; ptr to head of physical device list
$PLIST	equ	05667h	; ptr to list of partitions
$REDIR	equ	0153Ch	; follow UCB redirection links
$REMTK	equ	0329Dh	; remove task from STD
$RLIST	equ	0566Dh	; ptr to head of ready tasks list
$RNDC	equ	05679h	; round-robin interval in ticks
$RNDH	equ	0567Bh	; highest priority for round-robin scheduling
$RNDL	equ	0567Ch	; lowest priority for round-robin scheduling
$SCRBF	equ	05693h	; scratch buffer address
$SWPC	equ	0567Eh	; swapping interval in ticks
$SWPCT	equ	0567Fh	; swapping interval counter
$SWPRI	equ	0567Dh	; priority range for swapping
$TLIST	equ	0566Bh	; ptr to head of installed tasks list
$UCBDN	equ	0168Ah	; get device name and unit from UCB
$UNFTK	equ	032AFh	; unfix task
$WLIST	equ	0566Fh	; ptr to head of waiting tasks list
IODONE	equ	01D43h	; end I/O processing
LDCKR	equ	00A93h	; resume task after checkpoint read
LDCKW	equ	00AC5h	; queue task to partition after chkpnt write
LDGO	equ	00A04h	; start task after load
LDRTCB	equ	05682h	; LDR... TCB
MCRTCB	equ	05680h	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	0509Dh	; P112 NV RAM OK flag
NVRAM	equ	05085h	; P112 NV RAM contents
POOL	equ	0565Fh	; ptr to start of pool area
POOLSZ	equ	0565Dh	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	0120Fh	; set task's event flag
SFLAGS	equ	05686h	; system flags
SWSTK	equ	056A5h	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05649h	; start of system data area
SYSEND	equ	056EEh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	0565Bh	; top of pool area
SYSVER	equ	0564Fh	; system version number
TICCNT	equ	0F44Dh	; absolute time count in ticks
TICSEC	equ	0F44Ch	; ticks per second
TKILL	equ	00C4Fh	; abort task
TM_EPT	equ	0FA40h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F45Ah	; user mode CBAR value
UGETB	equ	0F38Eh	; inter-bank get byte routine
UGETBB	equ	0F3F7h	; inter-bank get byte routine
UGETWB	equ	0F42Eh	; inter-bank get word routine
UPTIME	equ	0F451h	; system up time (ticks and seconds)
UPUTB	equ	0F3B2h	; inter-bank put byte routine
UPUTBB	equ	0F3DAh	; inter-bank put byte routine
UPUTWB	equ	0F410h	; inter-bank put word routine
USRBBR	equ	0F459h	; BBR of current executing task
