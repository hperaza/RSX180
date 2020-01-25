$ALLOC	equ	019CBh	; allocate pool memory
$ALUN	equ	015E2h	; assign LUN to device
$ASGN	equ	01442h	; assign logical name to physical device
$ASNTP	equ	0278Dh	; assign next task to partition
$CHKPT	equ	02975h	; initiate task checkpoint
$CLASN	equ	014BCh	; delete all logical dev assignments of the given type
$CLIST	equ	0565Eh	; list of CLI control blocks
$CLKQ	equ	0565Ch	; ptr to head of clock queue
$CONN	equ	0174Fh	; connect to task
$CPCB	equ	0565Ah	; address of PCB of current task
$CPLST	equ	05650h	; ptr to head of checkpoint PCB list
$CTCB	equ	05658h	; address of TCB of current task
$DEASN	equ	014A5h	; delete logical device assignment
$ERSEQ	equ	0566Bh	; error sequence number
$FCBS	equ	0568Ah	; ptr to head of FCB list
$FEAT	equ	05641h	; feature bits
$FIXTK	equ	032A4h	; fix task in memory
$FNDEV	equ	014FDh	; find device and get UCB address
$FNPAR	equ	02735h	; find partition by name
$FNTCB	equ	010A5h	; find TCB by name
$FNTSK	equ	0107Ah	; find task by name
$FORKQ	equ	05676h	; pointer to list of fork blocks
$FREE	equ	01A2Ah	; free pool memory
$GTUCB	equ	015CDh	; get UCB address
$HOSTN	equ	05638h	; host/node name
$IOEND	equ	01D75h	; end I/O processing for ASTs
$LGOUT	equ	0171Ah	; logout user
$LKTCB	equ	008ADh	; link TCB to the specified list
$LOGDV	equ	0564Ch	; ptr to head of logical device assignment list
$LOGIN	equ	016B1h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05648h	; total memory size
$MFLGS	equ	05675h	; MCR flags
$MVTBL	equ	05678h	; ptr to head of mounted device list
$PHYDV	equ	0564Ah	; ptr to head of physical device list
$PLIST	equ	0564Eh	; ptr to list of partitions
$REDIR	equ	0154Ch	; follow UCB redirection links
$REMTK	equ	0329Bh	; remove task from STD
$RLIST	equ	05654h	; ptr to head of ready tasks list
$RNDC	equ	05660h	; round-robin interval in ticks
$RNDH	equ	05662h	; highest priority for round-robin scheduling
$RNDL	equ	05663h	; lowest priority for round-robin scheduling
$SCRBF	equ	0567Ah	; scratch buffer address
$SWPC	equ	05665h	; swapping interval in ticks
$SWPCT	equ	05666h	; swapping interval counter
$SWPRI	equ	05664h	; priority range for swapping
$TLIST	equ	05652h	; ptr to head of installed tasks list
$UCBDN	equ	0169Ah	; get device name and unit from UCB
$UNFTK	equ	032ADh	; unfix task
$WLIST	equ	05656h	; ptr to head of waiting tasks list
BUFFER	equ	0568Ch	; ptr to file I/O buffer area
IODONE	equ	01D4Fh	; end I/O processing
ITBL	equ	0F45Eh	; space for interrupt table
ITBLP	equ	0F45Ch	; interrupt table pointer
LDCKR	equ	00AA3h	; resume task after checkpoint read
LDCKW	equ	00AD5h	; queue task to partition after chkpnt write
LDGO	equ	00A14h	; start task after load
LDRTCB	equ	05669h	; LDR... TCB
MCRTCB	equ	05667h	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	05088h	; P112 NV RAM OK flag
NVRAM	equ	05070h	; P112 NV RAM contents
POOL	equ	05646h	; ptr to start of pool area
POOLSZ	equ	05644h	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	0121Fh	; set task's event flag
SFLAGS	equ	0566Dh	; system flags
SWSTK	equ	0568Eh	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05630h	; start of system data area
SYSEND	equ	056D7h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05642h	; top of pool area
SYSVER	equ	05636h	; system version number
TICCNT	equ	0F44Dh	; absolute time count in ticks
TICSEC	equ	0F44Ch	; ticks per second
TKILL	equ	00C5Fh	; abort task
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
