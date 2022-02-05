$ALLOC	equ	01A08h	; allocate pool memory
$ALUN	equ	01617h	; assign LUN to device
$ASGN	equ	01477h	; assign logical name to physical device
$ASNTP	equ	02899h	; assign next task to partition
$CHKPT	equ	02A81h	; initiate task checkpoint
$CLASN	equ	014F1h	; delete all logical dev assignments of the given type
$CLIST	equ	05B35h	; list of CLI control blocks
$CLKQ	equ	05B33h	; ptr to head of clock queue
$CONN	equ	01788h	; connect to task
$CPCB	equ	05B31h	; address of PCB of current task
$CPLST	equ	05B27h	; ptr to head of checkpoint PCB list
$CTCB	equ	05B2Fh	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014DAh	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05B42h	; error sequence number
$FEAT	equ	05B0Fh	; feature bits
$FILBF	equ	05B61h	; ptr to file I/O buffer area
$FIXTK	equ	03583h	; fix task in memory
$FNDEV	equ	01532h	; find device and get UCB address
$FNPAR	equ	02841h	; find partition by name
$FNTCB	equ	01047h	; find TCB by name
$FNTSK	equ	0101Ch	; find task by name
$FORKQ	equ	05B4Dh	; pointer to list of fork blocks
$FREE	equ	01A67h	; free pool memory
$GTUCB	equ	01602h	; get UCB address
$HOSTN	equ	05B10h	; host/node name
$IOEND	equ	01E24h	; end I/O processing for ASTs
$LDCKR	equ	00AAEh	; resume task after checkpoint read
$LDCKW	equ	00AE0h	; queue task to partition after chkpnt write
$LDGO	equ	00A11h	; start task after load
$LGOUT	equ	01753h	; logout user
$LKTCB	equ	008B7h	; link TCB to the specified list
$LOGDV	equ	05B23h	; ptr to head of logical device assignment list
$LOGIN	equ	016E6h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05B1Fh	; total memory size
$MFLGS	equ	05B4Ch	; MCR flags
$MVTBL	equ	05B4Fh	; ptr to head of mounted device list
$PHYDV	equ	05B21h	; ptr to head of physical device list
$PLIST	equ	05B25h	; ptr to list of partitions
$POLSZ	equ	05B1Dh	; size of pool area
$POOL	equ	05B1Bh	; ptr to start of pool area
$REDIR	equ	01581h	; follow UCB redirection links
$REMTK	equ	0357Ah	; remove task from STD
$RLIST	equ	05B2Bh	; ptr to head of ready tasks list
$RNDC	equ	05B37h	; round-robin interval in ticks
$RNDH	equ	05B39h	; highest priority for round-robin scheduling
$RNDL	equ	05B3Ah	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05B51h	; scratch buffer address
$SWPC	equ	05B3Ch	; swapping interval in ticks
$SWPCT	equ	05B3Dh	; swapping interval counter
$SWPRI	equ	05B3Bh	; priority range for swapping
$SWSTK	equ	05B63h	; stub to call kernel routines
$TLIST	equ	05B29h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016CFh	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	0358Ch	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05B2Dh	; ptr to head of waiting tasks list
IODONE	equ	01E01h	; end I/O processing
LDRTCB	equ	05B40h	; LDR... TCB
MCRTCB	equ	05B3Eh	; MCR... TCB
NVOK	equ	0555Eh	; P112 NV RAM OK flag
NVRAM	equ	05546h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011D5h	; set task's event flag
SFLAGS	equ	05B44h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05B06h	; start of system data area
SYSEND	equ	05BACh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05B19h	; top of pool area
SYSTYP	equ	05B0Eh	; system type
SYSVER	equ	05B0Ch	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C6Ah	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
