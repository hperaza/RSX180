$ALLOC	equ	019E4h	; allocate pool memory
$ALUN	equ	015E6h	; assign LUN to device
$ASGN	equ	01446h	; assign logical name to physical device
$ASNTP	equ	027A9h	; assign next task to partition
$CHKPT	equ	02991h	; initiate task checkpoint
$CLASN	equ	014C0h	; delete all logical dev assignments of the given type
$CLIST	equ	05661h	; list of CLI control blocks
$CLKQ	equ	0565Fh	; ptr to head of clock queue
$CONN	equ	01768h	; connect to task
$CPCB	equ	0565Dh	; address of PCB of current task
$CPLST	equ	05653h	; ptr to head of checkpoint PCB list
$CTCB	equ	0565Bh	; address of TCB of current task
$DEASN	equ	014A9h	; delete logical device assignment
$ERSEQ	equ	0566Eh	; error sequence number
$FCBS	equ	0568Dh	; ptr to head of FCB list
$FEAT	equ	05644h	; feature bits
$FIXTK	equ	032A7h	; fix task in memory
$FNDEV	equ	01501h	; find device and get UCB address
$FNPAR	equ	02751h	; find partition by name
$FNTCB	equ	010A9h	; find TCB by name
$FNTSK	equ	0107Eh	; find task by name
$FORKQ	equ	05679h	; pointer to list of fork blocks
$FREE	equ	01A43h	; free pool memory
$GTUCB	equ	015D1h	; get UCB address
$HOSTN	equ	0563Bh	; host/node name
$IOEND	equ	01D8Eh	; end I/O processing for ASTs
$LGOUT	equ	0171Ah	; logout user
$LKTCB	equ	008ADh	; link TCB to the specified list
$LOGDV	equ	0564Fh	; ptr to head of logical device assignment list
$LOGIN	equ	016B1h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	0564Bh	; total memory size
$MFLGS	equ	05678h	; MCR flags
$MVTBL	equ	0567Bh	; ptr to head of mounted device list
$PHYDV	equ	0564Dh	; ptr to head of physical device list
$PLIST	equ	05651h	; ptr to list of partitions
$REDIR	equ	01550h	; follow UCB redirection links
$REMTK	equ	0329Eh	; remove task from STD
$RLIST	equ	05657h	; ptr to head of ready tasks list
$RNDC	equ	05663h	; round-robin interval in ticks
$RNDH	equ	05665h	; highest priority for round-robin scheduling
$RNDL	equ	05666h	; lowest priority for round-robin scheduling
$SCRBF	equ	0567Dh	; scratch buffer address
$SWPC	equ	05668h	; swapping interval in ticks
$SWPCT	equ	05669h	; swapping interval counter
$SWPRI	equ	05667h	; priority range for swapping
$TLIST	equ	05655h	; ptr to head of installed tasks list
$UNFTK	equ	032B0h	; unfix task
$WLIST	equ	05659h	; ptr to head of waiting tasks list
BUFFER	equ	0568Fh	; ptr to file I/O buffer area
IODONE	equ	01D68h	; end I/O processing
ITBL	equ	0F45Eh	; space for interrupt table
ITBLP	equ	0F45Ch	; interrupt table pointer
LDCKR	equ	00AA7h	; resume task after checkpoint read
LDCKW	equ	00AD9h	; queue task to partition after chkpnt write
LDGO	equ	00A18h	; start task after load
LDRTCB	equ	0566Ch	; LDR... TCB
MCRTCB	equ	0566Ah	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	0508Bh	; P112 NV RAM OK flag
NVRAM	equ	05073h	; P112 NV RAM contents
POOL	equ	05649h	; ptr to start of pool area
POOLSZ	equ	05647h	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	01223h	; set task's event flag
SFLAGS	equ	05670h	; system flags
SWSTK	equ	05691h	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05633h	; start of system data area
SYSEND	equ	056DAh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05645h	; top of pool area
SYSVER	equ	05639h	; system version number
TICCNT	equ	0F44Dh	; absolute time count in ticks
TICSEC	equ	0F44Ch	; ticks per second
TKILL	equ	00C63h	; abort task
TM_EPT	equ	0FA40h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F45Ah	; user mode CBAR value
UCBNAM	equ	0169Eh	; get device name from UCB
UGETB	equ	0F38Eh	; inter-bank get byte routine
UGETBB	equ	0F3F7h	; inter-bank get byte routine
UGETWB	equ	0F42Eh	; inter-bank get word routine
UPTIME	equ	0F451h	; system up time (ticks and seconds)
UPUTB	equ	0F3B2h	; inter-bank put byte routine
UPUTBB	equ	0F3DAh	; inter-bank put byte routine
UPUTWB	equ	0F410h	; inter-bank put word routine
USRBBR	equ	0F459h	; BBR of current executing task
