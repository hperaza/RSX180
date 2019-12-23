$ALLOC	equ	01974h	; allocate pool memory
$ALUN	equ	01593h	; assign LUN to device
$ASGN	equ	01403h	; assign logical name to physical device
$CHKPT	equ	0276Dh	; initiate task checkpoint
$CLASN	equ	0147Dh	; delete all logical dev assignments of the given type
$CLIST	equ	05265h	; list of CLI control blocks
$CLKQ	equ	05263h	; ptr to head of clock queue
$CONN	equ	01715h	; connect to task
$CPCB	equ	05261h	; address of PCB of current task
$CPLST	equ	05257h	; ptr to head of checkpoint PCB list
$CTCB	equ	0525Fh	; address of TCB of current task
$DEASN	equ	01466h	; delete logical device assignment
$ERSEQ	equ	0526Fh	; error sequence number
$FCBS	equ	0528Eh	; ptr to head of FCB list
$FEAT	equ	05248h	; feature bits
$FIXTK	equ	02F3Eh	; fix task in memory
$FNDEV	equ	014BEh	; find device and get UCB address
$FNPAR	equ	02556h	; find partition by name
$FNTCB	equ	0103Eh	; find TCB by name
$FNTSK	equ	01013h	; find task by name
$FORKQ	equ	0527Ah	; pointer to list of fork blocks
$FREE	equ	019D3h	; free pool memory
$GTUCB	equ	0157Eh	; get UCB address
$HOSTN	equ	0523Fh	; host/node name
$IOEND	equ	01D1Ah	; end I/O processing for ASTs
$LGOUT	equ	016C7h	; logout user
$LKTCB	equ	0083Ch	; link TCB to the specified list
$LOGDV	equ	05253h	; ptr to head of logical device assignment list
$LOGIN	equ	0165Eh	; login user
$MCOPY	equ	0F226h	; inter-bank memory copy routine
$MEMSZ	equ	0524Fh	; total memory size
$MFLGS	equ	05279h	; MCR flags
$MVTBL	equ	0527Ch	; ptr to head of mounted device list
$PHYDV	equ	05251h	; ptr to head of physical device list
$PLIST	equ	05255h	; ptr to list of partitions
$REMTK	equ	02F35h	; remove task from STD
$RLIST	equ	0525Bh	; ptr to head of ready tasks list
$RNDC	equ	05267h	; round-robin interval in ticks
$SCRBF	equ	0527Eh	; scratch buffer address
$TLIST	equ	05259h	; ptr to head of installed tasks list
$UNFTK	equ	02F47h	; unfix task
$WLIST	equ	0525Dh	; ptr to head of waiting tasks list
BUFFER	equ	05290h	; ptr to file I/O buffer area
IODONE	equ	01CF4h	; end I/O processing
ITBL	equ	0F479h	; space for interrupt table
ITBLP	equ	0F477h	; interrupt table pointer
LDCKR	equ	00A3Ch	; resume task after checkpoint read
LDCKW	equ	00A6Eh	; queue task to partition after chkpnt write
LDGO	equ	009ADh	; start task after load
LDRTCB	equ	0526Bh	; LDR... TCB
MCRTCB	equ	05269h	; MCR... TCB
M_EPT	equ	0F7BDh	; debugger-monitor normal entry point
NVOK	equ	04D27h	; P112 NV RAM OK flag
NVRAM	equ	04D0Fh	; P112 NV RAM contents
POOL	equ	0524Dh	; ptr to start of pool area
POOLSZ	equ	0524Bh	; size of pool area
SCBAR	equ	0F476h	; supervisor mode CBAR value
SETFLG	equ	011B9h	; set task's event flag
SFLAGS	equ	05271h	; system flags
SWSTK	equ	05292h	; stub to call kernel routines
SYSBBR	equ	0F473h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05237h	; start of system data area
SYSEND	equ	052DBh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0EFh	; current system level
SYSTOP	equ	05249h	; top of pool area
SYSVER	equ	0523Dh	; system version number
TICCNT	equ	0F468h	; absolute time count in ticks
TICSEC	equ	0F467h	; ticks per second
TKILL	equ	00BF8h	; abort task
TM_EPT	equ	0FA5Bh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9DDh	; debugger-monitor breakpoint entry point
UCBAR	equ	0F475h	; user mode CBAR value
UCBNAM	equ	0164Bh	; get device name from UCB
UGETB	equ	0F3A9h	; inter-bank get byte routine
UGETBB	equ	0F412h	; inter-bank get byte routine
UGETWB	equ	0F449h	; inter-bank get word routine
UPTIME	equ	0F46Ch	; system up time (ticks and seconds)
UPUTB	equ	0F3CDh	; inter-bank put byte routine
UPUTBB	equ	0F3F5h	; inter-bank put byte routine
UPUTWB	equ	0F42Bh	; inter-bank put word routine
USRBBR	equ	0F474h	; BBR of current executing task
