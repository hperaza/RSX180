$ALLOC	equ	018BDh	; allocate pool memory
$ALUN	equ	014DCh	; assign LUN to device
$ASGN	equ	0134Ch	; assign logical name to physical device
$CLASN	equ	013C6h	; delete all logical dev assignments of the given type
$CLIST	equ	04FC0h	; list of CLI control blocks
$CLKQ	equ	04FBEh	; ptr to head of clock queue
$CONN	equ	0165Eh	; connect to task
$CPCB	equ	04FBCh	; address of PCB of current task
$CPLST	equ	04FB2h	; ptr to head of checkpoint PCB list
$CTCB	equ	04FBAh	; address of TCB of current task
$DEASN	equ	013AFh	; delete logical device assignment
$ERSEQ	equ	04FCAh	; error sequence number
$FCBS	equ	04FE9h	; ptr to head of FCB list
$FEAT	equ	04FA3h	; feature bits
$FIXTK	equ	02CCEh	; fix task in memory
$FNDEV	equ	01407h	; find device and get UCB address
$FNPAR	equ	0246Bh	; find partition by name
$FNTCB	equ	00F91h	; find TCB by name
$FNTSK	equ	00F66h	; find task by name
$FORKQ	equ	04FD5h	; pointer to list of fork blocks
$FREE	equ	0191Ch	; free pool memory
$GTUCB	equ	014C7h	; get UCB address
$HOSTN	equ	04F9Ah	; host/node name
$IOEND	equ	01C63h	; end I/O processing for ASTs
$LGOUT	equ	01610h	; logout user
$LKTCB	equ	0083Ch	; link TCB to the specified list
$LOGDV	equ	04FAEh	; ptr to head of logical device assignment list
$LOGIN	equ	015A7h	; login user
$MCOPY	equ	0F226h	; inter-bank memory copy routine
$MEMSZ	equ	04FAAh	; total memory size
$MFLGS	equ	04FD4h	; MCR flags
$MVTBL	equ	04FD7h	; ptr to head of mounted device list
$PHYDV	equ	04FACh	; ptr to head of physical device list
$PLIST	equ	04FB0h	; ptr to list of partitions
$REMTK	equ	02CC5h	; remove task from STD
$RLIST	equ	04FB6h	; ptr to head of ready tasks list
$RNDC	equ	04FC2h	; round-robin interval in ticks
$SCRBF	equ	04FD9h	; scratch buffer address
$TLIST	equ	04FB4h	; ptr to head of installed tasks list
$UNFTK	equ	02CD7h	; unfix task
$WLIST	equ	04FB8h	; ptr to head of waiting tasks list
BUFFER	equ	04FEBh	; ptr to file I/O buffer area
IODONE	equ	01C3Dh	; end I/O processing
ITBL	equ	0F479h	; space for interrupt table
ITBLP	equ	0F477h	; interrupt table pointer
LDRTCB	equ	04FC6h	; LDR... TCB
MCRTCB	equ	04FC4h	; MCR... TCB
M_EPT	equ	0F7BDh	; debugger-monitor normal entry point
NUMBFS	equ	04FEDh	; number of file I/O buffers
NVOK	equ	04A82h	; P112 NV RAM OK flag
NVRAM	equ	04A6Ah	; P112 NV RAM contents
POOL	equ	04FA8h	; ptr to start of pool area
POOLSZ	equ	04FA6h	; size of pool area
SCBAR	equ	0F476h	; supervisor mode CBAR value
SETFLG	equ	0110Ch	; set task's event flag
SFLAGS	equ	04FCCh	; system flags
SWSTK	equ	04FEEh	; stub to call kernel routines
SYSBBR	equ	0F473h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04F92h	; start of system data area
SYSEND	equ	05037h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0EFh	; current system level
SYSTOP	equ	04FA4h	; top of pool area
SYSVER	equ	04F98h	; system version number
TGO	equ	009ADh	; start task after being loaded
TICCNT	equ	0F468h	; absolute time count in ticks
TICSEC	equ	0F467h	; ticks per second
TKILL	equ	00B8Ah	; abort task
TM_EPT	equ	0FA5Bh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9DDh	; debugger-monitor breakpoint entry point
UCBAR	equ	0F475h	; user mode CBAR value
UCBNAM	equ	01594h	; get device name from UCB
UGETB	equ	0F3A9h	; inter-bank get byte routine
UGETBB	equ	0F412h	; inter-bank get byte routine
UGETWB	equ	0F449h	; inter-bank get word routine
UPTIME	equ	0F46Ch	; system up time (ticks and seconds)
UPUTB	equ	0F3CDh	; inter-bank put byte routine
UPUTBB	equ	0F3F5h	; inter-bank put byte routine
UPUTWB	equ	0F42Bh	; inter-bank put word routine
USRBBR	equ	0F474h	; BBR of current executing task
