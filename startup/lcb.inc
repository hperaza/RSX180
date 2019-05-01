; Login/Session Control Block structure, one per logged-in terminal

L.LNK	equ	0		; link to next SCB in priority list (2 bytes)
L.ST	equ	L.LNK + 2	; status (1 byte)
L.ATTR	equ	L.ST + 1	; attributes (1 byte)
L.NAME	equ	L.ATTR + 1	; user name (9 characters)
L.USR	equ	L.NAME + 9	; user number (1 byte)
L.GRP	equ	L.USR + 1	; group number (1 byte)
L.CON	equ	L.GRP + 1	; console device and unit (3 bytes)
L.CDIR	equ	L.CON + 3	; current dir name (9 bytes)
L.TIME	equ	L.CDIR + 9	; login timestamp (7 bytes)

; LCB size

LCBSZ	equ	L.TIME + 7

; Status bit numbers

LS.LOG	equ	0		; logged in
LS.PRV	equ	1		; privileged

