$ALLOC	equ	019F6h	; allocate pool memory
$ALUN	equ	01609h	; assign LUN to device
$ASGN	equ	01469h	; assign logical name to physical device
$ASNTP	equ	0283Fh	; assign next task to partition
$CHKPT	equ	02A27h	; initiate task checkpoint
$CLASN	equ	014E3h	; delete all logical dev assignments of the given type
$CLIST	equ	05AD5h	; list of CLI control blocks
$CLKQ	equ	05AD3h	; ptr to head of clock queue
$CONN	equ	01776h	; connect to task
$CPCB	equ	05AD1h	; address of PCB of current task
$CPLST	equ	05AC7h	; ptr to head of checkpoint PCB list
$CTCB	equ	05ACFh	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014CCh	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05AE2h	; error sequence number
$FEAT	equ	05AAFh	; feature bits
$FILBF	equ	05B01h	; ptr to file I/O buffer area
$FIXTK	equ	03529h	; fix task in memory
$FNDEV	equ	01524h	; find device and get UCB address
$FNPAR	equ	027E7h	; find partition by name
$FNTCB	equ	01039h	; find TCB by name
$FNTSK	equ	0100Eh	; find task by name
$FORKQ	equ	05AEDh	; pointer to list of fork blocks
$FREE	equ	01A55h	; free pool memory
$GTUCB	equ	015F4h	; get UCB address
$HOSTN	equ	05AB0h	; host/node name
$IOEND	equ	01DCAh	; end I/O processing for ASTs
$LDCKR	equ	00AA0h	; resume task after checkpoint read
$LDCKW	equ	00AD2h	; queue task to partition after chkpnt write
$LDGO	equ	00A11h	; start task after load
$LGOUT	equ	01741h	; logout user
$LKTCB	equ	008B7h	; link TCB to the specified list
$LOGDV	equ	05AC3h	; ptr to head of logical device assignment list
$LOGIN	equ	016D8h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05ABFh	; total memory size
$MFLGS	equ	05AECh	; MCR flags
$MVTBL	equ	05AEFh	; ptr to head of mounted device list
$PHYDV	equ	05AC1h	; ptr to head of physical device list
$PLIST	equ	05AC5h	; ptr to list of partitions
$POLSZ	equ	05ABDh	; size of pool area
$POOL	equ	05ABBh	; ptr to start of pool area
$REDIR	equ	01573h	; follow UCB redirection links
$REMTK	equ	03520h	; remove task from STD
$RLIST	equ	05ACBh	; ptr to head of ready tasks list
$RNDC	equ	05AD7h	; round-robin interval in ticks
$RNDH	equ	05AD9h	; highest priority for round-robin scheduling
$RNDL	equ	05ADAh	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05AF1h	; scratch buffer address
$SWPC	equ	05ADCh	; swapping interval in ticks
$SWPCT	equ	05ADDh	; swapping interval counter
$SWPRI	equ	05ADBh	; priority range for swapping
$SWSTK	equ	05B03h	; stub to call kernel routines
$TLIST	equ	05AC9h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016C1h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	03532h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05ACDh	; ptr to head of waiting tasks list
IODONE	equ	01DA7h	; end I/O processing
LDRTCB	equ	05AE0h	; LDR... TCB
MCRTCB	equ	05ADEh	; MCR... TCB
NVOK	equ	054FEh	; P112 NV RAM OK flag
NVRAM	equ	054E6h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011C7h	; set task's event flag
SFLAGS	equ	05AE4h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05AA6h	; start of system data area
SYSEND	equ	05B4Ch	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05AB9h	; top of pool area
SYSTYP	equ	05AAEh	; system type
SYSVER	equ	05AACh	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C5Ch	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
