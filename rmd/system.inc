$ALLOC	equ	019D4h	; allocate pool memory
$ALUN	equ	015E3h	; assign LUN to device
$ASGN	equ	01443h	; assign logical name to physical device
$ASNTP	equ	0287Ah	; assign next task to partition
$CHKPT	equ	02A62h	; initiate task checkpoint
$CLASN	equ	014BDh	; delete all logical dev assignments of the given type
$CLIST	equ	05B47h	; list of CLI control blocks
$CLKQ	equ	05B45h	; ptr to head of clock queue
$CONN	equ	01754h	; connect to task
$CPCB	equ	05B43h	; address of PCB of current task
$CPLST	equ	05B39h	; ptr to head of checkpoint PCB list
$CTCB	equ	05B41h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014A6h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05B54h	; error sequence number
$FEAT	equ	05B21h	; feature bits
$FILBF	equ	05B73h	; ptr to file I/O buffer area
$FIXTK	equ	03564h	; fix task in memory
$FNDEV	equ	014FEh	; find device and get UCB address
$FNPAR	equ	02821h	; find partition by name
$FNTCB	equ	01013h	; find TCB by name
$FNTSK	equ	00FE8h	; find task by name
$FORKQ	equ	05B5Fh	; pointer to list of fork blocks
$FREE	equ	01A33h	; free pool memory
$GTUCB	equ	015CEh	; get UCB address
$HOSTN	equ	05B22h	; host/node name
$IOEND	equ	01E04h	; end I/O processing for ASTs
$LDCKR	equ	00AA1h	; resume task after checkpoint read
$LDCKW	equ	00AD3h	; queue task to partition after chkpnt write
$LDGO	equ	00A04h	; start task after load
$LGOUT	equ	0171Fh	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	05B35h	; ptr to head of logical device assignment list
$LOGIN	equ	016B2h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05B31h	; total memory size
$MFLGS	equ	05B5Eh	; MCR flags
$MVTBL	equ	05B61h	; ptr to head of mounted device list
$PHYDV	equ	05B33h	; ptr to head of physical device list
$PLIST	equ	05B37h	; ptr to list of partitions
$POLSZ	equ	05B2Fh	; size of pool area
$POOL	equ	05B2Dh	; ptr to start of pool area
$REDIR	equ	0154Dh	; follow UCB redirection links
$REMTK	equ	0355Bh	; remove task from STD
$RLIST	equ	05B3Dh	; ptr to head of ready tasks list
$RNDC	equ	05B49h	; round-robin interval in ticks
$RNDH	equ	05B4Bh	; highest priority for round-robin scheduling
$RNDL	equ	05B4Ch	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05B63h	; scratch buffer address
$SWPC	equ	05B4Eh	; swapping interval in ticks
$SWPCT	equ	05B4Fh	; swapping interval counter
$SWPRI	equ	05B4Dh	; priority range for swapping
$SWSTK	equ	05B75h	; stub to call kernel routines
$TLIST	equ	05B3Bh	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	0169Bh	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	0356Dh	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05B3Fh	; ptr to head of waiting tasks list
IODONE	equ	01DE1h	; end I/O processing
LDRTCB	equ	05B52h	; LDR... TCB
MCRTCB	equ	05B50h	; MCR... TCB
NVOK	equ	05558h	; P112 NV RAM OK flag
NVRAM	equ	05540h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011A1h	; set task's event flag
SFLAGS	equ	05B56h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05B18h	; start of system data area
SYSEND	equ	05BBEh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05B2Bh	; top of pool area
SYSTYP	equ	05B20h	; system type
SYSVER	equ	05B1Eh	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C36h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
