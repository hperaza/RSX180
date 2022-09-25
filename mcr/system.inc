$ALLOC	equ	01993h	; allocate pool memory
$ALUN	equ	015A2h	; assign LUN to device
$ASGN	equ	01402h	; assign logical name to physical device
$ASNTP	equ	02882h	; assign next task to partition
$CHKPT	equ	02A6Ah	; initiate task checkpoint
$CLASN	equ	0147Ch	; delete all logical dev assignments of the given type
$CLIST	equ	05EA1h	; list of CLI control blocks
$CLKQ	equ	05E9Fh	; ptr to head of clock queue
$CONN	equ	01713h	; connect to task
$CPCB	equ	05E9Dh	; address of PCB of current task
$CPLST	equ	05E93h	; ptr to head of checkpoint PCB list
$CTCB	equ	05E9Bh	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	01465h	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	05EAEh	; error sequence number
$FEAT	equ	05E7Bh	; feature bits
$FILBF	equ	05ECDh	; ptr to file I/O buffer area
$FIXTK	equ	03615h	; fix task in memory
$FNDEV	equ	014BDh	; find device and get UCB address
$FNPAR	equ	02829h	; find partition by name
$FNTCB	equ	0100Dh	; find TCB by name
$FNTSK	equ	00FE2h	; find task by name
$FORKQ	equ	05EB9h	; pointer to list of fork blocks
$FREE	equ	019F2h	; free pool memory
$GTUCB	equ	0158Dh	; get UCB address
$HOSTN	equ	05E7Ch	; host/node name
$IOEND	equ	01DDBh	; end I/O processing for ASTs
$LDCKR	equ	00A9Bh	; resume task after checkpoint read
$LDCKW	equ	00ACDh	; queue task to partition after chkpnt write
$LDGO	equ	009FEh	; start task after load
$LGOUT	equ	016DEh	; logout user
$LKTCB	equ	008A4h	; link TCB to the specified list
$LOGDV	equ	05E8Fh	; ptr to head of logical device assignment list
$LOGIN	equ	01671h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05E8Bh	; total memory size
$MFLGS	equ	05EB8h	; MCR flags
$MVTBL	equ	05EBBh	; ptr to head of mounted device list
$PHYDV	equ	05E8Dh	; ptr to head of physical device list
$PLIST	equ	05E91h	; ptr to list of partitions
$POLSZ	equ	05E89h	; size of pool area
$POOL	equ	05E87h	; ptr to start of pool area
$REDIR	equ	0150Ch	; follow UCB redirection links
$REMTK	equ	0360Ch	; remove task from STD
$RLIST	equ	05E97h	; ptr to head of ready tasks list
$RNDC	equ	05EA3h	; round-robin interval in ticks
$RNDH	equ	05EA5h	; highest priority for round-robin scheduling
$RNDL	equ	05EA6h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05EBDh	; scratch buffer address
$SWPC	equ	05EA8h	; swapping interval in ticks
$SWPCT	equ	05EA9h	; swapping interval counter
$SWPRI	equ	05EA7h	; priority range for swapping
$SWSTK	equ	05ECFh	; stub to call kernel routines
$TLIST	equ	05E95h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	0165Ah	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	0361Eh	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$VALBF	equ	0200Bh	; validate buffer (current task)
$VALTB	equ	01FE8h	; validate buffer (arbitrary task)
$WLIST	equ	05E99h	; ptr to head of waiting tasks list
IODONE	equ	01DB8h	; end I/O processing
LDRTCB	equ	05EACh	; LDR... TCB
MCRTCB	equ	05EAAh	; MCR... TCB
NVOK	equ	0589Ah	; P112 NV RAM OK flag
NVRAM	equ	05882h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	01188h	; set task's event flag
SFLAGS	equ	05EB0h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05E72h	; start of system data area
SYSEND	equ	05F18h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05E85h	; top of pool area
SYSTYP	equ	05E7Ah	; system type
SYSVER	equ	05E78h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C30h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
