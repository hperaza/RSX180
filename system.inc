APPBBR	equ	0F45Eh	; first available BBR after system
ASSIGN	equ	01C66h	; assign logical name to physical device
BUFFER	equ	05998h	; ptr to file I/O buffer area
BUFMEM	equ	0599Ah	; size of file I/O buffer area
CLILST	equ	0A85Fh	; list of CLI control blocks
CLKQ	equ	0A844h	; ptr to head of clock queue
CONN	equ	01FB1h	; connect to task
CTCB	equ	0A842h	; address of TCB of current task
DEASGN	equ	01CD0h	; delete logical device assignment
ERRSEQ	equ	0A852h	; error sequence number
FCBS	equ	05996h	; ptr to head of FCB linked list
FCPTCB	equ	0A84Ch	; SYSFCP TCB
FIXTSK	equ	03233h	; fix task in memory
FNDDEV	equ	01D0Bh	; find device and get DCB address
FORKQ	equ	0A861h	; pointer to list of fork blocks
GETUCB	equ	01D71h	; get UCB address
HOSTNM	equ	0A80Dh	; host/node name
IHPOOL	equ	0F6A8h	; interrupt handler pool
IHPTR	equ	0F6A6h	; ptr to free space in IHPOOL
IHSP	equ	0F6A4h	; saved SP when servicing interrupts
IHSTK	equ	0F6A4h	; top of stack for interrupt service routines
INSTSK	equ	03224h	; enter task into STD
ITBL	equ	0F464h	; space for interrupt table
ITBLP	equ	0F462h	; interrupt table pointer
KALLOC	equ	021C9h	; allocate pool memory
KFREE	equ	02228h	; free pool memory
LCBLST	equ	0A85Dh	; ptr to head of session linked list
LDRTCB	equ	0A848h	; LDR... TCB
LOGDEV	equ	0A850h	; ptr to head of logical device assignment list
LOGIN	equ	01F03h	; login user
LOGOUT	equ	01F6Fh	; logout user
MBITMP	equ	0A81Ch	; system memory allocation bitmap
MCRTCB	equ	0A846h	; MCR... TCB
MEMCPY	equ	0F210h	; inter-bank memory copy routine
MEMSZ	equ	0A81Ah	; total memory size
MFLAGS	equ	0A85Ch	; MCR flags
MVTBL	equ	0A863h	; ptr to head of mounted device linked list
M_EPT	equ	0F7A8h	; debugger-monitor normal entry point
NVOK	equ	09F01h	; P112 NV RAM OK flag
NVRAM	equ	09EE9h	; P112 NV RAM contents
PHYDEV	equ	0A84Eh	; ptr to head of physical device linked list
POOL	equ	0A818h	; ptr to start of pool area
POOLSZ	equ	0A816h	; size of pool area
REMTSK	equ	0322Ah	; remove task from STD
RLIST	equ	0A83Eh	; ptr to head of ready tasks list
SCBAR	equ	0F461h	; supervisor mode CBAR value
SFLAGS	equ	0A854h	; system flags
SWSTK	equ	0A865h	; stub to call kernel routines
SYSBBR	equ	0F45Dh	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0A805h	; start of system data area
SYSEND	equ	0A8A7h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F2h	; current system level
SYSVER	equ	0A80Bh	; system version number
TICCNT	equ	0F452h	; absolute time count in ticks
TICSEC	equ	0F451h	; ticks per second
TKILL	equ	014BAh	; abort task
TLIST	equ	0A83Ch	; ptr to head of installed tasks list
TM_EPT	equ	0FA46h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C8h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F460h	; user mode CBAR value
UGETB	equ	0F393h	; inter-bank get byte routine
UGETBB	equ	0F3FCh	; inter-bank get byte routine
UGETWB	equ	0F433h	; inter-bank get word routine
UNFTSK	equ	0323Ch	; unfix task
UPTIME	equ	0F456h	; system up time (ticks and seconds)
UPUTB	equ	0F3B7h	; inter-bank put byte routine
UPUTBB	equ	0F3DFh	; inter-bank put byte routine
UPUTWB	equ	0F415h	; inter-bank put word routine
USRBBR	equ	0F45Fh	; BBR of current executing task
WLIST	equ	0A840h	; ptr to head of waiting tasks list
