$ALLOC	equ	01A08h	; allocate pool memory
$ALUN	equ	01617h	; assign LUN to device
$ASGN	equ	01477h	; assign logical name to physical device
$ASNTP	equ	02851h	; assign next task to partition
$CHKPT	equ	02A39h	; initiate task checkpoint
$CLASN	equ	014F1h	; delete all logical dev assignments of the given type
$CLIST	equ	05AEDh	; list of CLI control blocks
$CLKQ	equ	05AEBh	; ptr to head of clock queue
$CONN	equ	01788h	; connect to task
$CPCB	equ	05AE9h	; address of PCB of current task
$CPLST	equ	05ADFh	; ptr to head of checkpoint PCB list
$CTCB	equ	05AE7h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014DAh	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05AFAh	; error sequence number
$FEAT	equ	05AC7h	; feature bits
$FILBF	equ	05B19h	; ptr to file I/O buffer area
$FIXTK	equ	0353Bh	; fix task in memory
$FNDEV	equ	01532h	; find device and get UCB address
$FNPAR	equ	027F9h	; find partition by name
$FNTCB	equ	01047h	; find TCB by name
$FNTSK	equ	0101Ch	; find task by name
$FORKQ	equ	05B05h	; pointer to list of fork blocks
$FREE	equ	01A67h	; free pool memory
$GTUCB	equ	01602h	; get UCB address
$HOSTN	equ	05AC8h	; host/node name
$IOEND	equ	01DDCh	; end I/O processing for ASTs
$LDCKR	equ	00AAEh	; resume task after checkpoint read
$LDCKW	equ	00AE0h	; queue task to partition after chkpnt write
$LDGO	equ	00A11h	; start task after load
$LGOUT	equ	01753h	; logout user
$LKTCB	equ	008B7h	; link TCB to the specified list
$LOGDV	equ	05ADBh	; ptr to head of logical device assignment list
$LOGIN	equ	016E6h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05AD7h	; total memory size
$MFLGS	equ	05B04h	; MCR flags
$MVTBL	equ	05B07h	; ptr to head of mounted device list
$PHYDV	equ	05AD9h	; ptr to head of physical device list
$PLIST	equ	05ADDh	; ptr to list of partitions
$POLSZ	equ	05AD5h	; size of pool area
$POOL	equ	05AD3h	; ptr to start of pool area
$REDIR	equ	01581h	; follow UCB redirection links
$REMTK	equ	03532h	; remove task from STD
$RLIST	equ	05AE3h	; ptr to head of ready tasks list
$RNDC	equ	05AEFh	; round-robin interval in ticks
$RNDH	equ	05AF1h	; highest priority for round-robin scheduling
$RNDL	equ	05AF2h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05B09h	; scratch buffer address
$SWPC	equ	05AF4h	; swapping interval in ticks
$SWPCT	equ	05AF5h	; swapping interval counter
$SWPRI	equ	05AF3h	; priority range for swapping
$SWSTK	equ	05B1Bh	; stub to call kernel routines
$TLIST	equ	05AE1h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016CFh	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	03544h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05AE5h	; ptr to head of waiting tasks list
IODONE	equ	01DB9h	; end I/O processing
LDRTCB	equ	05AF8h	; LDR... TCB
MCRTCB	equ	05AF6h	; MCR... TCB
NVOK	equ	05516h	; P112 NV RAM OK flag
NVRAM	equ	054FEh	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011D5h	; set task's event flag
SFLAGS	equ	05AFCh	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05ABEh	; start of system data area
SYSEND	equ	05B64h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05AD1h	; top of pool area
SYSTYP	equ	05AC6h	; system type
SYSVER	equ	05AC4h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C6Ah	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
