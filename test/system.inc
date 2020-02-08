$ALLOC	equ	01996h	; allocate pool memory
$ALUN	equ	015A9h	; assign LUN to device
$ASGN	equ	01409h	; assign logical name to physical device
$ASNTP	equ	0277Dh	; assign next task to partition
$CHKPT	equ	02965h	; initiate task checkpoint
$CLASN	equ	01483h	; delete all logical dev assignments of the given type
$CLIST	equ	058B0h	; list of CLI control blocks
$CLKQ	equ	058AEh	; ptr to head of clock queue
$CONN	equ	01716h	; connect to task
$CPCB	equ	058ACh	; address of PCB of current task
$CPLST	equ	058A2h	; ptr to head of checkpoint PCB list
$CTCB	equ	058AAh	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	0146Ch	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	058BDh	; error sequence number
$FEAT	equ	05893h	; feature bits
$FILBF	equ	058DCh	; ptr to file I/O buffer area
$FIXTK	equ	033EDh	; fix task in memory
$FNDEV	equ	014C4h	; find device and get UCB address
$FNPAR	equ	02725h	; find partition by name
$FNTCB	equ	0106Ch	; find TCB by name
$FNTSK	equ	01041h	; find task by name
$FORKQ	equ	058C8h	; pointer to list of fork blocks
$FREE	equ	019F5h	; free pool memory
$GTUCB	equ	01594h	; get UCB address
$HOSTN	equ	0588Ah	; host/node name
$IOEND	equ	01D4Eh	; end I/O processing for ASTs
$LDCKR	equ	00A97h	; resume task after checkpoint read
$LDCKW	equ	00AC9h	; queue task to partition after chkpnt write
$LDGO	equ	00A08h	; start task after load
$LGOUT	equ	016E1h	; logout user
$LKTCB	equ	008AEh	; link TCB to the specified list
$LOGDV	equ	0589Eh	; ptr to head of logical device assignment list
$LOGIN	equ	01678h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	0589Ah	; total memory size
$MFLGS	equ	058C7h	; MCR flags
$MVTBL	equ	058CAh	; ptr to head of mounted device list
$PHYDV	equ	0589Ch	; ptr to head of physical device list
$PLIST	equ	058A0h	; ptr to list of partitions
$POLSZ	equ	05898h	; size of pool area
$POOL	equ	05896h	; ptr to start of pool area
$REDIR	equ	01513h	; follow UCB redirection links
$REMTK	equ	033E4h	; remove task from STD
$RLIST	equ	058A6h	; ptr to head of ready tasks list
$RNDC	equ	058B2h	; round-robin interval in ticks
$RNDH	equ	058B4h	; highest priority for round-robin scheduling
$RNDL	equ	058B5h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	058CCh	; scratch buffer address
$SWPC	equ	058B7h	; swapping interval in ticks
$SWPCT	equ	058B8h	; swapping interval counter
$SWPRI	equ	058B6h	; priority range for swapping
$SWSTK	equ	058DEh	; stub to call kernel routines
$TLIST	equ	058A4h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	01661h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	033F6h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	058A8h	; ptr to head of waiting tasks list
IODONE	equ	01D28h	; end I/O processing
LDRTCB	equ	058BBh	; LDR... TCB
MCRTCB	equ	058B9h	; MCR... TCB
NVOK	equ	052E0h	; P112 NV RAM OK flag
NVRAM	equ	052C8h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011E6h	; set task's event flag
SFLAGS	equ	058BFh	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05882h	; start of system data area
SYSEND	equ	05927h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05894h	; top of pool area
SYSVER	equ	05888h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C53h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
