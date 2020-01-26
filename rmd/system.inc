$ALLOC	equ	019BFh	; allocate pool memory
$ALUN	equ	015D2h	; assign LUN to device
$ASGN	equ	01432h	; assign logical name to physical device
$ASNTP	equ	02785h	; assign next task to partition
$CHKPT	equ	0296Dh	; initiate task checkpoint
$CLASN	equ	014ACh	; delete all logical dev assignments of the given type
$CLIST	equ	05659h	; list of CLI control blocks
$CLKQ	equ	05657h	; ptr to head of clock queue
$CONN	equ	0173Fh	; connect to task
$CPCB	equ	05655h	; address of PCB of current task
$CPLST	equ	0564Bh	; ptr to head of checkpoint PCB list
$CTCB	equ	05653h	; address of TCB of current task
$DEASN	equ	01495h	; delete logical device assignment
$ERSEQ	equ	05666h	; error sequence number
$FEAT	equ	0563Ch	; feature bits
$FILBF	equ	05685h	; ptr to file I/O buffer area
$FIXTK	equ	0329Bh	; fix task in memory
$FNDEV	equ	014EDh	; find device and get UCB address
$FNPAR	equ	0272Dh	; find partition by name
$FNTCB	equ	01095h	; find TCB by name
$FNTSK	equ	0106Ah	; find task by name
$FORKQ	equ	05671h	; pointer to list of fork blocks
$FREE	equ	01A1Eh	; free pool memory
$GTUCB	equ	015BDh	; get UCB address
$HOSTN	equ	05633h	; host/node name
$IOEND	equ	01D69h	; end I/O processing for ASTs
$LGOUT	equ	0170Ah	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	05647h	; ptr to head of logical device assignment list
$LOGIN	equ	016A1h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05643h	; total memory size
$MFLGS	equ	05670h	; MCR flags
$MVTBL	equ	05673h	; ptr to head of mounted device list
$PHYDV	equ	05645h	; ptr to head of physical device list
$PLIST	equ	05649h	; ptr to list of partitions
$REDIR	equ	0153Ch	; follow UCB redirection links
$REMTK	equ	03292h	; remove task from STD
$RLIST	equ	0564Fh	; ptr to head of ready tasks list
$RNDC	equ	0565Bh	; round-robin interval in ticks
$RNDH	equ	0565Dh	; highest priority for round-robin scheduling
$RNDL	equ	0565Eh	; lowest priority for round-robin scheduling
$SCRBF	equ	05675h	; scratch buffer address
$SWPC	equ	05660h	; swapping interval in ticks
$SWPCT	equ	05661h	; swapping interval counter
$SWPRI	equ	0565Fh	; priority range for swapping
$TLIST	equ	0564Dh	; ptr to head of installed tasks list
$UCBDN	equ	0168Ah	; get device name and unit from UCB
$UNFTK	equ	032A4h	; unfix task
$WLIST	equ	05651h	; ptr to head of waiting tasks list
IODONE	equ	01D43h	; end I/O processing
LDCKR	equ	00A93h	; resume task after checkpoint read
LDCKW	equ	00AC5h	; queue task to partition after chkpnt write
LDGO	equ	00A04h	; start task after load
LDRTCB	equ	05664h	; LDR... TCB
MCRTCB	equ	05662h	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	05083h	; P112 NV RAM OK flag
NVRAM	equ	0506Bh	; P112 NV RAM contents
POOL	equ	05641h	; ptr to start of pool area
POOLSZ	equ	0563Fh	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	0120Fh	; set task's event flag
SFLAGS	equ	05668h	; system flags
SWSTK	equ	05687h	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0562Bh	; start of system data area
SYSEND	equ	056D0h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	0563Dh	; top of pool area
SYSVER	equ	05631h	; system version number
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
