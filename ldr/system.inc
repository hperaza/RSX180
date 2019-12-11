$ALLOC	equ	018BEh	; allocate pool memory
$ALUN	equ	014DDh	; assign LUN to device
$ASGN	equ	0134Dh	; assign logical name to physical device
$CLASN	equ	013C7h	; delete all logical dev assignments of the given type
$CLIST	equ	04F82h	; list of CLI control blocks
$CLKQ	equ	04F80h	; ptr to head of clock queue
$CONN	equ	0165Fh	; connect to task
$CPCB	equ	04F7Eh	; address of PCB of current task
$CPLST	equ	04F74h	; ptr to head of checkpoint PCB list
$CTCB	equ	04F7Ch	; address of TCB of current task
$DEASN	equ	013B0h	; delete logical device assignment
$ERSEQ	equ	04F8Ch	; error sequence number
$FCBS	equ	04FABh	; ptr to head of FCB list
$FEAT	equ	04F65h	; feature bits
$FIXTK	equ	02C90h	; fix task in memory
$FNDEV	equ	01408h	; find device and get UCB address
$FNPAR	equ	02457h	; find partition by name
$FNTCB	equ	00F92h	; find TCB by name
$FNTSK	equ	00F67h	; find task by name
$FORKQ	equ	04F97h	; pointer to list of fork blocks
$FREE	equ	0191Dh	; free pool memory
$GTUCB	equ	014C8h	; get UCB address
$HOSTN	equ	04F5Ch	; host/node name
$LGOUT	equ	01611h	; logout user
$LKTCB	equ	0083Ch	; link TCB to the specified list
$LOGDV	equ	04F70h	; ptr to head of logical device assignment list
$LOGIN	equ	015A8h	; login user
$MCOPY	equ	0F226h	; inter-bank memory copy routine
$MEMSZ	equ	04F6Ch	; total memory size
$MFLGS	equ	04F96h	; MCR flags
$MVTBL	equ	04F99h	; ptr to head of mounted device list
$PHYDV	equ	04F6Eh	; ptr to head of physical device list
$PLIST	equ	04F72h	; ptr to list of partitions
$REMTK	equ	02C87h	; remove task from STD
$RLIST	equ	04F78h	; ptr to head of ready tasks list
$RNDC	equ	04F84h	; round-robin interval in ticks
$SCRBF	equ	04F9Bh	; scratch buffer address
$TLIST	equ	04F76h	; ptr to head of installed tasks list
$UNFTK	equ	02C99h	; unfix task
$WLIST	equ	04F7Ah	; ptr to head of waiting tasks list
BUFFER	equ	04FADh	; ptr to file I/O buffer area
IODONE	equ	01C3Eh	; end I/O processing
ITBL	equ	0F479h	; space for interrupt table
ITBLP	equ	0F477h	; interrupt table pointer
LDRTCB	equ	04F88h	; LDR... TCB
MCRTCB	equ	04F86h	; MCR... TCB
M_EPT	equ	0F7BDh	; debugger-monitor normal entry point
NUMBFS	equ	04FAFh	; number of file I/O buffers
NVOK	equ	04A44h	; P112 NV RAM OK flag
NVRAM	equ	04A2Ch	; P112 NV RAM contents
POOL	equ	04F6Ah	; ptr to start of pool area
POOLSZ	equ	04F68h	; size of pool area
SCBAR	equ	0F476h	; supervisor mode CBAR value
SETFLG	equ	0110Dh	; set task's event flag
SFLAGS	equ	04F8Eh	; system flags
SWSTK	equ	04FB0h	; stub to call kernel routines
SYSBBR	equ	0F473h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04F54h	; start of system data area
SYSEND	equ	04FF9h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0EFh	; current system level
SYSTOP	equ	04F66h	; top of pool area
SYSVER	equ	04F5Ah	; system version number
TGO	equ	009ADh	; start task after being loaded
TICCNT	equ	0F468h	; absolute time count in ticks
TICSEC	equ	0F467h	; ticks per second
TKILL	equ	00B8Ah	; abort task
TM_EPT	equ	0FA5Bh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9DDh	; debugger-monitor breakpoint entry point
UCBAR	equ	0F475h	; user mode CBAR value
UCBNAM	equ	01595h	; get device name from UCB
UGETB	equ	0F3A9h	; inter-bank get byte routine
UGETBB	equ	0F412h	; inter-bank get byte routine
UGETWB	equ	0F449h	; inter-bank get word routine
UPTIME	equ	0F46Ch	; system up time (ticks and seconds)
UPUTB	equ	0F3CDh	; inter-bank put byte routine
UPUTBB	equ	0F3F5h	; inter-bank put byte routine
UPUTWB	equ	0F42Bh	; inter-bank put word routine
USRBBR	equ	0F474h	; BBR of current executing task
