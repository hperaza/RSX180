$ALLOC	equ	019F6h	; allocate pool memory
$ALUN	equ	01609h	; assign LUN to device
$ASGN	equ	01469h	; assign logical name to physical device
$ASNTP	equ	02824h	; assign next task to partition
$CHKPT	equ	02A0Ch	; initiate task checkpoint
$CLASN	equ	014E3h	; delete all logical dev assignments of the given type
$CLIST	equ	059A9h	; list of CLI control blocks
$CLKQ	equ	059A7h	; ptr to head of clock queue
$CONN	equ	01776h	; connect to task
$CPCB	equ	059A5h	; address of PCB of current task
$CPLST	equ	0599Bh	; ptr to head of checkpoint PCB list
$CTCB	equ	059A3h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014CCh	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	059B6h	; error sequence number
$FEAT	equ	05983h	; feature bits
$FILBF	equ	059D5h	; ptr to file I/O buffer area
$FIXTK	equ	034E5h	; fix task in memory
$FNDEV	equ	01524h	; find device and get UCB address
$FNPAR	equ	027CCh	; find partition by name
$FNTCB	equ	01039h	; find TCB by name
$FNTSK	equ	0100Eh	; find task by name
$FORKQ	equ	059C1h	; pointer to list of fork blocks
$FREE	equ	01A55h	; free pool memory
$GTUCB	equ	015F4h	; get UCB address
$HOSTN	equ	05984h	; host/node name
$IOEND	equ	01DD0h	; end I/O processing for ASTs
$LDCKR	equ	00AA0h	; resume task after checkpoint read
$LDCKW	equ	00AD2h	; queue task to partition after chkpnt write
$LDGO	equ	00A11h	; start task after load
$LGOUT	equ	01741h	; logout user
$LKTCB	equ	008B7h	; link TCB to the specified list
$LOGDV	equ	05997h	; ptr to head of logical device assignment list
$LOGIN	equ	016D8h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05993h	; total memory size
$MFLGS	equ	059C0h	; MCR flags
$MVTBL	equ	059C3h	; ptr to head of mounted device list
$PHYDV	equ	05995h	; ptr to head of physical device list
$PLIST	equ	05999h	; ptr to list of partitions
$POLSZ	equ	05991h	; size of pool area
$POOL	equ	0598Fh	; ptr to start of pool area
$REDIR	equ	01573h	; follow UCB redirection links
$REMTK	equ	034DCh	; remove task from STD
$RLIST	equ	0599Fh	; ptr to head of ready tasks list
$RNDC	equ	059ABh	; round-robin interval in ticks
$RNDH	equ	059ADh	; highest priority for round-robin scheduling
$RNDL	equ	059AEh	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	059C5h	; scratch buffer address
$SWPC	equ	059B0h	; swapping interval in ticks
$SWPCT	equ	059B1h	; swapping interval counter
$SWPRI	equ	059AFh	; priority range for swapping
$SWSTK	equ	059D7h	; stub to call kernel routines
$TLIST	equ	0599Dh	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016C1h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	034EEh	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	059A1h	; ptr to head of waiting tasks list
IODONE	equ	01DAAh	; end I/O processing
LDRTCB	equ	059B4h	; LDR... TCB
MCRTCB	equ	059B2h	; MCR... TCB
NVOK	equ	053D8h	; P112 NV RAM OK flag
NVRAM	equ	053C0h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011C7h	; set task's event flag
SFLAGS	equ	059B8h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0597Ah	; start of system data area
SYSEND	equ	05A20h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	0598Dh	; top of pool area
SYSTYP	equ	05982h	; system type
SYSVER	equ	05980h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C5Ch	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
