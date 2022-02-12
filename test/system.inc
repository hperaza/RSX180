$ALLOC	equ	019E1h	; allocate pool memory
$ALUN	equ	015F0h	; assign LUN to device
$ASGN	equ	01450h	; assign logical name to physical device
$ASNTP	equ	02886h	; assign next task to partition
$CHKPT	equ	02A6Eh	; initiate task checkpoint
$CLASN	equ	014CAh	; delete all logical dev assignments of the given type
$CLIST	equ	05B22h	; list of CLI control blocks
$CLKQ	equ	05B20h	; ptr to head of clock queue
$CONN	equ	01761h	; connect to task
$CPCB	equ	05B1Eh	; address of PCB of current task
$CPLST	equ	05B14h	; ptr to head of checkpoint PCB list
$CTCB	equ	05B1Ch	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014B3h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05B2Fh	; error sequence number
$FEAT	equ	05AFCh	; feature bits
$FILBF	equ	05B4Eh	; ptr to file I/O buffer area
$FIXTK	equ	03570h	; fix task in memory
$FNDEV	equ	0150Bh	; find device and get UCB address
$FNPAR	equ	0282Eh	; find partition by name
$FNTCB	equ	01020h	; find TCB by name
$FNTSK	equ	00FF5h	; find task by name
$FORKQ	equ	05B3Ah	; pointer to list of fork blocks
$FREE	equ	01A40h	; free pool memory
$GTUCB	equ	015DBh	; get UCB address
$HOSTN	equ	05AFDh	; host/node name
$IOEND	equ	01E11h	; end I/O processing for ASTs
$LDCKR	equ	00AAEh	; resume task after checkpoint read
$LDCKW	equ	00AE0h	; queue task to partition after chkpnt write
$LDGO	equ	00A11h	; start task after load
$LGOUT	equ	0172Ch	; logout user
$LKTCB	equ	008B7h	; link TCB to the specified list
$LOGDV	equ	05B10h	; ptr to head of logical device assignment list
$LOGIN	equ	016BFh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05B0Ch	; total memory size
$MFLGS	equ	05B39h	; MCR flags
$MVTBL	equ	05B3Ch	; ptr to head of mounted device list
$PHYDV	equ	05B0Eh	; ptr to head of physical device list
$PLIST	equ	05B12h	; ptr to list of partitions
$POLSZ	equ	05B0Ah	; size of pool area
$POOL	equ	05B08h	; ptr to start of pool area
$REDIR	equ	0155Ah	; follow UCB redirection links
$REMTK	equ	03567h	; remove task from STD
$RLIST	equ	05B18h	; ptr to head of ready tasks list
$RNDC	equ	05B24h	; round-robin interval in ticks
$RNDH	equ	05B26h	; highest priority for round-robin scheduling
$RNDL	equ	05B27h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05B3Eh	; scratch buffer address
$SWPC	equ	05B29h	; swapping interval in ticks
$SWPCT	equ	05B2Ah	; swapping interval counter
$SWPRI	equ	05B28h	; priority range for swapping
$SWSTK	equ	05B50h	; stub to call kernel routines
$TLIST	equ	05B16h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016A8h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	03579h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05B1Ah	; ptr to head of waiting tasks list
IODONE	equ	01DEEh	; end I/O processing
LDRTCB	equ	05B2Dh	; LDR... TCB
MCRTCB	equ	05B2Bh	; MCR... TCB
NVOK	equ	0554Bh	; P112 NV RAM OK flag
NVRAM	equ	05533h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011AEh	; set task's event flag
SFLAGS	equ	05B31h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05AF3h	; start of system data area
SYSEND	equ	05B99h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05B06h	; top of pool area
SYSTYP	equ	05AFBh	; system type
SYSVER	equ	05AF9h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C43h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
