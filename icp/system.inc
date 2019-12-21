$ALLOC	equ	018BEh	; allocate pool memory
$ALUN	equ	014DDh	; assign LUN to device
$ASGN	equ	0134Dh	; assign logical name to physical device
$CHKPT	equ	02632h	; initiate task checkpoint
$CLASN	equ	013C7h	; delete all logical dev assignments of the given type
$CLIST	equ	050C9h	; list of CLI control blocks
$CLKQ	equ	050C7h	; ptr to head of clock queue
$CONN	equ	0165Fh	; connect to task
$CPCB	equ	050C5h	; address of PCB of current task
$CPLST	equ	050BBh	; ptr to head of checkpoint PCB list
$CTCB	equ	050C3h	; address of TCB of current task
$DEASN	equ	013B0h	; delete logical device assignment
$ERSEQ	equ	050D3h	; error sequence number
$FCBS	equ	050F2h	; ptr to head of FCB list
$FEAT	equ	050ACh	; feature bits
$FIXTK	equ	02DA2h	; fix task in memory
$FNDEV	equ	01408h	; find device and get UCB address
$FNPAR	equ	0246Ch	; find partition by name
$FNTCB	equ	00F92h	; find TCB by name
$FNTSK	equ	00F67h	; find task by name
$FORKQ	equ	050DEh	; pointer to list of fork blocks
$FREE	equ	0191Dh	; free pool memory
$GTUCB	equ	014C8h	; get UCB address
$HOSTN	equ	050A3h	; host/node name
$IOEND	equ	01C64h	; end I/O processing for ASTs
$LGOUT	equ	01611h	; logout user
$LKTCB	equ	0083Ch	; link TCB to the specified list
$LOGDV	equ	050B7h	; ptr to head of logical device assignment list
$LOGIN	equ	015A8h	; login user
$MCOPY	equ	0F226h	; inter-bank memory copy routine
$MEMSZ	equ	050B3h	; total memory size
$MFLGS	equ	050DDh	; MCR flags
$MVTBL	equ	050E0h	; ptr to head of mounted device list
$PHYDV	equ	050B5h	; ptr to head of physical device list
$PLIST	equ	050B9h	; ptr to list of partitions
$REMTK	equ	02D99h	; remove task from STD
$RLIST	equ	050BFh	; ptr to head of ready tasks list
$RNDC	equ	050CBh	; round-robin interval in ticks
$SCRBF	equ	050E2h	; scratch buffer address
$TLIST	equ	050BDh	; ptr to head of installed tasks list
$UNFTK	equ	02DABh	; unfix task
$WLIST	equ	050C1h	; ptr to head of waiting tasks list
BUFFER	equ	050F4h	; ptr to file I/O buffer area
IODONE	equ	01C3Eh	; end I/O processing
ITBL	equ	0F479h	; space for interrupt table
ITBLP	equ	0F477h	; interrupt table pointer
LDRTCB	equ	050CFh	; LDR... TCB
MCRTCB	equ	050CDh	; MCR... TCB
M_EPT	equ	0F7BDh	; debugger-monitor normal entry point
NVOK	equ	04B8Bh	; P112 NV RAM OK flag
NVRAM	equ	04B73h	; P112 NV RAM contents
POOL	equ	050B1h	; ptr to start of pool area
POOLSZ	equ	050AFh	; size of pool area
SCBAR	equ	0F476h	; supervisor mode CBAR value
SETFLG	equ	0110Dh	; set task's event flag
SFLAGS	equ	050D5h	; system flags
SWSTK	equ	050F6h	; stub to call kernel routines
SYSBBR	equ	0F473h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0509Bh	; start of system data area
SYSEND	equ	0513Fh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0EFh	; current system level
SYSTOP	equ	050ADh	; top of pool area
SYSVER	equ	050A1h	; system version number
TGO	equ	009ADh	; start task after being loaded
TICCNT	equ	0F468h	; absolute time count in ticks
TICSEC	equ	0F467h	; ticks per second
TKILL	equ	00B91h	; abort task
TM_EPT	equ	0FA5Bh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9DDh	; debugger-monitor breakpoint entry point
UCBAR	equ	0F475h	; user mode CBAR value
UCBNAM	equ	01595h	; get device name from UCB
UGETB	equ	0F3A9h	; inter-bank get byte routine
UGETBB	equ	0F412h	; inter-bank get byte routine
UGETWB	equ	0F449h	; inter-bank get word routine
UPTIME	equ	0F46Ch	; system up time (ticks and seconds)
UPUTB	equ	0F3CDh	; inter-bank put byte routine
UPUTBB	equ	0F3F5h	; inter-bank put byte routine
UPUTWB	equ	0F42Bh	; inter-bank put word routine
USRBBR	equ	0F474h	; BBR of current executing task
