$ALLOC	equ	01A32h	; allocate pool memory
$ALUN	equ	0161Ch	; assign LUN to device
$ASGN	equ	0148Ch	; assign logical name to physical device
$CHKPT	equ	0288Bh	; initiate task checkpoint
$CLASN	equ	01506h	; delete all logical dev assignments of the given type
$CLIST	equ	05475h	; list of CLI control blocks
$CLKQ	equ	05473h	; ptr to head of clock queue
$CONN	equ	0179Eh	; connect to task
$CPCB	equ	05471h	; address of PCB of current task
$CPLST	equ	05467h	; ptr to head of checkpoint PCB list
$CTCB	equ	0546Fh	; address of TCB of current task
$DEASN	equ	014EFh	; delete logical device assignment
$ERSEQ	equ	05484h	; error sequence number
$FCBS	equ	054A3h	; ptr to head of FCB list
$FEAT	equ	05458h	; feature bits
$FIXTK	equ	0314Ah	; fix task in memory
$FNDEV	equ	01547h	; find device and get UCB address
$FNPAR	equ	0265Dh	; find partition by name
$FNTCB	equ	010C8h	; find TCB by name
$FNTSK	equ	0109Dh	; find task by name
$FORKQ	equ	0548Fh	; pointer to list of fork blocks
$FREE	equ	01A91h	; free pool memory
$GTUCB	equ	01607h	; get UCB address
$HOSTN	equ	0544Fh	; host/node name
$IOEND	equ	01DD8h	; end I/O processing for ASTs
$LGOUT	equ	01750h	; logout user
$LKTCB	equ	008C6h	; link TCB to the specified list
$LOGDV	equ	05463h	; ptr to head of logical device assignment list
$LOGIN	equ	016E7h	; login user
$MCOPY	equ	0F22Eh	; inter-bank memory copy routine
$MEMSZ	equ	0545Fh	; total memory size
$MFLGS	equ	0548Eh	; MCR flags
$MVTBL	equ	05491h	; ptr to head of mounted device list
$PHYDV	equ	05461h	; ptr to head of physical device list
$PLIST	equ	05465h	; ptr to list of partitions
$REMTK	equ	03141h	; remove task from STD
$RLIST	equ	0546Bh	; ptr to head of ready tasks list
$RNDC	equ	05477h	; round-robin interval in ticks
$RNDH	equ	05479h	; highest priority for round-robin scheduling
$RNDL	equ	0547Ah	; lowest priority for round-robin scheduling
$SCRBF	equ	05493h	; scratch buffer address
$SWPC	equ	0547Ch	; swapping interval in ticks
$SWPCT	equ	0547Dh	; swapping interval counter
$SWPRI	equ	0547Bh	; priority range for swapping
$TLIST	equ	05469h	; ptr to head of installed tasks list
$UNFTK	equ	03153h	; unfix task
$WLIST	equ	0546Dh	; ptr to head of waiting tasks list
BUFFER	equ	054A5h	; ptr to file I/O buffer area
IODONE	equ	01DB2h	; end I/O processing
ITBL	equ	0F481h	; space for interrupt table
ITBLP	equ	0F47Fh	; interrupt table pointer
LDCKR	equ	00AC6h	; resume task after checkpoint read
LDCKW	equ	00AF8h	; queue task to partition after chkpnt write
LDGO	equ	00A37h	; start task after load
LDRTCB	equ	05480h	; LDR... TCB
MCRTCB	equ	0547Eh	; MCR... TCB
M_EPT	equ	0F7C5h	; debugger-monitor normal entry point
NVOK	equ	04F37h	; P112 NV RAM OK flag
NVRAM	equ	04F1Fh	; P112 NV RAM contents
POOL	equ	0545Dh	; ptr to start of pool area
POOLSZ	equ	0545Bh	; size of pool area
SCBAR	equ	0F47Eh	; supervisor mode CBAR value
SETFLG	equ	01242h	; set task's event flag
SFLAGS	equ	05486h	; system flags
SWSTK	equ	054A7h	; stub to call kernel routines
SYSBBR	equ	0F47Bh	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05447h	; start of system data area
SYSEND	equ	054F0h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSTOP	equ	05459h	; top of pool area
SYSVER	equ	0544Dh	; system version number
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
