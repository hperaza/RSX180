$ALLOC	equ	01A27h	; allocate pool memory
$ALUN	equ	01611h	; assign LUN to device
$ASGN	equ	01481h	; assign logical name to physical device
$ASNTP	equ	026B4h	; assign next task to partition
$CHKPT	equ	0289Ch	; initiate task checkpoint
$CLASN	equ	014FBh	; delete all logical dev assignments of the given type
$CLIST	equ	0549Ch	; list of CLI control blocks
$CLKQ	equ	0549Ah	; ptr to head of clock queue
$CONN	equ	01793h	; connect to task
$CPCB	equ	05498h	; address of PCB of current task
$CPLST	equ	0548Eh	; ptr to head of checkpoint PCB list
$CTCB	equ	05496h	; address of TCB of current task
$DEASN	equ	014E4h	; delete logical device assignment
$ERSEQ	equ	054A9h	; error sequence number
$FCBS	equ	054C8h	; ptr to head of FCB list
$FEAT	equ	0547Fh	; feature bits
$FIXTK	equ	0315Bh	; fix task in memory
$FNDEV	equ	0153Ch	; find device and get UCB address
$FNPAR	equ	0265Ch	; find partition by name
$FNTCB	equ	010BDh	; find TCB by name
$FNTSK	equ	01092h	; find task by name
$FORKQ	equ	054B4h	; pointer to list of fork blocks
$FREE	equ	01A86h	; free pool memory
$GTUCB	equ	015FCh	; get UCB address
$HOSTN	equ	05476h	; host/node name
$IOEND	equ	01DCDh	; end I/O processing for ASTs
$LGOUT	equ	01745h	; logout user
$LKTCB	equ	008BBh	; link TCB to the specified list
$LOGDV	equ	0548Ah	; ptr to head of logical device assignment list
$LOGIN	equ	016DCh	; login user
$MCOPY	equ	0F22Eh	; inter-bank memory copy routine
$MEMSZ	equ	05486h	; total memory size
$MFLGS	equ	054B3h	; MCR flags
$MVTBL	equ	054B6h	; ptr to head of mounted device list
$PHYDV	equ	05488h	; ptr to head of physical device list
$PLIST	equ	0548Ch	; ptr to list of partitions
$REMTK	equ	03152h	; remove task from STD
$RLIST	equ	05492h	; ptr to head of ready tasks list
$RNDC	equ	0549Eh	; round-robin interval in ticks
$RNDH	equ	054A0h	; highest priority for round-robin scheduling
$RNDL	equ	054A1h	; lowest priority for round-robin scheduling
$SCRBF	equ	054B8h	; scratch buffer address
$SWPC	equ	054A3h	; swapping interval in ticks
$SWPCT	equ	054A4h	; swapping interval counter
$SWPRI	equ	054A2h	; priority range for swapping
$TLIST	equ	05490h	; ptr to head of installed tasks list
$UNFTK	equ	03164h	; unfix task
$WLIST	equ	05494h	; ptr to head of waiting tasks list
BUFFER	equ	054CAh	; ptr to file I/O buffer area
IODONE	equ	01DA7h	; end I/O processing
ITBL	equ	0F481h	; space for interrupt table
ITBLP	equ	0F47Fh	; interrupt table pointer
LDCKR	equ	00ABBh	; resume task after checkpoint read
LDCKW	equ	00AEDh	; queue task to partition after chkpnt write
LDGO	equ	00A2Ch	; start task after load
LDRTCB	equ	054A7h	; LDR... TCB
MCRTCB	equ	054A5h	; MCR... TCB
M_EPT	equ	0F7C5h	; debugger-monitor normal entry point
NVOK	equ	04F5Eh	; P112 NV RAM OK flag
NVRAM	equ	04F46h	; P112 NV RAM contents
POOL	equ	05484h	; ptr to start of pool area
POOLSZ	equ	05482h	; size of pool area
SCBAR	equ	0F47Eh	; supervisor mode CBAR value
SETFLG	equ	01237h	; set task's event flag
SFLAGS	equ	054ABh	; system flags
SWSTK	equ	054CCh	; stub to call kernel routines
SYSBBR	equ	0F47Bh	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0546Eh	; start of system data area
SYSEND	equ	05515h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSTOP	equ	05480h	; top of pool area
SYSVER	equ	05474h	; system version number
TICCNT	equ	0F470h	; absolute time count in ticks
TICSEC	equ	0F46Fh	; ticks per second
TKILL	equ	00C77h	; abort task
TM_EPT	equ	0FA63h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E5h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Dh	; user mode CBAR value
UCBNAM	equ	016C9h	; get device name from UCB
UGETB	equ	0F3B1h	; inter-bank get byte routine
UGETBB	equ	0F41Ah	; inter-bank get byte routine
UGETWB	equ	0F451h	; inter-bank get word routine
UPTIME	equ	0F474h	; system up time (ticks and seconds)
UPUTB	equ	0F3D5h	; inter-bank put byte routine
UPUTBB	equ	0F3FDh	; inter-bank put byte routine
UPUTWB	equ	0F433h	; inter-bank put word routine
USRBBR	equ	0F47Ch	; BBR of current executing task
