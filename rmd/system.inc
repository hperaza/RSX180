$ALLOC	equ	019C9h	; allocate pool memory
$ALUN	equ	015DCh	; assign LUN to device
$ASGN	equ	0143Ch	; assign logical name to physical device
$ASNTP	equ	0279Fh	; assign next task to partition
$CHKPT	equ	02987h	; initiate task checkpoint
$CLASN	equ	014B6h	; delete all logical dev assignments of the given type
$CLIST	equ	056D2h	; list of CLI control blocks
$CLKQ	equ	056D0h	; ptr to head of clock queue
$CONN	equ	01749h	; connect to task
$CPCB	equ	056CEh	; address of PCB of current task
$CPLST	equ	056C4h	; ptr to head of checkpoint PCB list
$CTCB	equ	056CCh	; address of TCB of current task
$DEASN	equ	0149Fh	; delete logical device assignment
$ERSEQ	equ	056DFh	; error sequence number
$FEAT	equ	056B5h	; feature bits
$FILBF	equ	056FEh	; ptr to file I/O buffer area
$FIXTK	equ	032C6h	; fix task in memory
$FNDEV	equ	014F7h	; find device and get UCB address
$FNPAR	equ	02747h	; find partition by name
$FNTCB	equ	0109Fh	; find TCB by name
$FNTSK	equ	01074h	; find task by name
$FORKQ	equ	056EAh	; pointer to list of fork blocks
$FREE	equ	01A28h	; free pool memory
$GTUCB	equ	015C7h	; get UCB address
$HOSTN	equ	056ACh	; host/node name
$IOEND	equ	01D73h	; end I/O processing for ASTs
$LGOUT	equ	01714h	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	056C0h	; ptr to head of logical device assignment list
$LOGIN	equ	016ABh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	056BCh	; total memory size
$MFLGS	equ	056E9h	; MCR flags
$MVTBL	equ	056ECh	; ptr to head of mounted device list
$PHYDV	equ	056BEh	; ptr to head of physical device list
$PLIST	equ	056C2h	; ptr to list of partitions
$REDIR	equ	01546h	; follow UCB redirection links
$REMTK	equ	032BDh	; remove task from STD
$RLIST	equ	056C8h	; ptr to head of ready tasks list
$RNDC	equ	056D4h	; round-robin interval in ticks
$RNDH	equ	056D6h	; highest priority for round-robin scheduling
$RNDL	equ	056D7h	; lowest priority for round-robin scheduling
$SCRBF	equ	056EEh	; scratch buffer address
$SWPC	equ	056D9h	; swapping interval in ticks
$SWPCT	equ	056DAh	; swapping interval counter
$SWPRI	equ	056D8h	; priority range for swapping
$TLIST	equ	056C6h	; ptr to head of installed tasks list
$UCBDN	equ	01694h	; get device name and unit from UCB
$UNFTK	equ	032CFh	; unfix task
$WLIST	equ	056CAh	; ptr to head of waiting tasks list
IODONE	equ	01D4Dh	; end I/O processing
LDCKR	equ	00A93h	; resume task after checkpoint read
LDCKW	equ	00AC5h	; queue task to partition after chkpnt write
LDGO	equ	00A04h	; start task after load
LDRTCB	equ	056DDh	; LDR... TCB
MCRTCB	equ	056DBh	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	050F8h	; P112 NV RAM OK flag
NVRAM	equ	050E0h	; P112 NV RAM contents
POOL	equ	056BAh	; ptr to start of pool area
POOLSZ	equ	056B8h	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	01219h	; set task's event flag
SFLAGS	equ	056E1h	; system flags
SWSTK	equ	05700h	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	056A4h	; start of system data area
SYSEND	equ	05749h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	056B6h	; top of pool area
SYSVER	equ	056AAh	; system version number
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
