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

	public	SYSENT,SYSXIT,SYSLVL,DSPFLG,TRPFLG,DOFORK

	extrn	SYSFN,TKILL,FORKQ,KFREE,CHKCLQ,DOAST,CPCB
;;	extrn	SYSBBR,APPBBR,USRBBR

;-----------------------------------------------------------------------

; New system trap entry:
; - all registers are saved into the task's stack frame.
; - stack is switched to system in common memory.
; - system level variable gets decremented to prevent dispatch until
;   we return.
; - interrupts are reenabled.

SYSENT:	di
	ex	af,af'
	push	af		; all registers are save in task's stack frame
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
	ld	hl,0
	add	hl,sp
	ld	a,(SYSBBR)
	out0	(BBR),a		; switch to system context
	ld	sp,SYSSTK	; switch to system stack in common memory
	ld	ix,(CTCB)
	ld	(ix+T.SP),l	; save SP in task's TCB
	ld	(ix+T.SP+1),h
	ld	hl,SYSLVL
	dec	(hl)		; we are now in global system state
	ei			; enable interrupts

	xor	a
	ld	(DSPFLG),a	; clear redispatch flag

	ld	a,(TRPFLG)
	or	a		; abnormal task exit? trap happened?
	jr	z,normal	; proceed normally if not

	ld	e,a		; E = reason code

	xor	a
	ld	(TRPFLG),a
	ld	bc,(CTCB)	; else abort the current task
	call	TKILL
	jr	SYSXIT		; TKILL never returns, anyway

normal:	call	SYSFN		; handle system call

SYSXIT:	call	DOFORK		; process all pending fork blocks
	jr	nc,SYSXIT

	ld	hl,TFLAG
	ld	a,(hl)
	ld	(hl),0
	or	a
	call	nz,CHKCLQ	; check the clock queue

  IF 0
	ld	a,(DSPFLG)	; task changed state?
	or	a
	call	nz,DSPTCH	; redispatch if yes
  ELSE
	call	DSPTCH
  ENDIF

	call	DOAST		; if there is a pending AST for this task,
				;  execute it now
	di
	ld	hl,SYSLVL
	inc	(hl)		; leaving system state
	ld	ix,(CTCB)
	bit	TS.SUP,(ix+T.ST) ; check if task is in supervisor mode
	ld	a,(UCBAR)	 ; user-mode memory map
	jr	z,go2
	ld	a,(SCBAR)	 ; supervisor-mode memory map
go2:	out0	(CBAR),a
	ld	hl,(CPCB)
	ld	de,P.BASE
	add	hl,de
	ld	a,(hl)
	ld	l,(ix+T.SP)
	ld	h,(ix+T.SP+1)
	out0	(BBR),a		; bring task into context
	ld	sp,hl		; restore task's SP
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
	ei
	ret

;-----------------------------------------------------------------------

; Fork block execution. Removes first queued fork block from the list
; and calls the corresponding routine. Returns CY if the list is empty.

FBSZ	equ	8

DOFORK:	di
	ld	iy,FORKQ
	ld	l,(iy)
	ld	h,(iy+1)
	ld	a,h
	or	l
	scf
	jp	z,frk3		; return if queue empty.
	push	hl
	ld	a,(hl)
	ld	(iy),a		; unlink the fork block
	inc	hl
	ld	a,(hl)
	ld	(iy+1),a
	ei
	inc	hl
	ld	a,(hl)		; type
	inc	hl
	ld	e,(hl)		; bank
	inc	hl
	ld	c,(hl)		; routine address
	inc	hl
	ld	b,(hl)
	inc	hl
	push	bc
	ld	c,(hl)		; IY
	inc	hl
	ld	b,(hl)
	push	bc
	pop	iy
	pop	bc		; routine address
	pop	hl
	or	a		; static?
	jr	z,frk1		; skip deallocation if yes
	push	iy
	push	ix
	push	bc
	push	de
	ld	de,FBSZ
	call	KFREE		; free the fork block
	pop	de
	pop	bc
	pop	ix
	pop	iy
frk1:	in0	a,(BBR)		; SYSBBR
	push	af
	out0	(BBR),e		; note that stack is in common memory!
	ld	hl,frk2
	push	hl		; push return address
	push	bc
	ret			; call the routine
frk2:	pop	af
	out0	(BBR),a
	or	a
	ret
frk3:	ei
	ret

;-----------------------------------------------------------------------

;	dseg

SYSLVL:	ds	1
DSPFLG:	ds	1
TRPFLG:	ds	1

