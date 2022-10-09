$ALLOC	equ	0144Dh	; allocate pool memory
$ALUN	equ	0105Ah	; assign LUN to device
$ASGN	equ	00EBAh	; assign logical name to physical device
$ASNTP	equ	0233Ch	; assign next task to partition
$CHKPT	equ	02524h	; initiate task checkpoint
$CLASN	equ	00F34h	; delete all logical dev assignments of the given type
$CLIST	equ	0593Eh	; list of CLI control blocks
$CLKQ	equ	0593Ch	; ptr to head of clock queue
$CONN	equ	011CDh	; connect to task
$CPCB	equ	0593Ah	; address of PCB of current task
$CPLST	equ	05930h	; ptr to head of checkpoint PCB list
$CTCB	equ	05938h	; address of TCB of current task
$DBMON	equ	0F756h	; debugger-monitor main entry point
$DBTRP	equ	0F976h	; debugger-monitor bpt entry
$DEASN	equ	00F1Dh	; delete logical device assignment
$DMTRP	equ	0F9F4h	; debugger-monitor bpt entry with message
$ERSEQ	equ	0594Bh	; error sequence number
$FEAT	equ	05918h	; feature bits
$FILBF	equ	0596Ah	; ptr to file I/O buffer area
$FIXTK	equ	030CFh	; fix task in memory
$FNDEV	equ	00F75h	; find device and get UCB address
$FNPAR	equ	022E3h	; find partition by name
$FNTCB	equ	00AC5h	; find TCB by name
$FNTSK	equ	00A9Ah	; find task by name
$FORKQ	equ	05956h	; pointer to list of fork blocks
$FREE	equ	014ACh	; free pool memory
$GTUCB	equ	01045h	; get UCB address
$HOSTN	equ	05919h	; host/node name
$IOEND	equ	01895h	; end I/O processing for ASTs
$LDCKR	equ	00553h	; resume task after checkpoint read
$LDCKW	equ	00585h	; queue task to partition after chkpnt write
$LDGO	equ	004B6h	; start task after load
$LGOUT	equ	01198h	; logout user
$LKTCB	equ	0035Ch	; link TCB to the specified list
$LOGDV	equ	0592Ch	; ptr to head of logical device assignment list
$LOGIN	equ	01129h	; login user
$MCOPY	equ	0F20Bh	; inter-bank memory copy routine
$MEMSZ	equ	05928h	; total memory size
$MFLGS	equ	05955h	; MCR flags
$MVTBL	equ	05958h	; ptr to head of mounted device list
$PHYDV	equ	0592Ah	; ptr to head of physical device list
$PLIST	equ	0592Eh	; ptr to list of partitions
$POLSZ	equ	05926h	; size of pool area
$POOL	equ	05924h	; ptr to start of pool area
$REDIR	equ	00FC4h	; follow UCB redirection links
$REMTK	equ	030C6h	; remove task from STD
$RLIST	equ	05934h	; ptr to head of ready tasks list
$RNDC	equ	05940h	; round-robin interval in ticks
$RNDH	equ	05942h	; highest priority for round-robin scheduling
$RNDL	equ	05943h	; lowest priority for round-robin scheduling
$SBANK	equ	0F40Ch	; system bank number
$SCRBF	equ	0595Ah	; scratch buffer address
$SWPC	equ	05945h	; swapping interval in ticks
$SWPCT	equ	05946h	; swapping interval counter
$SWPRI	equ	05944h	; priority range for swapping
$SWSTK	equ	0596Ch	; stub to call kernel routines
$TLIST	equ	05932h	; ptr to head of installed tasks list
$UBANK	equ	0F40Dh	; bank of current task
$UCBDN	equ	01112h	; get device name and unit from UCB
$UGETB	equ	0F38Eh	; inter-bank get byte routine
$UGETW	equ	0F3C4h	; inter-bank get word routine
$UNFTK	equ	030D8h	; unfix task
$UPUTB	equ	0F3A7h	; inter-bank put byte routine
$UPUTW	equ	0F3E2h	; inter-bank put word routine
$VALBF	equ	01AC5h	; validate buffer (current task)
$VALTB	equ	01AA2h	; validate buffer (arbitrary task)
$WLIST	equ	05936h	; ptr to head of waiting tasks list
IODONE	equ	01872h	; end I/O processing
LDRTCB	equ	05949h	; LDR... TCB
MCRTCB	equ	05947h	; MCR... TCB
NVOK	equ	05337h	; P112 NV RAM OK flag
NVRAM	equ	0531Fh	; P112 NV RAM contents
SCBAR	equ	0F40Fh	; supervisor mode CBAR value
SETFLG	equ	00C40h	; set task's event flag
SFLAGS	equ	0594Dh	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0590Fh	; start of system data area
SYSEND	equ	059B5h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0D0h	; current system level
SYSTOP	equ	05922h	; top of pool area
SYSTYP	equ	05917h	; system type
SYSVER	equ	05915h	; system version number
TICCNT	equ	0F401h	; absolute time count in ticks
TICSEC	equ	0F400h	; ticks per second
TKILL	equ	006E8h	; abort task
UCBAR	equ	0F40Eh	; user mode CBAR value
UPTIME	equ	0F405h	; system up time (ticks and seconds)
