APPBBR	equ	0F457h	; first available BBR after system
ASSIGN	equ	01CF4h	; assign logical name to physical device
BUFFER	equ	05BFCh	; ptr to file I/O buffer area
BUFMEM	equ	05BFEh	; size of file I/O buffer area
CLILST	equ	0AB31h	; list of CLI control blocks
CLKQ	equ	0AB16h	; ptr to head of clock queue
CONN	equ	0203Fh	; connect to task
CPCB	equ	0AB14h	; address of PCB of current task
CTCB	equ	0AB12h	; address of TCB of current task
DEASGN	equ	01D5Eh	; delete logical device assignment
ERRSEQ	equ	0AB24h	; error sequence number
FCBS	equ	05BFAh	; ptr to head of FCB linked list
FCPTCB	equ	0AB1Eh	; SYSFCP TCB
FIXTSK	equ	03474h	; fix task in memory
FNDDEV	equ	01D99h	; find device and get DCB address
FORKQ	equ	0AB33h	; pointer to list of fork blocks
GETUCB	equ	01DFFh	; get UCB address
HOSTNM	equ	0AAFBh	; host/node name
IHPOOL	equ	0F6A1h	; interrupt handler pool
IHPTR	equ	0F69Fh	; ptr to free space in IHPOOL
IHSP	equ	0F69Dh	; saved SP when servicing interrupts
IHSTK	equ	0F69Dh	; top of stack for interrupt service routines
INSTSK	equ	03465h	; enter task into STD
ITBL	equ	0F45Dh	; space for interrupt table
ITBLP	equ	0F45Bh	; interrupt table pointer
KALLOC	equ	022ACh	; allocate pool memory
KFREE	equ	0230Bh	; free pool memory
LCBLST	equ	0AB2Fh	; ptr to head of session linked list
LDRTCB	equ	0AB1Ah	; LDR... TCB
LOGDEV	equ	0AB22h	; ptr to head of logical device assignment list
LOGIN	equ	01F91h	; login user
LOGOUT	equ	01FFDh	; logout user
MCRTCB	equ	0AB18h	; MCR... TCB
MEMCPY	equ	0F209h	; inter-bank memory copy routine
MEMSZ	equ	0AB08h	; total memory size
MFLAGS	equ	0AB2Eh	; MCR flags
MVTBL	equ	0AB35h	; ptr to head of mounted device linked list
M_EPT	equ	0F7A1h	; debugger-monitor normal entry point
NVOK	equ	0A1EFh	; P112 NV RAM OK flag
NVRAM	equ	0A1D7h	; P112 NV RAM contents
PHYDEV	equ	0AB20h	; ptr to head of physical device linked list
PLIST	equ	0AB0Ah	; ptr to list of partitions
POOL	equ	0AB06h	; ptr to start of pool area
POOLSZ	equ	0AB04h	; size of pool area
REMTSK	equ	0346Bh	; remove task from STD
RLIST	equ	0AB0Eh	; ptr to head of ready tasks list
SCBAR	equ	0F45Ah	; supervisor mode CBAR value
SFLAGS	equ	0AB26h	; system flags
SWSTK	equ	0AB37h	; stub to call kernel routines
SYSBBR	equ	0F456h	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0AAF3h	; start of system data area
SYSEND	equ	0AB79h	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0F1h	; current system level
SYSVER	equ	0AAF9h	; system version number
TICCNT	equ	0F44Bh	; absolute time count in ticks
TICSEC	equ	0F44Ah	; ticks per second
TKILL	equ	01525h	; abort task
TLIST	equ	0AB0Ch	; ptr to head of installed tasks list
TM_EPT	equ	0FA3Fh	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C1h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F459h	; user mode CBAR value
UGETB	equ	0F38Ch	; inter-bank get byte routine
UGETBB	equ	0F3F5h	; inter-bank get byte routine
UGETWB	equ	0F42Ch	; inter-bank get word routine
UNFTSK	equ	0347Dh	; unfix task
UPTIME	equ	0F44Fh	; system up time (ticks and seconds)
UPUTB	equ	0F3B0h	; inter-bank put byte routine
UPUTBB	equ	0F3D8h	; inter-bank put byte routine
UPUTWB	equ	0F40Eh	; inter-bank put word routine
USRBBR	equ	0F458h	; BBR of current executing task
WLIST	equ	0AB10h	; ptr to head of waiting tasks list
