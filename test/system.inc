APPBBR	equ	0F457h	; first available BBR after system
ASSIGN	equ	01D41h	; assign logical name to physical device
BUFFER	equ	05C51h	; ptr to file I/O buffer area
BUFMEM	equ	05C53h	; size of file I/O buffer area
CLILST	equ	0AB3Ah	; list of CLI control blocks
CLKQ	equ	0AB1Fh	; ptr to head of clock queue
CONN	equ	0208Ch	; connect to task
CPCB	equ	0AB1Dh	; address of PCB of current task
CTCB	equ	0AB1Bh	; address of TCB of current task
DEASGN	equ	01DABh	; delete logical device assignment
ERRSEQ	equ	0AB2Dh	; error sequence number
FCBS	equ	05C4Fh	; ptr to head of FCB linked list
FCPTCB	equ	0AB27h	; SYSFCP TCB
FIXTSK	equ	034C9h	; fix task in memory
FNDDEV	equ	01DE6h	; find device and get DCB address
FORKQ	equ	0AB3Ch	; pointer to list of fork blocks
GETUCB	equ	01E4Ch	; get UCB address
HOSTNM	equ	0AB04h	; host/node name
IHPOOL	equ	0F6A1h	; interrupt handler pool
IHPTR	equ	0F69Fh	; ptr to free space in IHPOOL
IHSP	equ	0F69Dh	; saved SP when servicing interrupts
IHSTK	equ	0F69Dh	; top of stack for interrupt service routines
INSTSK	equ	034BAh	; enter task into STD
ITBL	equ	0F45Dh	; space for interrupt table
ITBLP	equ	0F45Bh	; interrupt table pointer
KALLOC	equ	02301h	; allocate pool memory
KFREE	equ	02360h	; free pool memory
LCBLST	equ	0AB38h	; ptr to head of session linked list
LDRTCB	equ	0AB23h	; LDR... TCB
LOGDEV	equ	0AB2Bh	; ptr to head of logical device assignment list
LOGIN	equ	01FDEh	; login user
LOGOUT	equ	0204Ah	; logout user
MCRTCB	equ	0AB21h	; MCR... TCB
MEMCPY	equ	0F209h	; inter-bank memory copy routine
MEMSZ	equ	0AB11h	; total memory size
MFLAGS	equ	0AB37h	; MCR flags
MVTBL	equ	0AB3Eh	; ptr to head of mounted device linked list
M_EPT	equ	0F7A1h	; debugger-monitor normal entry point
NVOK	equ	0A1F8h	; P112 NV RAM OK flag
NVRAM	equ	0A1E0h	; P112 NV RAM contents
PHYDEV	equ	0AB29h	; ptr to head of physical device linked list
PLIST	equ	0AB13h	; ptr to list of partitions
POOL	equ	0AB0Fh	; ptr to start of pool area
POOLSZ	equ	0AB0Dh	; size of pool area
REMTSK	equ	034C0h	; remove task from STD
RLIST	equ	0AB17h	; ptr to head of ready tasks list
SCBAR	equ	0F45Ah	; supervisor mode CBAR value
SFLAGS	equ	0AB2Fh	; system flags
SWSTK	equ	0AB40h	; stub to call kernel routines
SYSBBR	equ	0F456h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0AAFCh	; start of system data area
SYSEND	equ	0AB82h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSVER	equ	0AB02h	; system version number
TICCNT	equ	0F44Bh	; absolute time count in ticks
TICSEC	equ	0F44Ah	; ticks per second
TKILL	equ	01572h	; abort task
TLIST	equ	0AB15h	; ptr to head of installed tasks list
TM_EPT	equ	0FA3Fh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C1h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F459h	; user mode CBAR value
UGETB	equ	0F38Ch	; inter-bank get byte routine
UGETBB	equ	0F3F5h	; inter-bank get byte routine
UGETWB	equ	0F42Ch	; inter-bank get word routine
UNFTSK	equ	034D2h	; unfix task
UPTIME	equ	0F44Fh	; system up time (ticks and seconds)
UPUTB	equ	0F3B0h	; inter-bank put byte routine
UPUTBB	equ	0F3D8h	; inter-bank put byte routine
UPUTWB	equ	0F40Eh	; inter-bank put word routine
USRBBR	equ	0F458h	; BBR of current executing task
WLIST	equ	0AB19h	; ptr to head of waiting tasks list
