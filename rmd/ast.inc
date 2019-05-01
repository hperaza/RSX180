; AST event block structure

A.LNK	equ	0		; link to next item in list (2 bytes)
A.SIZ	equ	A.LNK + 2	; size of data area (1 byte)
A.TYP	equ	A.SIZ + 1	; event type (1 byte)
A.DAT	equ	A.TYP + 1	; start of data area (variable length)

; AST header size

AHSZ	equ	A.DAT

; AST types (mask values)

AST.IO	equ	01h		; I/O completion
AST.UC	equ	02h		; unsolicited char from attached terminal
AST.RD	equ	04h		; data received
AST.CK	equ	08h		; clock (mark time)
AST.ST	equ	10h		; status (from offspring)
AST.AB	equ	20h		; abort/exit
AST.CL	equ	40h		; command line (CLIs only)

