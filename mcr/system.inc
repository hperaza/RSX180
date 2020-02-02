$ALLOC	equ	01996h	; allocate pool memory
$ALUN	equ	015A9h	; assign LUN to device
$ASGN	equ	01409h	; assign logical name to physical device
$ASNTP	equ	0276Fh	; assign next task to partition
$CHKPT	equ	02957h	; initiate task checkpoint
$CLASN	equ	01483h	; delete all logical dev assignments of the given type
$CLIST	equ	057EBh	; list of CLI control blocks
$CLKQ	equ	057E9h	; ptr to head of clock queue
$CONN	equ	01716h	; connect to task
$CPCB	equ	057E7h	; address of PCB of current task
$CPLST	equ	057DDh	; ptr to head of checkpoint PCB list
$CTCB	equ	057E5h	; address of TCB of current task
$DEASN	equ	0146Ch	; delete logical device assignment
$ERSEQ	equ	057F8h	; error sequence number
$FEAT	equ	057CEh	; feature bits
$FILBF	equ	05817h	; ptr to file I/O buffer area
$FIXTK	equ	033DFh	; fix task in memory
$FNDEV	equ	014C4h	; find device and get UCB address
$FNPAR	equ	02717h	; find partition by name
$FNTCB	equ	0106Ch	; find TCB by name
$FNTSK	equ	01041h	; find task by name
$FORKQ	equ	05803h	; pointer to list of fork blocks
$FREE	equ	019F5h	; free pool memory
$GTUCB	equ	01594h	; get UCB address
$HOSTN	equ	057C5h	; host/node name
$IOEND	equ	01D40h	; end I/O processing for ASTs
$LDCKR	equ	00A97h	; resume task after checkpoint read
$LDCKW	equ	00AC9h	; queue task to partition after chkpnt write
$LDGO	equ	00A08h	; start task after load
$LGOUT	equ	016E1h	; logout user
$LKTCB	equ	008AEh	; link TCB to the specified list
$LOGDV	equ	057D9h	; ptr to head of logical device assignment list
$LOGIN	equ	01678h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	057D5h	; total memory size
$MFLGS	equ	05802h	; MCR flags
$MVTBL	equ	05805h	; ptr to head of mounted device list
$PHYDV	equ	057D7h	; ptr to head of physical device list
$PLIST	equ	057DBh	; ptr to list of partitions
$POLSZ	equ	057D3h	; size of pool area
$POOL	equ	057D1h	; ptr to start of pool area
$REDIR	equ	01513h	; follow UCB redirection links
$REMTK	equ	033D6h	; remove task from STD
$RLIST	equ	057E1h	; ptr to head of ready tasks list
$RNDC	equ	057EDh	; round-robin interval in ticks
$RNDH	equ	057EFh	; highest priority for round-robin scheduling
$RNDL	equ	057F0h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	05807h	; scratch buffer address
$SWPC	equ	057F2h	; swapping interval in ticks
$SWPCT	equ	057F3h	; swapping interval counter
$SWPRI	equ	057F1h	; priority range for swapping
$SWSTK	equ	05819h	; stub to call kernel routines
$TLIST	equ	057DFh	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	01661h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	033E8h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$WLIST	equ	057E3h	; ptr to head of waiting tasks list
IODONE	equ	01D1Ah	; end I/O processing
LDRTCB	equ	057F6h	; LDR... TCB
MCRTCB	equ	057F4h	; MCR... TCB
M_EPT	equ	0F756h	; debugger-monitor normal entry point
NVOK	equ	05211h	; P112 NV RAM OK flag
NVRAM	equ	051F9h	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	011E6h	; set task's event flag
SFLAGS	equ	057FAh	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	057BDh	; start of system data area
SYSEND	equ	05862h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	057CFh	; top of pool area
SYSVER	equ	057C3h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	00C53h	; abort task
TM_EPT	equ	0F9F4h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F976h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
