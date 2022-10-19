$ALLOC	equ	0148Eh	; allocate pool memory
$ALUN	equ	01087h	; assign LUN to device
$ASGN	equ	00EE7h	; assign logical name to physical device
$ASNTP	equ	0237Dh	; assign next task to partition
$AVAIL	equ	01577h	; compute available pool memory
$CHKPT	equ	02565h	; initiate task checkpoint
$CLASN	equ	00F61h	; delete all logical dev assignments of the given type
$CLIST	equ	05981h	; list of CLI control blocks
$CLKQ	equ	0597Fh	; ptr to head of clock queue
$CONN	equ	011FAh	; connect to task
$CPCB	equ	0597Dh	; address of PCB of current task
$CPLST	equ	05973h	; ptr to head of checkpoint PCB list
$CTCB	equ	0597Bh	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	00F4Ah	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	0598Eh	; error sequence number
$FEAT	equ	0595Bh	; feature bits
$FILBF	equ	059ADh	; ptr to file I/O buffer area
$FIXTK	equ	03110h	; fix task in memory
$FNDEV	equ	00FA2h	; find device and get UCB address
$FNPAR	equ	02324h	; find partition by name
$FNTCB	equ	00AF2h	; find TCB by name
$FNTSK	equ	00AC7h	; find task by name
$FORKQ	equ	05999h	; pointer to list of fork blocks
$FREE	equ	014EDh	; free pool memory
$GTUCB	equ	01072h	; get UCB address
$HOSTN	equ	0595Ch	; host/node name
$IOEND	equ	018D6h	; end I/O processing for ASTs
$LDCKR	equ	00580h	; resume task after checkpoint read
$LDCKW	equ	005B2h	; queue task to partition after chkpnt write
$LDGO	equ	004E3h	; start task after load
$LGOUT	equ	011C5h	; logout user
$LKTCB	equ	00389h	; link TCB to the specified list
$LOGDV	equ	0596Fh	; ptr to head of logical device assignment list
$LOGIN	equ	01156h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	0596Bh	; total memory size
$MFLGS	equ	05998h	; MCR flags
$MVTBL	equ	0599Bh	; ptr to head of mounted device list
$PHYDV	equ	0596Dh	; ptr to head of physical device list
$PLIST	equ	05971h	; ptr to list of partitions
$POLSZ	equ	05969h	; size of pool area
$POOL	equ	05967h	; ptr to start of pool area
$REDIR	equ	00FF1h	; follow UCB redirection links
$REMTK	equ	03107h	; remove task from STD
$RLIST	equ	05977h	; ptr to head of ready tasks list
$RNDC	equ	05983h	; round-robin interval in ticks
$RNDH	equ	05985h	; highest priority for round-robin scheduling
$RNDL	equ	05986h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	0599Dh	; scratch buffer address
$SWPC	equ	05988h	; swapping interval in ticks
$SWPCT	equ	05989h	; swapping interval counter
$SWPRI	equ	05987h	; priority range for swapping
$SWSTK	equ	059AFh	; stub to call kernel routines
$TLIST	equ	05975h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	0113Fh	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	03119h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$VALBF	equ	01B06h	; validate buffer (current task)
$VALTB	equ	01AE3h	; validate buffer (arbitrary task)
$WLIST	equ	05979h	; ptr to head of waiting tasks list
IODONE	equ	018B3h	; end I/O processing
LDRTCB	equ	0598Ch	; LDR... TCB
MCRTCB	equ	0598Ah	; MCR... TCB
NVOK	equ	0537Ah	; P112 NV RAM OK flag
NVRAM	equ	05362h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	00C6Dh	; set task's event flag
SFLAGS	equ	05990h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05952h	; start of system data area
SYSEND	equ	059F8h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05965h	; top of pool area
SYSTYP	equ	0595Ah	; system type
SYSVER	equ	05958h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00715h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
