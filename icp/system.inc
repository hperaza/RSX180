$ALLOC	equ	019DDh	; allocate pool memory
$ALUN	equ	015F0h	; assign LUN to device
$ASGN	equ	01450h	; assign logical name to physical device
$ASNTP	equ	027E2h	; assign next task to partition
$CHKPT	equ	029CAh	; initiate task checkpoint
$CLASN	equ	014CAh	; delete all logical dev assignments of the given type
$CLIST	equ	0595Bh	; list of CLI control blocks
$CLKQ	equ	05959h	; ptr to head of clock queue
$CONN	equ	0175Dh	; connect to task
$CPCB	equ	05957h	; address of PCB of current task
$CPLST	equ	0594Dh	; ptr to head of checkpoint PCB list
$CTCB	equ	05955h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014B3h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05968h	; error sequence number
$FEAT	equ	0593Eh	; feature bits
$FILBF	equ	05987h	; ptr to file I/O buffer area
$FIXTK	equ	03498h	; fix task in memory
$FNDEV	equ	0150Bh	; find device and get UCB address
$FNPAR	equ	0278Ah	; find partition by name
$FNTCB	equ	01034h	; find TCB by name
$FNTSK	equ	01009h	; find task by name
$FORKQ	equ	05973h	; pointer to list of fork blocks
$FREE	equ	01A3Ch	; free pool memory
$GTUCB	equ	015DBh	; get UCB address
$HOSTN	equ	05935h	; host/node name
$IOEND	equ	01DADh	; end I/O processing for ASTs
$LDCKR	equ	00A97h	; resume task after checkpoint read
$LDCKW	equ	00AC9h	; queue task to partition after chkpnt write
$LDGO	equ	00A08h	; start task after load
$LGOUT	equ	01728h	; logout user
$LKTCB	equ	008AEh	; link TCB to the specified list
$LOGDV	equ	05949h	; ptr to head of logical device assignment list
$LOGIN	equ	016BFh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05945h	; total memory size
$MFLGS	equ	05972h	; MCR flags
$MVTBL	equ	05975h	; ptr to head of mounted device list
$PHYDV	equ	05947h	; ptr to head of physical device list
$PLIST	equ	0594Bh	; ptr to list of partitions
$POLSZ	equ	05943h	; size of pool area
$POOL	equ	05941h	; ptr to start of pool area
$REDIR	equ	0155Ah	; follow UCB redirection links
$REMTK	equ	0348Fh	; remove task from STD
$RLIST	equ	05951h	; ptr to head of ready tasks list
$RNDC	equ	0595Dh	; round-robin interval in ticks
$RNDH	equ	0595Fh	; highest priority for round-robin scheduling
$RNDL	equ	05960h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05977h	; scratch buffer address
$SWPC	equ	05962h	; swapping interval in ticks
$SWPCT	equ	05963h	; swapping interval counter
$SWPRI	equ	05961h	; priority range for swapping
$SWSTK	equ	05989h	; stub to call kernel routines
$TLIST	equ	0594Fh	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016A8h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	034A1h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05953h	; ptr to head of waiting tasks list
IODONE	equ	01D87h	; end I/O processing
LDRTCB	equ	05966h	; LDR... TCB
MCRTCB	equ	05964h	; MCR... TCB
NVOK	equ	0538Bh	; P112 NV RAM OK flag
NVRAM	equ	05373h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011AEh	; set task's event flag
SFLAGS	equ	0596Ah	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0592Dh	; start of system data area
SYSEND	equ	059D2h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	0593Fh	; top of pool area
SYSVER	equ	05933h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C53h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
