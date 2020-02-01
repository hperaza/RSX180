$ALLOC	equ	019CFh	; allocate pool memory
$ALUN	equ	015E2h	; assign LUN to device
$ASGN	equ	01442h	; assign logical name to physical device
$ASNTP	equ	027A5h	; assign next task to partition
$CHKPT	equ	0298Dh	; initiate task checkpoint
$CLASN	equ	014BCh	; delete all logical dev assignments of the given type
$CLIST	equ	056D8h	; list of CLI control blocks
$CLKQ	equ	056D6h	; ptr to head of clock queue
$CONN	equ	0174Fh	; connect to task
$CPCB	equ	056D4h	; address of PCB of current task
$CPLST	equ	056CAh	; ptr to head of checkpoint PCB list
$CTCB	equ	056D2h	; address of TCB of current task
$DEASN	equ	014A5h	; delete logical device assignment
$ERSEQ	equ	056E5h	; error sequence number
$FEAT	equ	056BBh	; feature bits
$FILBF	equ	05704h	; ptr to file I/O buffer area
$FIXTK	equ	032CCh	; fix task in memory
$FNDEV	equ	014FDh	; find device and get UCB address
$FNPAR	equ	0274Dh	; find partition by name
$FNTCB	equ	010A5h	; find TCB by name
$FNTSK	equ	0107Ah	; find task by name
$FORKQ	equ	056F0h	; pointer to list of fork blocks
$FREE	equ	01A2Eh	; free pool memory
$GTUCB	equ	015CDh	; get UCB address
$HOSTN	equ	056B2h	; host/node name
$IOEND	equ	01D79h	; end I/O processing for ASTs
$LGOUT	equ	0171Ah	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	056C6h	; ptr to head of logical device assignment list
$LOGIN	equ	016B1h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	056C2h	; total memory size
$MFLGS	equ	056EFh	; MCR flags
$MVTBL	equ	056F2h	; ptr to head of mounted device list
$PHYDV	equ	056C4h	; ptr to head of physical device list
$PLIST	equ	056C8h	; ptr to list of partitions
$REDIR	equ	0154Ch	; follow UCB redirection links
$REMTK	equ	032C3h	; remove task from STD
$RLIST	equ	056CEh	; ptr to head of ready tasks list
$RNDC	equ	056DAh	; round-robin interval in ticks
$RNDH	equ	056DCh	; highest priority for round-robin scheduling
$RNDL	equ	056DDh	; lowest priority for round-robin scheduling
$SCRBF	equ	056F4h	; scratch buffer address
$SWPC	equ	056DFh	; swapping interval in ticks
$SWPCT	equ	056E0h	; swapping interval counter
$SWPRI	equ	056DEh	; priority range for swapping
$TLIST	equ	056CCh	; ptr to head of installed tasks list
$UCBDN	equ	0169Ah	; get device name and unit from UCB
$UNFTK	equ	032D5h	; unfix task
$WLIST	equ	056D0h	; ptr to head of waiting tasks list
IODONE	equ	01D53h	; end I/O processing
LDCKR	equ	00A93h	; resume task after checkpoint read
LDCKW	equ	00AC5h	; queue task to partition after chkpnt write
LDGO	equ	00A04h	; start task after load
LDRTCB	equ	056E3h	; LDR... TCB
MCRTCB	equ	056E1h	; MCR... TCB
M_EPT	equ	0F7A2h	; debugger-monitor normal entry point
NVOK	equ	050FEh	; P112 NV RAM OK flag
NVRAM	equ	050E6h	; P112 NV RAM contents
POOL	equ	056C0h	; ptr to start of pool area
POOLSZ	equ	056BEh	; size of pool area
SCBAR	equ	0F45Bh	; supervisor mode CBAR value
SETFLG	equ	0121Fh	; set task's event flag
SFLAGS	equ	056E7h	; system flags
SWSTK	equ	05706h	; stub to call kernel routines
SYSBBR	equ	0F458h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	056AAh	; start of system data area
SYSEND	equ	0574Fh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	056BCh	; top of pool area
SYSVER	equ	056B0h	; system version number
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
