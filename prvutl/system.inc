$ALLOC	equ	019D9h	; allocate pool memory
$ALUN	equ	015ECh	; assign LUN to device
$ASGN	equ	0144Ch	; assign logical name to physical device
$ASNTP	equ	027EBh	; assign next task to partition
$CHKPT	equ	029D3h	; initiate task checkpoint
$CLASN	equ	014C6h	; delete all logical dev assignments of the given type
$CLIST	equ	0596Ah	; list of CLI control blocks
$CLKQ	equ	05968h	; ptr to head of clock queue
$CONN	equ	01759h	; connect to task
$CPCB	equ	05966h	; address of PCB of current task
$CPLST	equ	0595Ch	; ptr to head of checkpoint PCB list
$CTCB	equ	05964h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014AFh	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05977h	; error sequence number
$FEAT	equ	0594Dh	; feature bits
$FILBF	equ	05996h	; ptr to file I/O buffer area
$FIXTK	equ	034A7h	; fix task in memory
$FNDEV	equ	01507h	; find device and get UCB address
$FNPAR	equ	02793h	; find partition by name
$FNTCB	equ	01030h	; find TCB by name
$FNTSK	equ	01005h	; find task by name
$FORKQ	equ	05982h	; pointer to list of fork blocks
$FREE	equ	01A38h	; free pool memory
$GTUCB	equ	015D7h	; get UCB address
$HOSTN	equ	05944h	; host/node name
$IOEND	equ	01DB2h	; end I/O processing for ASTs
$LDCKR	equ	00A97h	; resume task after checkpoint read
$LDCKW	equ	00AC9h	; queue task to partition after chkpnt write
$LDGO	equ	00A08h	; start task after load
$LGOUT	equ	01724h	; logout user
$LKTCB	equ	008AEh	; link TCB to the specified list
$LOGDV	equ	05958h	; ptr to head of logical device assignment list
$LOGIN	equ	016BBh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05954h	; total memory size
$MFLGS	equ	05981h	; MCR flags
$MVTBL	equ	05984h	; ptr to head of mounted device list
$PHYDV	equ	05956h	; ptr to head of physical device list
$PLIST	equ	0595Ah	; ptr to list of partitions
$POLSZ	equ	05952h	; size of pool area
$POOL	equ	05950h	; ptr to start of pool area
$REDIR	equ	01556h	; follow UCB redirection links
$REMTK	equ	0349Eh	; remove task from STD
$RLIST	equ	05960h	; ptr to head of ready tasks list
$RNDC	equ	0596Ch	; round-robin interval in ticks
$RNDH	equ	0596Eh	; highest priority for round-robin scheduling
$RNDL	equ	0596Fh	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05986h	; scratch buffer address
$SWPC	equ	05971h	; swapping interval in ticks
$SWPCT	equ	05972h	; swapping interval counter
$SWPRI	equ	05970h	; priority range for swapping
$SWSTK	equ	05998h	; stub to call kernel routines
$TLIST	equ	0595Eh	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016A4h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	034B0h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05962h	; ptr to head of waiting tasks list
IODONE	equ	01D8Ch	; end I/O processing
LDRTCB	equ	05975h	; LDR... TCB
MCRTCB	equ	05973h	; MCR... TCB
NVOK	equ	0539Ah	; P112 NV RAM OK flag
NVRAM	equ	05382h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011AAh	; set task's event flag
SFLAGS	equ	05979h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0593Ch	; start of system data area
SYSEND	equ	059E1h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	0594Eh	; top of pool area
SYSVER	equ	05942h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C53h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
