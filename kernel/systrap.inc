;**********************************************************************;
;                                                                      ;
;   This file is part of RSX180, a multi-tasking OS for the Z180.      ;
;   Copyright (C) 1985-2020, Hector Peraza.                            ;
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

	public	SYSENT,SYSXIT,SYSLVL,TRPFLG,DOFORK

	extrn	SYSFN,TKILL,$FORKQ,$FREE,DOCLKQ,DSPTCH,DOAST,$CPCB
;;	extrn	$SBANK

;-----------------------------------------------------------------------

; System trap entry:
; - all registers are saved into the task's stack frame.
; - stack is switched to system in common memory.
; - system level variable gets decremented to prevent dispatch until
;   we return.
; - interrupts are reenabled.

SYSENT:	di
	push	af
	push	bc
	push	de
	push	hl
	ex	af,af'
	push	af		; all registers are saved in task's stack frame
	ex	af,af'
	exx
	push	bc
	push	de
	push	hl
	exx
	push	ix
	push	iy
	ld	hl,0
	add	hl,sp
	ld	a,($SBANK)
	out0	(BBR),a		; switch to system context
	ld	sp,SYSSTK	; switch to system stack in common memory
	ld	ix,($CTCB)
	ld	(ix+T.SP),l	; save SP in task's TCB
	ld	(ix+T.SP+1),h
	ld	a,-1
	ld	(SYSLVL),a	; we are now in global system state
	ei			; enable interrupts

	ld	a,(TRPFLG)	; check trap flag
	or	a		; abnormal task exit? trap happened?
	jr	z,normal	; proceed normally if not

	ld	e,a		; E = reason code

	xor	a
	ld	(TRPFLG),a
	ld	bc,($CTCB)	; else abort the current task
	call	TKILL
	jr	SYSXIT		; TKILL never returns, anyway

normal:	call	SYSFN		; handle system call

SYSXIT:	ld	sp,SYSSTK
	call	DOFORK		; process all pending fork blocks
	jr	nc,SYSXIT

	ld	hl,TFLAG
	bit	0,(hl)
	jr	z,go1
	res	0,(hl)
	call	DOCLKQ		; dispatch the clock queue

go1:	call	DSPTCH		; prepare next task to dispatch
	call	DOAST		; if there is a pending AST for this task,
				;  execute it now
	jr	c,SYSXIT	; on AST error (bad stack), redispatch

	di
	ld	a,1
	ld	(SYSLVL),a	; leaving system, entering user state
	ld	ix,($CTCB)
	bit	TS.SUP,(ix+T.ST); check if task is in supervisor mode
	ld	a,(UCBAR)	; user-mode memory map
	jr	z,go2
	ld	a,(SCBAR)	; supervisor-mode memory map
go2:	out0	(CBAR),a
	ld	hl,($CPCB)
	ld	de,P.BASE
	add	hl,de
	ld	a,(hl)
	ld	l,(ix+T.SP)
	ld	h,(ix+T.SP+1)
	out0	(BBR),a		; bring task into context
	ld	sp,hl		; restore task's SP
	pop	iy
	pop	ix
	exx
	pop	hl
	pop	de
	pop	bc
	exx
	ex	af,af'
	pop	af
	ex	af,af'
	pop	hl
	pop	de
	pop	bc
	pop	af
	ei
	ret

;-----------------------------------------------------------------------

; Fork block execution. Removes first queued fork block from the list
; and calls the corresponding routine. Returns CY if the list is empty.

DOFORK:	di
	ld	hl,$FORKQ
	ld	e,(hl)		; get first fork block in list into DE
	inc	hl
	ld	d,(hl)
	dec	hl
	ld	a,d
	or	e
	scf
	jp	z,frk1		; return if queue empty.
	ex	de,hl		; get fork block address into HL
	ld	a,(hl)
	ld	(de),a		; unlink the fork block
	inc	hl
	inc	de
	ld	a,(hl)
	ld	(de),a
	ei			; interrupts can happen from now on
	inc	hl
	ld	a,(hl)		; get bank
	inc	hl
	ld	e,(hl)		; get routine address into DE
	inc	hl
	ld	d,(hl)
	inc	hl
	ld	c,(hl)		; get context
	inc	hl
	ld	b,(hl)
	push	bc
	pop	iy		;  into IY
	ld	c,a		; bank now in C
	in0	a,(BBR)		; $SBANK
	push	af
	out0	(BBR),c		; note that stack is in common memory!
	ex	de,hl
	call	jphl		; call the routine
	pop	af
	out0	(BBR),a
	xor	a
frk1:	ei
	ret

jphl:	jp	(hl)

;-----------------------------------------------------------------------

;	dseg

SYSLVL:	ds	1		; system level:
				;  1 = user task state
				;  0 = priv task accessing kernel data
				; -1 = system state
TRPFLG:	ds	1		; trap flag

