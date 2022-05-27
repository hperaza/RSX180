$ALLOC	equ	019D4h	; allocate pool memory
$ALUN	equ	015E3h	; assign LUN to device
$ASGN	equ	01443h	; assign logical name to physical device
$ASNTP	equ	0287Ah	; assign next task to partition
$CHKPT	equ	02A62h	; initiate task checkpoint
$CLASN	equ	014BDh	; delete all logical dev assignments of the given type
$CLIST	equ	05CEFh	; list of CLI control blocks
$CLKQ	equ	05CEDh	; ptr to head of clock queue
$CONN	equ	01754h	; connect to task
$CPCB	equ	05CEBh	; address of PCB of current task
$CPLST	equ	05CE1h	; ptr to head of checkpoint PCB list
$CTCB	equ	05CE9h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014A6h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05CFCh	; error sequence number
$FEAT	equ	05CC9h	; feature bits
$FILBF	equ	05D1Bh	; ptr to file I/O buffer area
$FIXTK	equ	03578h	; fix task in memory
$FNDEV	equ	014FEh	; find device and get UCB address
$FNPAR	equ	02821h	; find partition by name
$FNTCB	equ	01013h	; find TCB by name
$FNTSK	equ	00FE8h	; find task by name
$FORKQ	equ	05D07h	; pointer to list of fork blocks
$FREE	equ	01A33h	; free pool memory
$GTUCB	equ	015CEh	; get UCB address
$HOSTN	equ	05CCAh	; host/node name
$IOEND	equ	01E04h	; end I/O processing for ASTs
$LDCKR	equ	00AA1h	; resume task after checkpoint read
$LDCKW	equ	00AD3h	; queue task to partition after chkpnt write
$LDGO	equ	00A04h	; start task after load
$LGOUT	equ	0171Fh	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	05CDDh	; ptr to head of logical device assignment list
$LOGIN	equ	016B2h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05CD9h	; total memory size
$MFLGS	equ	05D06h	; MCR flags
$MVTBL	equ	05D09h	; ptr to head of mounted device list
$PHYDV	equ	05CDBh	; ptr to head of physical device list
$PLIST	equ	05CDFh	; ptr to list of partitions
$POLSZ	equ	05CD7h	; size of pool area
$POOL	equ	05CD5h	; ptr to start of pool area
$REDIR	equ	0154Dh	; follow UCB redirection links
$REMTK	equ	0356Fh	; remove task from STD
$RLIST	equ	05CE5h	; ptr to head of ready tasks list
$RNDC	equ	05CF1h	; round-robin interval in ticks
$RNDH	equ	05CF3h	; highest priority for round-robin scheduling
$RNDL	equ	05CF4h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05D0Bh	; scratch buffer address
$SWPC	equ	05CF6h	; swapping interval in ticks
$SWPCT	equ	05CF7h	; swapping interval counter
$SWPRI	equ	05CF5h	; priority range for swapping
$SWSTK	equ	05D1Dh	; stub to call kernel routines
$TLIST	equ	05CE3h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	0169Bh	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	03581h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05CE7h	; ptr to head of waiting tasks list
IODONE	equ	01DE1h	; end I/O processing
LDRTCB	equ	05CFAh	; LDR... TCB
MCRTCB	equ	05CF8h	; MCR... TCB
NVOK	equ	056EAh	; P112 NV RAM OK flag
NVRAM	equ	056D2h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011A1h	; set task's event flag
SFLAGS	equ	05CFEh	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05CC0h	; start of system data area
SYSEND	equ	05D66h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05CD3h	; top of pool area
SYSTYP	equ	05CC8h	; system type
SYSVER	equ	05CC6h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C36h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
