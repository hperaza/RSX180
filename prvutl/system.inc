$ALLOC	equ	0172Bh	; allocate pool memory
$ALUN	equ	012FCh	; assign LUN to device
$ASGN	equ	0115Ch	; assign logical name to physical device
$ASNTP	equ	02663h	; assign next task to partition
$AVAIL	equ	01814h	; compute available pool memory
$CHKPT	equ	0285Ah	; initiate task checkpoint
$CLASN	equ	011D6h	; delete all logical dev assignments of the given type
$CLIST	equ	05D2Dh	; list of CLI control blocks
$CLKQ	equ	05D2Bh	; ptr to head of clock queue
$CONN	equ	0146Fh	; connect to task
$CPCB	equ	05D29h	; address of PCB of current task
$CPLST	equ	05D1Fh	; ptr to head of checkpoint PCB list
$CTCB	equ	05D27h	; address of TCB of current task
$DBBRK	equ	00DC7h	; break task execution
$DBCON	equ	00CF8h	; connect task to external debugger
$DBDIS	equ	00D80h	; disconnect task from external debugger
$DBRES	equ	00DF5h	; resume task stopped for debugger
$DEASN	equ	011BFh	; delete logical device assignment
$ERSEQ	equ	05D3Ah	; error sequence number
$FEAT	equ	05D07h	; feature bits
$FILBF	equ	05D59h	; ptr to file I/O buffer area
$FIXTK	equ	006A1h	; fix task in memory
$FNDEV	equ	01217h	; find device and get UCB address
$FNPAR	equ	0260Ah	; find partition by name
$FNTCB	equ	00B25h	; find TCB by name
$FNTSK	equ	00AFAh	; find task by name
$FORKQ	equ	05D45h	; pointer to list of fork blocks
$FREE	equ	0178Ah	; free pool memory
$GTUCB	equ	012E7h	; get UCB address
$HOSTN	equ	05D08h	; host/node name
$IOEND	equ	01B73h	; end I/O processing for ASTs
$KDMON	equ	0F78Bh	; kernel debugger-monitor main entry point
$KDTRP	equ	0F9ABh	; kernel debugger-monitor trap entry point
$KMTRP	equ	0FA29h	; kernel debugger-monitor trap entry with message
$LDCKR	equ	00585h	; resume task after checkpoint read
$LDCKW	equ	005B7h	; queue task to partition after chkpnt write
$LDGO	equ	004E2h	; start task after load
$LGOUT	equ	0143Ah	; logout user
$LKTCB	equ	00388h	; link TCB to the specified list
$LOGDV	equ	05D1Bh	; ptr to head of logical device assignment list
$LOGIN	equ	013CBh	; login user
$MCOPY	equ	0F240h	; inter-bank memory copy routine
$MEMSZ	equ	05D17h	; total memory size
$MFLGS	equ	05D44h	; MCR flags
$MVTBL	equ	05D47h	; ptr to head of mounted device list
$PHYDV	equ	05D19h	; ptr to head of physical device list
$PLIST	equ	05D1Dh	; ptr to list of partitions
$POLSZ	equ	05D15h	; size of pool area
$POOL	equ	05D13h	; ptr to start of pool area
$REDIR	equ	01266h	; follow UCB redirection links
$REMTK	equ	008E9h	; remove task from STD
$RLIST	equ	05D23h	; ptr to head of ready tasks list
$RNDC	equ	05D2Fh	; round-robin interval in ticks
$RNDH	equ	05D31h	; highest priority for round-robin scheduling
$RNDL	equ	05D32h	; lowest priority for round-robin scheduling
$SBANK	equ	0F441h	; system bank number
$SCRBF	equ	05D49h	; scratch buffer address
$SWPC	equ	05D34h	; swapping interval in ticks
$SWPCT	equ	05D35h	; swapping interval counter
$SWPRI	equ	05D33h	; priority range for swapping
$SWSTK	equ	05D5Bh	; stub to call kernel routines
$TLIST	equ	05D21h	; ptr to head of installed tasks list
$UBANK	equ	0F442h	; bank of current task
$UCBDN	equ	013B4h	; get device name and unit from UCB
$UGETB	equ	0F3C3h	; inter-bank get byte routine
$UGETW	equ	0F3F9h	; inter-bank get word routine
$UNFTK	equ	006DDh	; unfix task
$UPUTB	equ	0F3DCh	; inter-bank put byte routine
$UPUTW	equ	0F417h	; inter-bank put word routine
$VALBF	equ	01DA3h	; validate buffer (current task)
$VALTB	equ	01D80h	; validate buffer (arbitrary task)
$WLIST	equ	05D25h	; ptr to head of waiting tasks list
IODONE	equ	01B50h	; end I/O processing
LDRTCB	equ	05D38h	; LDR... TCB
MCRTCB	equ	05D36h	; MCR... TCB
NVOK	equ	05726h	; P112 NV RAM OK flag
NVRAM	equ	0570Eh	; P112 NV RAM contents
SCBAR	equ	0F444h	; supervisor mode CBAR value
SETFLG	equ	00ED0h	; set task's event flag
SFLAGS	equ	05D3Ch	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05CFEh	; start of system data area
SYSEND	equ	05DA4h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0FAh	; current system level
SYSTOP	equ	05D11h	; top of pool area
SYSTYP	equ	05D06h	; system type
SYSVER	equ	05D04h	; system version number
TICCNT	equ	0F436h	; absolute time count in ticks
TICSEC	equ	0F435h	; ticks per second
TKILL	equ	00734h	; abort task
UCBAR	equ	0F443h	; user mode CBAR value
UPTIME	equ	0F43Ah	; system up time (ticks and seconds)
