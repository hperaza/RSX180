$ALLOC	equ	019E2h	; allocate pool memory
$ALUN	equ	015E4h	; assign LUN to device
$ASGN	equ	01454h	; assign logical name to physical device
$ASNTP	equ	0279Fh	; assign next task to partition
$CHKPT	equ	02987h	; initiate task checkpoint
$CLASN	equ	014CEh	; delete all logical dev assignments of the given type
$CLIST	equ	054FBh	; list of CLI control blocks
$CLKQ	equ	054F9h	; ptr to head of clock queue
$CONN	equ	01766h	; connect to task
$CPCB	equ	054F7h	; address of PCB of current task
$CPLST	equ	054EDh	; ptr to head of checkpoint PCB list
$CTCB	equ	054F5h	; address of TCB of current task
$DEASN	equ	014B7h	; delete logical device assignment
$ERSEQ	equ	05508h	; error sequence number
$FCBS	equ	05527h	; ptr to head of FCB list
$FEAT	equ	054DEh	; feature bits
$FIXTK	equ	03232h	; fix task in memory
$FNDEV	equ	0150Fh	; find device and get UCB address
$FNPAR	equ	02747h	; find partition by name
$FNTCB	equ	010B7h	; find TCB by name
$FNTSK	equ	0108Ch	; find task by name
$FORKQ	equ	05513h	; pointer to list of fork blocks
$FREE	equ	01A41h	; free pool memory
$GTUCB	equ	015CFh	; get UCB address
$HOSTN	equ	054D5h	; host/node name
$IOEND	equ	01D88h	; end I/O processing for ASTs
$LGOUT	equ	01718h	; logout user
$LKTCB	equ	008BBh	; link TCB to the specified list
$LOGDV	equ	054E9h	; ptr to head of logical device assignment list
$LOGIN	equ	016AFh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	054E5h	; total memory size
$MFLGS	equ	05512h	; MCR flags
$MVTBL	equ	05515h	; ptr to head of mounted device list
$PHYDV	equ	054E7h	; ptr to head of physical device list
$PLIST	equ	054EBh	; ptr to list of partitions
$REMTK	equ	03229h	; remove task from STD
$RLIST	equ	054F1h	; ptr to head of ready tasks list
$RNDC	equ	054FDh	; round-robin interval in ticks
$RNDH	equ	054FFh	; highest priority for round-robin scheduling
$RNDL	equ	05500h	; lowest priority for round-robin scheduling
$SCRBF	equ	05517h	; scratch buffer address
$SWPC	equ	05502h	; swapping interval in ticks
$SWPCT	equ	05503h	; swapping interval counter
$SWPRI	equ	05501h	; priority range for swapping
$TLIST	equ	054EFh	; ptr to head of installed tasks list
$UNFTK	equ	0323Bh	; unfix task
$WLIST	equ	054F3h	; ptr to head of waiting tasks list
BUFFER	equ	05529h	; ptr to file I/O buffer area
IODONE	equ	01D62h	; end I/O processing
ITBL	equ	0F45Eh	; space for interrupt table
ITBLP	equ	0F45Ch	; interrupt table pointer
LDCKR	equ	00AB5h	; resume task after checkpoint read
LDCKW	equ	00AE7h	; queue task to partition after chkpnt write
LDGO	equ	00A26h	; start task after load
LDRTCB	equ	05506h	; LDR... TCB
MCRTCB	equ	05504h	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	04F8Dh	; P112 NV RAM OK flag
NVRAM	equ	04F75h	; P112 NV RAM contents
POOL	equ	054E3h	; ptr to start of pool area
POOLSZ	equ	054E1h	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	01231h	; set task's event flag
SFLAGS	equ	0550Ah	; system flags
SWSTK	equ	0552Bh	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	054CDh	; start of system data area
SYSEND	equ	05574h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	054DFh	; top of pool area
SYSVER	equ	054D3h	; system version number
TICCNT	equ	0F44Dh	; absolute time count in ticks
TICSEC	equ	0F44Ch	; ticks per second
TKILL	equ	00C71h	; abort task
TM_EPT	equ	0FA40h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F45Ah	; user mode CBAR value
UCBNAM	equ	0169Ch	; get device name from UCB
UGETB	equ	0F38Eh	; inter-bank get byte routine
UGETBB	equ	0F3F7h	; inter-bank get byte routine
UGETWB	equ	0F42Eh	; inter-bank get word routine
UPTIME	equ	0F451h	; system up time (ticks and seconds)
UPUTB	equ	0F3B2h	; inter-bank put byte routine
UPUTBB	equ	0F3DAh	; inter-bank put byte routine
UPUTWB	equ	0F410h	; inter-bank put word routine
USRBBR	equ	0F459h	; BBR of current executing task
