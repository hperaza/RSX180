; DASMed version of DR LINK.COM by W. Cirsovius
; (Heavily) Modified by H. Peraza

; %%%% Fix up LINK revision NOTE: Base 1.31

LINKver	macro
	db	'1.40'
	endm

; Main differences in this program:
;
;  1 - Select .IRL file on /S option
;  2 - Disable PL/I Library /?FPBNX/ COMMON to be solved
;  3 - Display messages in lower case
;  4 - Code optimized and converted to Z80
;  5 - Fix error message on memory full condition
;  6 - Simple bug fix displaying current logged disk
;  7 - Options are specified after "/" char
;  8 - Allow option /OX for .RSX file generation
;  9 - Allow option /OT for .TSK file generation
; 10 - RSX180 version in addition to CP/M version
;
; Optional functions to be selected:
;
; Boolean	Description
; =======	===========
; @@DU		Allow ZCPR DU: style drive and user
; @@HASH	Disable special symbol prefix #
; @@SYS		Enable option [OR]

; %%%% Set to -1 to enable a mod, 0 to disable (DEFAULT)

@@DU	equ	 0		;; ZCPR DU
@@DST	equ	-1		;; Fix destination
@@HASH	equ	-1		;; Allow # in symbols
@@SYS	equ	-1		;; Enable option [OR]
@@TSK	equ	-1		;; Enable option [OT]
@@MAP	equ	-1		;; Enable map file

FALSE	equ	0
TRUE	equ	-1		; all bits set!

TPA	equ	0100h		; default load address
HDR.sz	equ	0100h		; header size for SPR,RSP,PRL,etc. files

RecLen	equ	128		; record length
ExtLen	equ	128		; extent size
BufLen	equ	128		; command line buffer length
PageLen	equ	256		; memory page length
HashLen	equ	128
HeadLen	equ	 12		; Header length on prefix

MaxCR	equ	128		; Max current record
MaxChIx	equ	  8
IDXend	equ	0FEh
	
.Rd	equ	0
.Wr	equ	1

BFlen1	equ	 256		; YYABS, YYCOM
				;                /A: XXABS, XXCOM
BFlen2	equ	 512		; XXCOM
BFlen3	equ	1024		; input buffer size, YYPRG, YYDAT, XXABS
				;                /A: XXPRG, XXDAT
BFlen4	equ	6144		; XXDAT
BFlen5	equ	8192		; XXPRG

@nam	equ	 8
@ext	equ	 3

.JP	equ	0C3h
.LD.BC	equ	01h

@aseg	equ	00b
@cseg	equ	01b
@dseg	equ	10b
@comn	equ	11b

NumSegs	equ	4

; XX.. PB structure

X$.cur	equ	 0
X$.max	equ	 2
X$.len	equ	 4
X$.buf	equ	 6
X$.high	equ	 8
X$.low	equ	10
X$.RD	equ	12
X$.WR	equ	13
IF	@@DU
X$.FCB	equ	15
ELSE
X$.FCB	equ	14
ENDIF	;@@DU

; YY.. PB structure

Y$.buf	equ	0
Y$.cur	equ	2
Y$.len	equ	4
Y$.WR	equ	6
IF	@@DU
Y$.FCB	equ	8
ELSE
Y$.FCB	equ	7
ENDIF	;@@DU

CtrlC	equ	03h
TAB	equ	09h
LF	equ	0Ah
FF	equ	0Ch
CR	equ	0Dh
EOF	equ	1Ah
SpcChar	equ	'#'		; Denotes special symbol prefix

MSB	equ	10000000b
NoMSB	equ	01111111b
LSB	equ	00000001b
LoMask	equ	00001111b
HiMask	equ	11110000b

$$LSB	equ	0

.ENTRY	equ	0000b
.ModNam	equ	0010b
.COMMON	equ	0101b
.EntPnt	equ	0111b
.ModEnd	equ	1110b
.EndFil	equ	1111b

.COMM	equ	1
.noCOMM	equ	0
.ENT	equ	1
.noENT	equ	0

.OC	equ	0		; COM output
.OP	equ	1		; PRL output
IF	@@SYS
.OR	equ	2		; RSP output
.OS	equ	3		; SPR output
.OY	equ	4		; OVL output*
.OX	equ	5		; RSX output
IF	@@TSK
.OT	equ	6		; TSK output
ENDIF
ELSE
.OS	equ	2		; SPR output
.OY	equ	3		; OVL output*
.OX	equ	4		; RSX output
IF	@@TSK
.OT	equ	5		; TSK output
ENDIF
ENDIF	;@@SYS

; Symbol table structure

;    0     1     2     3     4     5     6 ...             N
; +-----+-----+-----+-----+-----+-----+-----...---+-----+-----+
; |   Chain   | Tlen|   Offset  | Slen| Symbol ...|   COsize  |
; +-----+-----+-----+-----+-----+-----+-----...---+-----+-----+
;
; Chain		Chain address
; Tlen		Total length of symbol entry (N)
;		Total length + code
;		code bits 76xx.xxxx
;		Bit 7 - LIB REQ
;		Bit 6 - Symbol fixed bit
; Offset	Offset within segment
; Slen		Symbol length + code
;		code bits MBBx.xxxx
;		BB address mode ------------------++
;		code	00	External	0.00
;			A0	Entry, CSEG	1.01
;			C0	Entry, DSEG	1.10
;			E0	COMMON		1.11
;		MSB set on COMMON and ENTRY ----^
; Symbol	The symbol name
; COsize	Size of COMMON block

.SymOff	equ	3
.SymCtr	equ	5
.SymLab	equ	6
.SymHdr	equ	6

$$ENT	equ	7

X$$LIB	equ	7
X$$fix	equ	6

X@@LIB	equ	1 SHL X$$LIB
X@@fix	equ	1 SHL X$$fix

X@@mod	equ	00000011b

.SymLen	equ	00011111b
.ItmLen	equ	00111111b
.ItmBit	equ	10011111b

; Temporary (Y) table structure
;
;    0     1     2     3     4     5     6     7     8
; +-----+-----+-----+-----+-----+-----+-----+-----+-----+
; | Sta |    Adr    |    Val    |    Lnk    |    Off    |
; +-----+-----+-----+-----+-----+-----+-----+-----+-----+
;
; Sta		Status of entry
;		Bit 0,1	Address mode
;		Bit  2	Chain type flag (0=CHAIN ADDRESS, 1=CHAIN EXTERNAL)
;		Bit  3	Offset flag
;		Bit  4	Offset sign
; Adr		Current address
; Val		Current value
; Lnk		Link pointer, ends with zero
; Off		Offset, if defined

.Y$Val	equ	3
.Y$Lnk	equ	5
.Y$Off	equ	7

Y$$sign	equ	4
Y$$off	equ	3
Y$$type	equ	2

Y@@sign	equ	1 SHL Y$$sign
Y@@off	equ	1 SHL Y$$off
Y@@type	equ	1 SHL Y$$type

Y@@mod	equ	00000011b

Y.eof	equ	-1

MaxOVL	equ	5

_LabLen	equ	7

ColMask	equ	00000011b
LabCol	equ	9
LabDel	equ	3
UnkMask	equ	00000111b

; Segment table indexes

IASEG	equ	0
ICSEG	equ	2
IDSEG	equ	4
ICOMN	equ	6
