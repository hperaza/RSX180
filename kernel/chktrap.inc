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

	.Z180

	public	CHKTRP

; 'Untrapped RST' handler: check for a possible illegal instruction trap and
; terminate current task accordingly.

CHKTRP:	ld	(tmp_hl),hl	; save HL
	pop	hl		; get PC into HL
	push	de		; save DE
	push	af		; save AF
	dec	hl		; PC-1
	ld	e,TK.RST	; set abort code for TKTN
	in0	a,(ITC)
	bit	7,a		; TRAP bit set?
	jr	z,noadj		; jump if not
	ld	e,TK.IIT	; abort code = illegal instruction
	res	7,a
	out0	(ITC),a		; clear the TRAP bit in ITC
	bit	6,a		; UFO bit set?
	jr	z,noadj
	dec	hl		; PC-2 if UFO was set
noadj:	ld	a,(SYSLVL)
	or	a		; are we running at system level?
	jr	z,panic		; panic via debugger if yes (kernel trap)
	di			; else disable interrupts
	ld	a,e
	ld	(TRPFLG),a	; set trap flag = abort code
	pop	af		; restore AF
	pop	de		;  and DE
	push	hl		; push adjusted PC back on stack
	ld	hl,(tmp_hl)	; restore HL
	jp	SYSENT		; and kill the task via SYSENT

panic:	push	hl
	ld	hl,trpmsg
	ld	a,e
	cp	TK.IIT
	jr	z,p1
	ld	hl,rstmsg
p1:	call	cr_lf
	call	print
	pop	hl
	pop	af		; restore AF
	pop	de		; restore DE
	push	hl		; push (adjusted) PC back on stack
	ld	hl,(tmp_hl)	; restore HL
	jp	T_EPT		; exit to debugger

trpmsg:	db	'Illegal instruction trap',0
rstmsg:	db	'Unexpected RST',0

;!!	dseg

tmp_hl:	ds	2

