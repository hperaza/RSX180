;**********************************************************************;
;                                                                      ;
;   This file is part of RSX180, a multi-tasking OS for the Z180.      ;
;   Copyright (C) 1985-2019, Hector Peraza.                            ;
;                                                                      ;
;   This program is free software; you can redistribute it and/or      ;
;   modify it under the terms of the GNU General Public License as     ;
;   published by the Free Software Foundation; either version 2 of     ;
;   the License, or (at your option) any later version.                ;
;                                                                      ;
;   This program is distributed in the hope that it will be useful,    ;
;   but WITHOUT ANY WARRANTY; without even the implied warranty of     ;
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      ;
;   GNU General Public License for more details.                       ;
;                                                                      ;
;   You should have received a copy of the GNU General Public License  ;
;   along with this program; if not, write to the Free Software        ;
;   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.          ;
;                                                                      ;
;**********************************************************************;

; Simple standalone debug monitor for P112 board.

	.Z180

	ifndef	Z80182
Z80182	equ	1
	include	Z180.INC
	endif

CR	equ	0Dh
LF	equ	0Ah

FALSE	equ	0
TRUE	equ	NOT FALSE

IITRAP	equ	FALSE

CMD_C	equ	FALSE		; compare command?
CMD_S	equ	FALSE		; search command?
CMD_T	equ	FALSE		; transfer command?
CMD_B	equ	FALSE		; breakpoint command?

;;	cseg

;-----------------------------------------------------------------------

; Main entry point

M_EPT::
	di
	ld	sp,mon_stack
	ld	hl,prompt
	call	print
	call	getln
	ld	hl,M_EPT
	push	hl
	ld	hl,lnbuf
	ld	a,(hl)
	or	a
	ret	z
	call	uc
	push	af
	call	get_args
	ld	bc,(arg3)
	ld	de,(arg2)
	ld	hl,(arg1)
	pop	af
	cp	'D'
	jp	z,dump
	IF	CMD_C
	cp	'C'
	jp	z,comp
	ENDIF
	cp	'F'
	jp	z,fill
	IF	CMD_S
	cp	'S'
	jp	z,search
	ENDIF
	IF	CMD_T
	cp	'T'
	jp	z,move
	ENDIF
	cp	'E'
	jp	z,exam
	IF	CMD_B
	cp	'B'
	jp	z,setbrk
	ENDIF
	cp	'G'
	jp	z,run
	cp	'I'
	jp	z,inport
	cp	'O'
	jp	z,outport
	cp	'X'
	jp	z,showregs
	cp	'M'
	jp	z,showmmu
	cp	'N'
	jp	z,continue
	cp	'W'
	jp	z,word
	cp	'/'
	jp	z,tasks
error:	call	cr_lf
	ld	a,'?'
	call	mon_putch
	jr	M_EPT

prompt:	db	CR,LF,"Z180>",0

getln:	ld	hl,lnbuf
	ld	b,1
get:	call	mon_getch
	cp	CR
	jr	z,eol
	cp	8
	jr	z,bkspc
	cp	7Fh
	jr	z,bkspc
	cp	3
	jr	z,ctrlc
	cp	' '
	jr	c,get
	ld	c,a
	ld	a,b
	cp	20
	jr	nc,get
	ld	a,c
	call	mon_putch
	ld	(hl),a
	inc	hl
	inc	b
	jr	get
bkspc:	dec	b
	jr	z,getln
	ld	a,8
	call	mon_putch
	call	space
	ld	a,8
	call	mon_putch
	dec	hl
	jr	get
eol:	ld	(hl),0
	call	mon_putch
	ret
ctrlc:	ld	hl,ctlcm
	call	print
	jp	M_EPT

ctlcm:	db	"^C",CR,LF,0

uc:	cp	'a'
	ret	c
	cp	'z'+1
	ret	nc
	and	5Fh
	ret

print:	ld	a,(hl)
	or	a
	ret	z
	call	mon_putch
	inc	hl
	jr	print

; get command line arguments

get_args:
	ld	hl,0
	ld	(arg1),hl
	ld	(arg2),hl
	ld	(arg3),hl
	ld	de,lnbuf+1
	call	gethex
	ld	(arg1),hl
	ld	(arg2),hl
	ret	c
	call	gethex
	ld	(arg2),hl
	ret	c
	call	gethex
	ld	(arg3),hl
	ret	c
	jp	error

gethex:	ld	hl,0
gh1:	ld	a,(de)
	call	uc
	inc	de
	or	a
	scf
	ret	z
	cp	','
	ret	z
	cp	' '
	jr	z,gh1
	sub	'0'
	jp	c,error
	cp	10
	jr	c,dig
	cp	11h
	jp	c,error
	cp	17h
	jp	nc,error
	sub	7
dig:	ld	c,a
	ld	b,0
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	jp	c,error
	add	hl,bc
	jr	gh1

hl?de:	ld	a,h
	cp	d
	ret	nz
	ld	a,l
	cp	e
	ret

next:	call	?stop
	call	hl?de
	jr	z,cmp_eq
	inc	hl
	ret
cmp_eq:	inc	sp
	inc	sp
	ret

?stop:	call	mon_status
	or	a
	ret	z
	call	mon_getch
	cp	3
	jp	z,ctrlc
	cp	13h	; CTRL/S
	ret	nz
	call	mon_getch
	cp	3
	jp	z,ctrlc
	ret

	IF	CMD_T

; T addr1,addr2,addr3
; Transfer (move) region addr1...addr2 to addr3,
; source and dest regions may overlap

move:	ld	a,b
	or	c
	ret	z
	ld	a,l
	sub	e
	ld	a,h
	sbc	a,d
	ret	z
	jr	c,m1
	ldir
	ret
m1:	add	hl,bc
	ex	de,hl
	add	hl,bc
	ex	de,hl
	dec	hl
	dec	de
	lddr
	ret

	ENDIF

; D addr1,addr2
; Dump region addr1...addr2

dump:	call	out_addr
	push	hl
dmph:   ld	a,(hl)
	call	outbyte
	call	?stop
	call	hl?de
	jr	z,enddmp
	inc	hl
	ld	a,l
	and	0Fh
	jr	nz,dmph
	pop	hl
	call	dumpl
	jr	dump
enddmp:	pop	hl
dumpl:  ld	a,(hl)
	cp	' '
	jr	c,outdot
	cp	7Fh
	jr	c,char
outdot:	ld	a,'.'
char:	call	mon_putch
	call	?stop
	call	hl?de
	ret	z
	inc	hl
	ld	a,l
	and	0Fh
	jr	nz,dumpl
	ret

; F addr1,addr2,byte
; Fill region addr1...addr2 with byte

fill:	ld	(hl),c
	call	next
	jr	fill

	IF	CMD_C

; C addr1,addr2,addr3
; Compare region addr1...addr2 with region at addr3

comp:	ld	a,(bc)
	cp	(hl)
	jr	z,same
	call	out_addr
	ld	a,(hl)
	call	outbyte
	ld	a,(bc)
	call	outbyte
same:	inc	bc
	call	next
	jr	comp

	ENDIF

	IF	CMD_S

; S addr1,addr2,byte
; Search region addr1...addr2 for byte

search:	ld	a,c
	cp	(hl)
	jr	nz,scont
	call	out_addr
	dec	hl
	ld	a,(hl)
	call	outbyte
	ld	a,'('
	call	mon_putch
	inc	hl
	ld	a,(hl)
	call	ahex
	ld	a,')'
	call	mon_putch
	call	space
	inc	hl
	ld	a,(hl)
	call	outbyte
	dec	hl
scont:	call	next
	jr	search

	ENDIF

; E addr
; Examine and modify memory starting at addr

exam:	call	out_addr
	ld	a,(hl)
	call	outbyte
	push	hl
	call	getln
	pop	hl
	ld	de,lnbuf
	ld	a,(de)
	or	a
	jr	z,cont
	push	hl
	call	gethex
	ld	a,l
	pop	hl
	ld	(hl),a
cont:	inc	hl
	jr	exam

; I port
; Input from port

inport:	call	cr_lf
	ld	a,l
	call	ahex
	ld	a,'='
	call	mon_putch
	ld	c,l
	ld	b,h		; or ld b,0
	in	a,(c)
	jp	ahex

; O port,byte
; Output to port

outport:ld	c,l
	ld	b,h		; or ld b,0
	ld	a,e
	out	(c),a
	ret

; W addr
; Display word at addr

word:	call	out_addr
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	jp	hlhex

	IF	CMD_B

; B addr
; set Breakpoint at addr. It will be automatically removed when reached.

setbrk:	ld	(brkadr),hl
	ld	a,(hl)
	ld	(brkval),a
	ld	a,DBGRST OR 0C7h
	ld	(hl),a
	ld	a,0C3h
	ld	(DBGRST),a
	ld	hl,T_EPT
	ld	(DBGRST+1),hl
	ret

	ENDIF

; G addr
; Go (execute) program at addr. Program may use return 
; instruction to return to monitor

run:
;;	ei
	call	r1
;;	di
	ret
r1:	jp	(hl)

out_addr:
	call	cr_lf
	call	hlhex
	ld	a,':'
	call	mon_putch
	jr	space

outbyte:
	call	ahex
space:	ld	a,' '
	jp	mon_putch

hlhex:	ld	a,h
	call	ahex
	ld	a,l
ahex:	push	af
	rrca
	rrca
	rrca
	rrca
	call	nhex
	pop	af
nhex:	and	0Fh
	add	a,90h
	daa
	adc	a,40h
	daa
	jp	mon_putch

cr_lf:	push	af
	ld	a,CR
	call	mon_putch
	ld	a,LF
	call	mon_putch
	pop	af
	ret

; Trap (breakpoint) entry point. Saves all registers and current MMU status.

T_EPT::
	di
	ld	(pgm_sp),sp
	ld	sp,reg_stack
	ex	af,af'
	push	af
	ex	af,af'
	exx	
	push	bc
	push	de
	push	hl
	exx
	push	af
	push	bc
	push	de
	push	hl
	push	ix
	push	iy
	in0	a,(BBR)
	ld	(pgm_bbr),a
	in0	a,(CBR)
	ld	(pgm_cbr),a
	ld	sp,mon_stack
	ld	hl,(pgm_sp)
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	(pgm_pc),de
	ld	hl,brk_msg

	IF	IITRAP
	in0	a,(ITC)
	ld	b,a
	and	80h		; TRAP bit set?
	jr	z,no_trap
	dec	de		; PC-1
	ld	a,b
	and	40h		; UFO bit set?
	jr	z,no_ufo_adj
	dec	de		; PC-2 if UFO was set
no_ufo_adj:
	ld	hl,trap_msg
no_trap:
	ENDIF

	call	cr_lf
	call	print
	ld	hl,atpc_msg
	call	print
	call	chkbrk
	ld	hl,(pgm_pc)
	call	hlhex
	call	cr_lf
	jp	M_EPT

chkbrk:	ld	hl,(brkadr)
	ld	de,(pgm_pc)
	dec	de		; adjust user's PC
	call	hl?de		; breakpoint set by us?
	ret	nz
	ld	a,(brkval)
	ld	(hl),a		; remove it if yes
	ld	hl,0
	ld	(brkadr),hl
	ld	hl,(pgm_sp)
	ld	(hl),e
	inc	hl
	ld	(hl),d
	ld	(pgm_pc),de	; save corrected user's PC
	ret

	IF	IITRAP
trap_msg:
	db	"Illegal instruction trap",0
	ENDIF

brk_msg:
	db	"Break",0
atpc_msg:
	db	" at PC=",0

TM_EPT::di
	ex	(sp),hl
	push	af
	call	cr_lf
	call	print
	inc	hl
	pop	af
	ex	(sp),hl
	jp	T_EPT

; N
; coNtinue execution from the last break

continue:
	ld	a,h
	or	l		; if 1st arg is <>0, continue w/o enabling ints
	jr	nz,di_continue
	ld	a,(pgm_bbr)
	out0	(BBR),a
	ld	a,(pgm_cbr)
	out0	(CBR),a
	ld	sp,pgm_iy
	pop	iy
	pop	ix
	pop	hl
	pop	de
	pop	bc
	pop	af
	exx
	pop	hl
	pop	de
	pop	bc
	exx
	ex	af,af'
	pop	af
	ex	af,af'
	ld	sp,(pgm_sp)
	ei
	ret
di_continue:
	ld	a,(pgm_bbr)
	out0	(BBR),a
	ld	a,(pgm_cbr)
	out0	(CBR),a
	ld	sp,pgm_iy
	pop	iy
	pop	ix
	pop	hl
	pop	de
	pop	bc
	pop	af
	exx
	pop	hl
	pop	de
	pop	bc
	exx
	ex	af,af'
	pop	af
	ex	af,af'
	ld	sp,(pgm_sp)
	ret

; X
; show the contents of the CPU registers

showregs:
	ld	hl,regdmp
showr1:	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	a,d
	or	e
	jr	z,shmmu
	ex	de,hl
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
	push	bc
	ex	de,hl
	call	print
	ex	(sp),hl
	call	hlhex
	pop	hl
	inc	hl
	jr	showr1
shmmu:	ld	hl,mmudmp
showm1:	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	a,d
	or	e
	ret	z
	ex	de,hl
	ld	c,(hl)
	push	bc
	ex	de,hl
	call	print
	ex	(sp),hl
	ld	a,l
	call	ahex
	pop	hl
	inc	hl
	jr	showm1

regdmp:	dw	pgm_af
	db	CR,LF,"AF=",0
	dw	pgm_bc
	db	" BC=",0
	dw	pgm_de
	db	" DE=",0
	dw	pgm_hl
	db	" HL=",0
	dw	pgm_ix
	db	" IX=",0
	dw	pgm_iy
	db	" IY=",0
	dw	pgm_af1
	db	CR,LF,"AF'",0
	dw	pgm_bc1
	db	" BC'",0
	dw	pgm_de1
	db	" DE'",0
	dw	pgm_hl1
	db	" HL'",0
	dw	pgm_pc
	db	" PC=",0
	dw	pgm_sp
	db	" SP=",0
	dw	0

mmudmp:	dw	pgm_bbr
	db	CR,LF,"BBR=",0
	dw	pgm_cbr
	db	" CBR=",0
	dw	0

; M
; Show Z180 MMU state

showmmu:
	ld	hl,mmurgs
	call	print
	in0	a,(CBAR)
	call	ahex
	inc	hl
	call	print
	in0	a,(BBR)
	call	ahex
	inc	hl
	call	print
	in0	a,(CBR)
	jp	ahex

mmurgs:	db	CR,LF,"CBAR=",0," BBR=",0," CBR=",0

; /
; Show tasks

;	include	TCB.INC

tasks:	in0	a,(BBR)
	push	af
	ld	a,(SYSBBR)
	out0	(BBR),a
	ld	hl,tmsg1
	call	print
	ld	hl,($RLIST##)
	call	prlist
	ld	hl,tmsg2
	call	print
	ld	hl,($WLIST##)
	call	prlist
	pop	af
	out0	(BBR),a
	ret

prlist:	ld	a,h
	or	l
	ret	z
	push	hl
	ld	de,T.NAME
	add	hl,de
	ld	b,6
pt1:	ld	a,(hl)
	call	mon_putch
	inc	hl
	djnz	pt1
	call	space
	pop	hl
	call	hlhex
	call	space
	ld	c,l
	ld	b,h
	push	bc
	ld	hl,T.ST
	add	hl,bc
	ld	a,(hl)
	call	outbyte
	inc	hl
	ld	a,(hl)
	call	outbyte
	ld	hl,T.PCB
	add	hl,bc
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	hl,P.BASE
	add	hl,de
	ld	e,(hl)		; for UGETWB below
	ld	a,e
	call	outbyte
	ld	hl,T.SP
	add	hl,bc
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	ld	bc,20		; offset to PC
	add	hl,bc
	call	UGETWB
	ld	l,c
	ld	h,b
	call	hlhex
	call	cr_lf
	pop	hl
	ld	bc,T.ACTL
	add	hl,bc
	ld	a,(hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	jr	prlist

tmsg1:	db	CR,LF,'RLIST:',CR,LF,0
tmsg2:	db	'WLIST:',CR,LF,0

mon_getch:
	call	mon_status
	or	a
	jr	z,mon_getch
	in0	a,(SCCAD)
	and	7Fh
	ret

mon_putch:
	push	af
wait:	in0	a,(SCCACNT)
	bit	2,a
	jr	z,wait
	pop	af
	out0	(SCCAD),a
	ret

mon_status:
	in0	a,(SCCACNT)
	rra
	sbc	a,a		; return FF if ready, 0 otherwise
	ret

_LSR	equ	9Dh
_THR	equ	98h

D_MSG::
	ex	(sp),hl
	push	af
dms0:	ld	a,(hl)
	inc	hl
	or	a
	jr	z,dms2
	push	af
dms1:	in0	a,(_LSR)
	bit	5,a
	jr	z,dms1
	pop	af
	out0	(_THR),a
	jr	dms0
dms2:	pop	af
	ex	(sp),hl
	ret

;;	dseg

arg1:	ds	2
arg2:	ds	2
arg3:	ds	2
lnbuf:	ds	21

pgm_iy:	ds	2
pgm_ix:	ds	2
pgm_hl:	ds	2
pgm_de:	ds	2
pgm_bc:	ds	2
pgm_af:	ds	2
pgm_hl1:ds	2
pgm_de1:ds	2
pgm_bc1:ds	2
pgm_af1:ds	2
reg_stack equ	$
pgm_sp:	ds	2
pgm_pc:	ds	2

pgm_bbr:ds	1
pgm_cbr:ds	1

brkadr:	ds	2
brkval:	ds	1

	ds	48
mon_stack:

