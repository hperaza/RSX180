$ALLOC	equ	019EDh	; allocate pool memory
$ALUN	equ	01600h	; assign LUN to device
$ASGN	equ	01460h	; assign logical name to physical device
$ASNTP	equ	02800h	; assign next task to partition
$CHKPT	equ	029E8h	; initiate task checkpoint
$CLASN	equ	014DAh	; delete all logical dev assignments of the given type
$CLIST	equ	05985h	; list of CLI control blocks
$CLKQ	equ	05983h	; ptr to head of clock queue
$CONN	equ	0176Dh	; connect to task
$CPCB	equ	05981h	; address of PCB of current task
$CPLST	equ	05977h	; ptr to head of checkpoint PCB list
$CTCB	equ	0597Fh	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	014C3h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05992h	; error sequence number
$FEAT	equ	0595Fh	; feature bits
$FILBF	equ	059B1h	; ptr to file I/O buffer area
$FIXTK	equ	034C1h	; fix task in memory
$FNDEV	equ	0151Bh	; find device and get UCB address
$FNPAR	equ	027A8h	; find partition by name
$FNTCB	equ	01030h	; find TCB by name
$FNTSK	equ	01005h	; find task by name
$FORKQ	equ	0599Dh	; pointer to list of fork blocks
$FREE	equ	01A4Ch	; free pool memory
$GTUCB	equ	015EBh	; get UCB address
$HOSTN	equ	05960h	; host/node name
$IOEND	equ	01DC7h	; end I/O processing for ASTs
$LDCKR	equ	00A97h	; resume task after checkpoint read
$LDCKW	equ	00AC9h	; queue task to partition after chkpnt write
$LDGO	equ	00A08h	; start task after load
$LGOUT	equ	01738h	; logout user
$LKTCB	equ	008AEh	; link TCB to the specified list
$LOGDV	equ	05973h	; ptr to head of logical device assignment list
$LOGIN	equ	016CFh	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	0596Fh	; total memory size
$MFLGS	equ	0599Ch	; MCR flags
$MVTBL	equ	0599Fh	; ptr to head of mounted device list
$PHYDV	equ	05971h	; ptr to head of physical device list
$PLIST	equ	05975h	; ptr to list of partitions
$POLSZ	equ	0596Dh	; size of pool area
$POOL	equ	0596Bh	; ptr to start of pool area
$REDIR	equ	0156Ah	; follow UCB redirection links
$REMTK	equ	034B8h	; remove task from STD
$RLIST	equ	0597Bh	; ptr to head of ready tasks list
$RNDC	equ	05987h	; round-robin interval in ticks
$RNDH	equ	05989h	; highest priority for round-robin scheduling
$RNDL	equ	0598Ah	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	059A1h	; scratch buffer address
$SWPC	equ	0598Ch	; swapping interval in ticks
$SWPCT	equ	0598Dh	; swapping interval counter
$SWPRI	equ	0598Bh	; priority range for swapping
$SWSTK	equ	059B3h	; stub to call kernel routines
$TLIST	equ	05979h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	016B8h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	034CAh	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	0597Dh	; ptr to head of waiting tasks list
IODONE	equ	01DA1h	; end I/O processing
LDRTCB	equ	05990h	; LDR... TCB
MCRTCB	equ	0598Eh	; MCR... TCB
NVOK	equ	053B4h	; P112 NV RAM OK flag
NVRAM	equ	0539Ch	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011BEh	; set task's event flag
SFLAGS	equ	05994h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05956h	; start of system data area
SYSEND	equ	059FCh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05969h	; top of pool area
SYSTYP	equ	0595Eh	; system type
SYSVER	equ	0595Ch	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C53h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
