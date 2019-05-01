APPBBR	equ	0F45Eh	; first available BBR after system
ASSIGN	equ	01C7Ah	; assign logical name to physical device
BUFFER	equ	0669Ch	; ptr to file I/O buffer area
BUFMEM	equ	0669Eh	; size of file I/O buffer area
CLILST	equ	0AC5Dh	; list of CLI control blocks
CLKQ	equ	0AC42h	; ptr to head of clock queue
CTCB	equ	0AC40h	; address of TCB of current task
DEASGN	equ	01CE4h	; delete logical device assignment
ERRSEQ	equ	0AC50h	; error sequence number
FCBS	equ	0669Ah	; ptr to head of FCB linked list
FCPTCB	equ	0AC4Ah	; SYSFCP TCB
FIXTSK	equ	03F37h	; fix task in memory
FNDDEV	equ	01D1Fh	; find device and get DCB address
FORKQ	equ	0AC5Fh	; pointer to list of fork blocks
GETUCB	equ	01D85h	; get UCB address
HOSTNM	equ	0AC09h	; host/node name
IHPOOL	equ	0F6A8h	; interrupt handler pool
IHPTR	equ	0F6A6h	; ptr to free space in IHPOOL
IHSP	equ	0F6A4h	; saved SP when servicing interrupts
IHSTK	equ	0F6A4h	; top of stack for interrupt service routines
INSTSK	equ	03F28h	; enter task into STD
ITBL	equ	0F464h	; space for interrupt table
ITBLP	equ	0F462h	; interrupt table pointer
KALLOC	equ	021DDh	; allocate pool memory
KFREE	equ	0223Ch	; free pool memory
LCBLST	equ	0AC5Bh	; ptr to head of session linked list
LDRTCB	equ	0AC46h	; LDR... TCB
LOGDEV	equ	0AC4Eh	; ptr to head of logical device assignment list
LOGIN	equ	01F17h	; login user
LOGOUT	equ	01F83h	; logout user
MBITMP	equ	0AC1Ah	; system memory allocation bitmap
MCRTCB	equ	0AC44h	; MCR... TCB
MEMCPY	equ	0F210h	; inter-bank memory copy routine
MEMSZ	equ	0AC18h	; total memory size
MFLAGS	equ	0AC5Ah	; MCR flags
MVTBL	equ	0AC61h	; ptr to head of mounted device linked list
M_EPT	equ	0F7A8h	; debugger-monitor normal entry point
NVOK	equ	0AC00h	; P112 NV RAM OK flag
NVRAM	equ	0ABE8h	; P112 NV RAM contents
PHYDEV	equ	0AC4Ch	; ptr to head of physical device linked list
POOL	equ	0AC16h	; ptr to start of pool area
POOLSZ	equ	0AC14h	; size of pool area
REMTSK	equ	03F2Eh	; remove task from STD
RLIST	equ	0AC3Ch	; ptr to head of ready tasks list
SCBAR	equ	0F461h	; supervisor mode CBAR value
SFLAGS	equ	0AC52h	; system flags
SWSTK	equ	0AC63h	; stub to call kernel routines
SYSBBR	equ	0F45Dh	; system BBR
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	0AC01h	; start of system data area
SYSENT	equ	0F000h	; kernel services entry point
SYSVER	equ	0AC07h	; system version number
TICCNT	equ	0F452h	; absolute time count in ticks
TICSEC	equ	0F451h	; ticks per second
TLIST	equ	0AC3Ah	; ptr to head of installed tasks list
TM_EPT	equ	0FA46h	; debugger-monitor breakpoint entry point with message
T_EPT	equ	0F9C8h	; debugger-monitor breakpoint entry point
UCBAR	equ	0F460h	; user mode CBAR value
UGETB	equ	0F393h	; inter-bank get byte routine
UGETBB	equ	0F3FCh	; inter-bank get byte routine
UGETWB	equ	0F433h	; inter-bank get word routine
UNFTSK	equ	03F40h	; unfix task
UPTIME	equ	0F456h	; system up time (ticks and seconds)
UPUTB	equ	0F3B7h	; inter-bank put byte routine
UPUTBB	equ	0F3DFh	; inter-bank put byte routine
UPUTWB	equ	0F415h	; inter-bank put word routine
USRBBR	equ	0F45Fh	; BBR of current executing task
WLIST	equ	0AC3Eh	; ptr to head of waiting tasks list
