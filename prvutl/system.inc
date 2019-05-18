APPBBR	equ	0F457h	; first available BBR after system
ASSIGN	equ	01D41h	; assign logical name to physical device
BUFFER	equ	05C49h	; ptr to file I/O buffer area
BUFMEM	equ	05C4Bh	; size of file I/O buffer area
CLILST	equ	0A51Fh	; list of CLI control blocks
CLKQ	equ	0A504h	; ptr to head of clock queue
CONN	equ	0208Ch	; connect to task
CPCB	equ	0A502h	; address of PCB of current task
CTCB	equ	0A500h	; address of TCB of current task
DEASGN	equ	01DABh	; delete logical device assignment
ERRSEQ	equ	0A512h	; error sequence number
FCBS	equ	05C47h	; ptr to head of FCB linked list
FCPTCB	equ	0A50Ch	; SYSFCP TCB
FIXTSK	equ	034C1h	; fix task in memory
FNDDEV	equ	01DE6h	; find device and get DCB address
FORKQ	equ	0A521h	; pointer to list of fork blocks
GETUCB	equ	01E4Ch	; get UCB address
HOSTNM	equ	0A4E9h	; host/node name
IHPOOL	equ	0F6A1h	; interrupt handler pool
IHPTR	equ	0F69Fh	; ptr to free space in IHPOOL
IHSP	equ	0F69Dh	; saved SP when servicing interrupts
IHSTK	equ	0F69Dh	; top of stack for interrupt service routines
INSTSK	equ	034B2h	; enter task into STD
ITBL	equ	0F45Dh	; space for interrupt table
ITBLP	equ	0F45Bh	; interrupt table pointer
KALLOC	equ	022F9h	; allocate pool memory
KFREE	equ	02358h	; free pool memory
LCBLST	equ	0A51Dh	; ptr to head of session linked list
LDRTCB	equ	0A508h	; LDR... TCB
LOGDEV	equ	0A510h	; ptr to head of logical device assignment list
LOGIN	equ	01FDEh	; login user
LOGOUT	equ	0204Ah	; logout user
MCRTCB	equ	0A506h	; MCR... TCB
MEMCPY	equ	0F209h	; inter-bank memory copy routine
MEMSZ	equ	0A4F6h	; total memory size
MFLAGS	equ	0A51Ch	; MCR flags
MVTBL	equ	0A523h	; ptr to head of mounted device linked list
M_EPT	equ	0F7A1h	; debugger-monitor normal entry point
NVOK	equ	0A02Ah	; P112 NV RAM OK flag
NVRAM	equ	0A012h	; P112 NV RAM contents
PHYDEV	equ	0A50Eh	; ptr to head of physical device linked list
PLIST	equ	0A4F8h	; ptr to list of partitions
POOL	equ	0A4F4h	; ptr to start of pool area
POOLSZ	equ	0A4F2h	; size of pool area
REMTSK	equ	034B8h	; remove task from STD
RLIST	equ	0A4FCh	; ptr to head of ready tasks list
SCBAR	equ	0F45Ah	; supervisor mode CBAR value
SFLAGS	equ	0A514h	; system flags
SWSTK	equ	0A525h	; stub to call kernel routines
SYSBBR	equ	0F456h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0A4E1h	; start of system data area
SYSEND	equ	0A567h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSVER	equ	0A4E7h	; system version number
TICCNT	equ	0F44Bh	; absolute time count in ticks
TICSEC	equ	0F44Ah	; ticks per second
TKILL	equ	01572h	; abort task
TLIST	equ	0A4FAh	; ptr to head of installed tasks list
TM_EPT	equ	0FA3Fh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C1h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F459h	; user mode CBAR value
UGETB	equ	0F38Ch	; inter-bank get byte routine
UGETBB	equ	0F3F5h	; inter-bank get byte routine
UGETWB	equ	0F42Ch	; inter-bank get word routine
UNFTSK	equ	034CAh	; unfix task
UPTIME	equ	0F44Fh	; system up time (ticks and seconds)
UPUTB	equ	0F3B0h	; inter-bank put byte routine
UPUTBB	equ	0F3D8h	; inter-bank put byte routine
UPUTWB	equ	0F40Eh	; inter-bank put word routine
USRBBR	equ	0F458h	; BBR of current executing task
WLIST	equ	0A4FEh	; ptr to head of waiting tasks list
