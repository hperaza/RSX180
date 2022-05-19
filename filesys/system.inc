$ALLOC	equ	019D4h	; allocate pool memory
$ALUN	equ	015E3h	; assign LUN to device
$ASGN	equ	01443h	; assign logical name to physical device
$ASNTP	equ	0287Ah	; assign next task to partition
$CHKPT	equ	02A62h	; initiate task checkpoint
$CLASN	equ	014BDh	; delete all logical dev assignments of the given type
$CLIST	equ	05CA2h	; list of CLI control blocks
$CLKQ	equ	05CA0h	; ptr to head of clock queue
$CONN	equ	01754h	; connect to task
$CPCB	equ	05C9Eh	; address of PCB of current task
$CPLST	equ	05C94h	; ptr to head of checkpoint PCB list
$CTCB	equ	05C9Ch	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014A6h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05CAFh	; error sequence number
$FEAT	equ	05C7Ch	; feature bits
$FILBF	equ	05CCEh	; ptr to file I/O buffer area
$FIXTK	equ	03564h	; fix task in memory
$FNDEV	equ	014FEh	; find device and get UCB address
$FNPAR	equ	02821h	; find partition by name
$FNTCB	equ	01013h	; find TCB by name
$FNTSK	equ	00FE8h	; find task by name
$FORKQ	equ	05CBAh	; pointer to list of fork blocks
$FREE	equ	01A33h	; free pool memory
$GTUCB	equ	015CEh	; get UCB address
$HOSTN	equ	05C7Dh	; host/node name
$IOEND	equ	01E04h	; end I/O processing for ASTs
$LDCKR	equ	00AA1h	; resume task after checkpoint read
$LDCKW	equ	00AD3h	; queue task to partition after chkpnt write
$LDGO	equ	00A04h	; start task after load
$LGOUT	equ	0171Fh	; logout user
$LKTCB	equ	008AAh	; link TCB to the specified list
$LOGDV	equ	05C90h	; ptr to head of logical device assignment list
$LOGIN	equ	016B2h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05C8Ch	; total memory size
$MFLGS	equ	05CB9h	; MCR flags
$MVTBL	equ	05CBCh	; ptr to head of mounted device list
$PHYDV	equ	05C8Eh	; ptr to head of physical device list
$PLIST	equ	05C92h	; ptr to list of partitions
$POLSZ	equ	05C8Ah	; size of pool area
$POOL	equ	05C88h	; ptr to start of pool area
$REDIR	equ	0154Dh	; follow UCB redirection links
$REMTK	equ	0355Bh	; remove task from STD
$RLIST	equ	05C98h	; ptr to head of ready tasks list
$RNDC	equ	05CA4h	; round-robin interval in ticks
$RNDH	equ	05CA6h	; highest priority for round-robin scheduling
$RNDL	equ	05CA7h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05CBEh	; scratch buffer address
$SWPC	equ	05CA9h	; swapping interval in ticks
$SWPCT	equ	05CAAh	; swapping interval counter
$SWPRI	equ	05CA8h	; priority range for swapping
$SWSTK	equ	05CD0h	; stub to call kernel routines
$TLIST	equ	05C96h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	0169Bh	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	0356Dh	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05C9Ah	; ptr to head of waiting tasks list
IODONE	equ	01DE1h	; end I/O processing
LDRTCB	equ	05CADh	; LDR... TCB
MCRTCB	equ	05CABh	; MCR... TCB
NVOK	equ	056ABh	; P112 NV RAM OK flag
NVRAM	equ	05693h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011A1h	; set task's event flag
SFLAGS	equ	05CB1h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05C73h	; start of system data area
SYSEND	equ	05D19h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05C86h	; top of pool area
SYSTYP	equ	05C7Bh	; system type
SYSVER	equ	05C79h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C36h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
