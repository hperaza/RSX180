$ALLOC	equ	019DDh	; allocate pool memory
$ALUN	equ	015F0h	; assign LUN to device
$ASGN	equ	01450h	; assign logical name to physical device
$ASNTP	equ	027E2h	; assign next task to partition
$CHKPT	equ	029CAh	; initiate task checkpoint
$CLASN	equ	014CAh	; delete all logical dev assignments of the given type
$CLIST	equ	05EE8h	; list of CLI control blocks
$CLKQ	equ	05EE6h	; ptr to head of clock queue
$CONN	equ	0175Dh	; connect to task
$CPCB	equ	05EE4h	; address of PCB of current task
$CPLST	equ	05EDAh	; ptr to head of checkpoint PCB list
$CTCB	equ	05EE2h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014B3h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05EF5h	; error sequence number
$FEAT	equ	05ECBh	; feature bits
$FILBF	equ	05F14h	; ptr to file I/O buffer area
$FIXTK	equ	03498h	; fix task in memory
$FNDEV	equ	0150Bh	; find device and get UCB address
$FNPAR	equ	0278Ah	; find partition by name
$FNTCB	equ	01034h	; find TCB by name
$FNTSK	equ	01009h	; find task by name
$FORKQ	equ	05F00h	; pointer to list of fork blocks
$FREE	equ	01A3Ch	; free pool memory
$GTUCB	equ	015DBh	; get UCB address
$HOSTN	equ	05EC2h	; host/node name
$IOEND	equ	01DADh	; end I/O processing for ASTs
$LDCKR	equ	00A97h	; resume task after checkpoint read
$LDCKW	equ	00AC9h	; queue task to partition after chkpnt write
$LDGO	equ	00A08h	; start task after load
$LGOUT	equ	01728h	; logout user
$LKTCB	equ	008AEh	; link TCB to the specified list
$LOGDV	equ	05ED6h	; ptr to head of logical device assignment list
$LOGIN	equ	016BFh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05ED2h	; total memory size
$MFLGS	equ	05EFFh	; MCR flags
$MVTBL	equ	05F02h	; ptr to head of mounted device list
$PHYDV	equ	05ED4h	; ptr to head of physical device list
$PLIST	equ	05ED8h	; ptr to list of partitions
$POLSZ	equ	05ED0h	; size of pool area
$POOL	equ	05ECEh	; ptr to start of pool area
$REDIR	equ	0155Ah	; follow UCB redirection links
$REMTK	equ	0348Fh	; remove task from STD
$RLIST	equ	05EDEh	; ptr to head of ready tasks list
$RNDC	equ	05EEAh	; round-robin interval in ticks
$RNDH	equ	05EECh	; highest priority for round-robin scheduling
$RNDL	equ	05EEDh	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05F04h	; scratch buffer address
$SWPC	equ	05EEFh	; swapping interval in ticks
$SWPCT	equ	05EF0h	; swapping interval counter
$SWPRI	equ	05EEEh	; priority range for swapping
$SWSTK	equ	05F16h	; stub to call kernel routines
$TLIST	equ	05EDCh	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016A8h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	034A1h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	05EE0h	; ptr to head of waiting tasks list
IODONE	equ	01D87h	; end I/O processing
LDRTCB	equ	05EF3h	; LDR... TCB
MCRTCB	equ	05EF1h	; MCR... TCB
NVOK	equ	0544Dh	; P112 NV RAM OK flag
NVRAM	equ	05435h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011AEh	; set task's event flag
SFLAGS	equ	05EF7h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05EBAh	; start of system data area
SYSEND	equ	05F5Fh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05ECCh	; top of pool area
SYSVER	equ	05EC0h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C53h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
