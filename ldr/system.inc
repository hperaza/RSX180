$ALLOC	equ	0152Dh	; allocate pool memory
$ALUN	equ	01108h	; assign LUN to device
$ASGN	equ	00F68h	; assign logical name to physical device
$ASNTP	equ	02452h	; assign next task to partition
$AVAIL	equ	01616h	; compute available pool memory
$CHKPT	equ	0263Ah	; initiate task checkpoint
$CLASN	equ	00FE2h	; delete all logical dev assignments of the given type
$CLIST	equ	05AF2h	; list of CLI control blocks
$CLKQ	equ	05AF0h	; ptr to head of clock queue
$CONN	equ	0127Bh	; connect to task
$CPCB	equ	05AEEh	; address of PCB of current task
$CPLST	equ	05AE4h	; ptr to head of checkpoint PCB list
$CTCB	equ	05AECh	; address of TCB of current task
$DBMON	equ	0F75Bh	; debugger-monitor main entry point
$DBTRP	equ	0F97Bh	; debugger-monitor bpt entry
$DEASN	equ	00FCBh	; delete logical device assignment
$DMTRP	equ	0F9F9h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05AFFh	; error sequence number
$FEAT	equ	05ACCh	; feature bits
$FILBF	equ	05B1Eh	; ptr to file I/O buffer area
$FIXTK	equ	00694h	; fix task in memory
$FNDEV	equ	01023h	; find device and get UCB address
$FNPAR	equ	023F9h	; find partition by name
$FNTCB	equ	00B05h	; find TCB by name
$FNTSK	equ	00ADAh	; find task by name
$FORKQ	equ	05B0Ah	; pointer to list of fork blocks
$FREE	equ	0158Ch	; free pool memory
$GTUCB	equ	010F3h	; get UCB address
$HOSTN	equ	05ACDh	; host/node name
$IOEND	equ	01975h	; end I/O processing for ASTs
$LDCKR	equ	0057Fh	; resume task after checkpoint read
$LDCKW	equ	005B1h	; queue task to partition after chkpnt write
$LDGO	equ	004E2h	; start task after load
$LGOUT	equ	01246h	; logout user
$LKTCB	equ	00388h	; link TCB to the specified list
$LOGDV	equ	05AE0h	; ptr to head of logical device assignment list
$LOGIN	equ	011D7h	; login user
$MCOPY	equ	0F210h	; inter-bank memory copy routine
$MEMSZ	equ	05ADCh	; total memory size
$MFLGS	equ	05B09h	; MCR flags
$MVTBL	equ	05B0Ch	; ptr to head of mounted device list
$PHYDV	equ	05ADEh	; ptr to head of physical device list
$PLIST	equ	05AE2h	; ptr to list of partitions
$POLSZ	equ	05ADAh	; size of pool area
$POOL	equ	05AD8h	; ptr to start of pool area
$REDIR	equ	01072h	; follow UCB redirection links
$REMTK	equ	008D9h	; remove task from STD
$RLIST	equ	05AE8h	; ptr to head of ready tasks list
$RNDC	equ	05AF4h	; round-robin interval in ticks
$RNDH	equ	05AF6h	; highest priority for round-robin scheduling
$RNDL	equ	05AF7h	; lowest priority for round-robin scheduling
$SBANK	equ	0F411h	; system bank number
$SCRBF	equ	05B0Eh	; scratch buffer address
$SWPC	equ	05AF9h	; swapping interval in ticks
$SWPCT	equ	05AFAh	; swapping interval counter
$SWPRI	equ	05AF8h	; priority range for swapping
$SWSTK	equ	05B20h	; stub to call kernel routines
$TLIST	equ	05AE6h	; ptr to head of installed tasks list
$UBANK	equ	0F412h	; bank of current task
$UCBDN	equ	011C0h	; get device name and unit from UCB
$UGETB	equ	0F393h	; inter-bank get byte routine
$UGETW	equ	0F3C9h	; inter-bank get word routine
$UNFTK	equ	006D0h	; unfix task
$UPUTB	equ	0F3ACh	; inter-bank put byte routine
$UPUTW	equ	0F3E7h	; inter-bank put word routine
$VALBF	equ	01BA5h	; validate buffer (current task)
$VALTB	equ	01B82h	; validate buffer (arbitrary task)
$WLIST	equ	05AEAh	; ptr to head of waiting tasks list
IODONE	equ	01952h	; end I/O processing
LDRTCB	equ	05AFDh	; LDR... TCB
MCRTCB	equ	05AFBh	; MCR... TCB
NVOK	equ	054EBh	; P112 NV RAM OK flag
NVRAM	equ	054D3h	; P112 NV RAM contents
SCBAR	equ	0F414h	; supervisor mode CBAR value
SETFLG	equ	00CEAh	; set task's event flag
SFLAGS	equ	05B01h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05AC3h	; start of system data area
SYSEND	equ	05B69h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D5h	; current system level
SYSTOP	equ	05AD6h	; top of pool area
SYSTYP	equ	05ACBh	; system type
SYSVER	equ	05AC9h	; system version number
TICCNT	equ	0F406h	; absolute time count in ticks
TICSEC	equ	0F405h	; ticks per second
TKILL	equ	00727h	; abort task
UCBAR	equ	0F413h	; user mode CBAR value
UPTIME	equ	0F40Ah	; system up time (ticks and seconds)
