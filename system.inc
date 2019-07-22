$ALLOC	equ	01962h	; allocate pool memory
$ALUN	equ	01584h	; assign LUN to device
$ASGN	equ	013EEh	; assign logical name to physical device
$CLASN	equ	0146Ch	; delete all logical dev assignments of the given type
$CLIST	equ	04EA1h	; list of CLI control blocks
$CLKQ	equ	04E9Fh	; ptr to head of clock queue
$CONN	equ	01706h	; connect to task
$CPCB	equ	04E9Dh	; address of PCB of current task
$CTCB	equ	04E9Bh	; address of TCB of current task
$DEASN	equ	01453h	; delete logical device assignment
$ERSEQ	equ	04EA9h	; error sequence number
$FCBS	equ	04EC8h	; ptr to head of FCB list
$FIXTK	equ	02BBEh	; fix task in memory
$FNDEV	equ	014AFh	; find device and get UCB address
$FNPAR	equ	024D7h	; find partition by name
$FNTCB	equ	00FD6h	; find TCB by name
$FNTSK	equ	00FABh	; find task by name
$FORKQ	equ	04EB4h	; pointer to list of fork blocks
$FREE	equ	019C1h	; free pool memory
$GTUCB	equ	0156Fh	; get UCB address
$HOSTN	equ	04E7Eh	; host/node name
$LGOUT	equ	016B8h	; logout user
$LKTCB	equ	008B2h	; link TCB to the specified list
$LOGDV	equ	04E91h	; ptr to head of logical device assignment list
$LOGIN	equ	0164Fh	; login user
$MCOPY	equ	0F22Bh	; inter-bank memory copy routine
$MEMSZ	equ	04E8Dh	; total memory size
$MFLGS	equ	04EB3h	; MCR flags
$MVTBL	equ	04EB6h	; ptr to head of mounted device list
$PHYDV	equ	04E8Fh	; ptr to head of physical device list
$PLIST	equ	04E93h	; ptr to list of partitions
$RLIST	equ	04E97h	; ptr to head of ready tasks list
$SCRBF	equ	04EB8h	; scratch buffer address
$TLIST	equ	04E95h	; ptr to head of installed tasks list
$UNFTK	equ	02BC7h	; unfix task
$WLIST	equ	04E99h	; ptr to head of waiting tasks list
BUFFER	equ	04ECAh	; ptr to file I/O buffer area
ITBL	equ	0F47Eh	; space for interrupt table
ITBLP	equ	0F47Ch	; interrupt table pointer
LDRTCB	equ	04EA5h	; LDR... TCB
MCRTCB	equ	04EA3h	; MCR... TCB
M_EPT	equ	0F7C2h	; debugger-monitor normal entry point
NUMBFS	equ	04ECCh	; number of file I/O buffers
NVOK	equ	04966h	; P112 NV RAM OK flag
NVRAM	equ	0494Eh	; P112 NV RAM contents
POOL	equ	04E8Bh	; ptr to start of pool area
POOLSZ	equ	04E89h	; size of pool area
REMTSK	equ	02BB5h	; remove task from STD
SCBAR	equ	0F47Bh	; supervisor mode CBAR value
SETFLG	equ	0118Bh	; set task's event flag
SFLAGS	equ	04EABh	; system flags
SWSTK	equ	04ECDh	; stub to call kernel routines
SYSBBR	equ	0F478h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	04E76h	; start of system data area
SYSEND	equ	04F16h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F3h	; current system level
SYSTOP	equ	04E87h	; top of pool area
SYSVER	equ	04E7Ch	; system version number
TGO	equ	00A2Ch	; start task after being loaded
TICCNT	equ	0F46Dh	; absolute time count in ticks
TICSEC	equ	0F46Ch	; ticks per second
TKILL	equ	00C16h	; abort task
TM_EPT	equ	0FA60h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9E2h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F47Ah	; user mode CBAR value
UCBNAM	equ	0163Ch	; get device name from UCB
UGETB	equ	0F3AEh	; inter-bank get byte routine
UGETBB	equ	0F417h	; inter-bank get byte routine
UGETWB	equ	0F44Eh	; inter-bank get word routine
UPTIME	equ	0F471h	; system up time (ticks and seconds)
UPUTB	equ	0F3D2h	; inter-bank put byte routine
UPUTBB	equ	0F3FAh	; inter-bank put byte routine
UPUTWB	equ	0F430h	; inter-bank put word routine
USRBBR	equ	0F479h	; BBR of current executing task
