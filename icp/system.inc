$ALLOC	equ	01724h	; allocate pool memory
$ALUN	equ	012F5h	; assign LUN to device
$ASGN	equ	01155h	; assign logical name to physical device
$ASNTP	equ	0265Ch	; assign next task to partition
$AVAIL	equ	0180Dh	; compute available pool memory
$CHKPT	equ	02853h	; initiate task checkpoint
$CLASN	equ	011CFh	; delete all logical dev assignments of the given type
$CLIST	equ	05D26h	; list of CLI control blocks
$CLKQ	equ	05D24h	; ptr to head of clock queue
$CONN	equ	01468h	; connect to task
$CPCB	equ	05D22h	; address of PCB of current task
$CPLST	equ	05D18h	; ptr to head of checkpoint PCB list
$CTCB	equ	05D20h	; address of TCB of current task
$DBBRK	equ	00DC0h	; break task execution
$DBCON	equ	00CF8h	; connect task to external debugger
$DBDIS	equ	00D79h	; disconnect task from external debugger
$DBRES	equ	00DEEh	; resume task stopped for debugger
$DEASN	equ	011B8h	; delete logical device assignment
$ERSEQ	equ	05D33h	; error sequence number
$FEAT	equ	05D00h	; feature bits
$FILBF	equ	05D52h	; ptr to file I/O buffer area
$FIXTK	equ	006A1h	; fix task in memory
$FNDEV	equ	01210h	; find device and get UCB address
$FNPAR	equ	02603h	; find partition by name
$FNTCB	equ	00B25h	; find TCB by name
$FNTSK	equ	00AFAh	; find task by name
$FORKQ	equ	05D3Eh	; pointer to list of fork blocks
$FREE	equ	01783h	; free pool memory
$GTUCB	equ	012E0h	; get UCB address
$HOSTN	equ	05D01h	; host/node name
$IOEND	equ	01B6Ch	; end I/O processing for ASTs
$KDMON	equ	0F78Bh	; kernel debugger-monitor main entry point
$KDTRP	equ	0F9ABh	; kernel debugger-monitor trap entry point
$KMTRP	equ	0FA29h	; kernel debugger-monitor trap entry with message
$LDCKR	equ	00585h	; resume task after checkpoint read
$LDCKW	equ	005B7h	; queue task to partition after chkpnt write
$LDGO	equ	004E2h	; start task after load
$LGOUT	equ	01433h	; logout user
$LKTCB	equ	00388h	; link TCB to the specified list
$LOGDV	equ	05D14h	; ptr to head of logical device assignment list
$LOGIN	equ	013C4h	; login user
$MCOPY	equ	0F240h	; inter-bank memory copy routine
$MEMSZ	equ	05D10h	; total memory size
$MFLGS	equ	05D3Dh	; MCR flags
$MVTBL	equ	05D40h	; ptr to head of mounted device list
$PHYDV	equ	05D12h	; ptr to head of physical device list
$PLIST	equ	05D16h	; ptr to list of partitions
$POLSZ	equ	05D0Eh	; size of pool area
$POOL	equ	05D0Ch	; ptr to start of pool area
$REDIR	equ	0125Fh	; follow UCB redirection links
$REMTK	equ	008E9h	; remove task from STD
$RLIST	equ	05D1Ch	; ptr to head of ready tasks list
$RNDC	equ	05D28h	; round-robin interval in ticks
$RNDH	equ	05D2Ah	; highest priority for round-robin scheduling
$RNDL	equ	05D2Bh	; lowest priority for round-robin scheduling
$SBANK	equ	0F441h	; system bank number
$SCRBF	equ	05D42h	; scratch buffer address
$SWPC	equ	05D2Dh	; swapping interval in ticks
$SWPCT	equ	05D2Eh	; swapping interval counter
$SWPRI	equ	05D2Ch	; priority range for swapping
$SWSTK	equ	05D54h	; stub to call kernel routines
$TLIST	equ	05D1Ah	; ptr to head of installed tasks list
$UBANK	equ	0F442h	; bank of current task
$UCBDN	equ	013ADh	; get device name and unit from UCB
$UGETB	equ	0F3C3h	; inter-bank get byte routine
$UGETW	equ	0F3F9h	; inter-bank get word routine
$UNFTK	equ	006DDh	; unfix task
$UPUTB	equ	0F3DCh	; inter-bank put byte routine
$UPUTW	equ	0F417h	; inter-bank put word routine
$VALBF	equ	01D9Ch	; validate buffer (current task)
$VALTB	equ	01D79h	; validate buffer (arbitrary task)
$WLIST	equ	05D1Eh	; ptr to head of waiting tasks list
IODONE	equ	01B49h	; end I/O processing
LDRTCB	equ	05D31h	; LDR... TCB
MCRTCB	equ	05D2Fh	; MCR... TCB
NVOK	equ	0571Fh	; P112 NV RAM OK flag
NVRAM	equ	05707h	; P112 NV RAM contents
SCBAR	equ	0F444h	; supervisor mode CBAR value
SETFLG	equ	00EC9h	; set task's event flag
SFLAGS	equ	05D35h	; system flags
SYSCOM	equ	0F000h	; start of common area
SYSDAT	equ	05CF7h	; start of system data area
SYSEND	equ	05D9Dh	; end of system image
SYSENT	equ	0F000h	; kernel services entry point
SYSLVL	equ	0F0FAh	; current system level
SYSTOP	equ	05D0Ah	; top of pool area
SYSTYP	equ	05CFFh	; system type
SYSVER	equ	05CFDh	; system version number
TICCNT	equ	0F436h	; absolute time count in ticks
TICSEC	equ	0F435h	; ticks per second
TKILL	equ	00734h	; abort task
UCBAR	equ	0F443h	; user mode CBAR value
UPTIME	equ	0F43Ah	; system up time (ticks and seconds)
