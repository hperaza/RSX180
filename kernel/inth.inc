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

	ifndef	Z80182
Z80182	equ	1
	include	Z180.INC
	endif

CR	equ	0Dh
LF	equ	0Ah

FALSE	equ	0
TRUE	equ	NOT FALSE

DBGINT	equ	FALSE		; make sure it maches the value in INTS.MAC!!!

	public	BADINT,TMRINT,UGETB,UPUTB,UGETBB,UPUTBB,MEMCPY
	public	ITBL,ITBLP,SYSBBR,APPBBR,USRBBR,UGETWB,UPUTWB
	public	IHPOOL,IHPTR,IHSP,IHSTK,UCBAR,SCBAR,UPTIME
	public	UPTIME,TICSEC,TICCNT,INTACK

	extrn	CHKWD,CHKCLQ,DSPTCH,CTCB,LNKFQB

;--------------------------------------------------------------------

; Dummy interrupt handler

BADINT:
	IF	DBGINT
	di
	push	af
	call	iahex
	push	bc
	ld	c,'!'
	call	iputc
	pop	bc
	pop	af
	ei
	ENDIF
	ret

	IF	DBGINT
iahex:	push	af
	rrca
	rrca
	rrca
	rrca
	call	iahex1
	pop	af
iahex1:	and	0Fh
	add	a,90h
	daa
	adc	a,40h
	daa
	push	bc
	ld	c,a
	call	iputc
	pop	bc
	ret

iputc:	in0	a,(SCCACNT)
	and	4
	jr	z,iputc
	out0	(SCCAD),c
	ret
	ENDIF

;--------------------------------------------------------------------

; Timer interrupt handler.

TMRINT:	di
	push	af
	call	INTACK
	push	hl
	call	INCTKC		; increment absolute time counter
	call	INCUPT		; increment uptime counter
	pop	hl
	ld	a,1
	ld	(TFLAG),a
	ld	a,(SYSLVL)	; check system level
	or	a		; interrupt from user mode?
	jr	nz,user		; jump if yes

	push	iy		; else just handle device timeouts and exit
	push	ix
	push	hl
	push	de
	push	bc
	call	CHKWD		; SYSLVL=0 means kernel is mapped in
				; (this means that privileged tasks should
				; not set SYSLVL to zero!)

	; Because SYSLVL=0 we cannot call CHKCLQ, as we may have interrupted
	; a fork process or system function that modifies the pool state
	; and/or the task list. Instead, we set a flag (see TFLAG above)
	; and execute the action in SYSXIT.

	pop	bc
	pop	de
	pop	hl
	pop	ix
	pop	iy
	pop	af
	ei
	ret

user:	pop	af
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
	ld	hl,0
	add	hl,sp		; get task's SP into HL
	ld	a,(SYSBBR)	; switch to system context
	out0	(BBR),a		;  (TCB's reside in system memory)
	ld	sp,SYSSTK	; switch to system stack
	ld	ix,(CTCB)	; get pointer to current TCB
	ld	(ix+T.SP),l	; save SP in task's TCB
	ld	(ix+T.SP+1),h
	ld	hl,SYSLVL
	dec	(hl)		; we're in global system state
	call	CHKWD		; handle device timeouts
	ei			; enable interrupts
	jp	SYSXIT		; return via SYSXIT to dispatch next task

INTACK:	in0	a,(TCR)
	in0	a,(TMDR0L)
	in0	a,(TMDR0H)	; clear the PRT interrupt
	ret

;-----------------------------------------------------------------------

; Increment the uptime counter. Called from the timer interrupt routine
; with interrupts disabled.

INCUPT:	ld	hl,UPTIME
	inc	(hl)		; 1-byte ticks/sec
	ld	a,(TICSEC)
	cp	(hl)
	ret	nz
	ld	(hl),0

	inc	hl
	inc	(hl)		; 1-byte seconds 00..59
	ld	a,60
	cp	(hl)
	ret	nz
	ld	(hl),0

	inc	hl
	inc	(hl)		; 1-byte minutes 00..59
	cp	(hl)		; A still = 60
	ret	nz
	ld	(hl),0

	inc	hl
	inc	(hl)		; 1-byte hours 00..23
	ld	a,24
	cp	(hl)
	ret	nz
	ld	(hl),0

	inc	hl
	inc	(hl)		; 2-byte days 00000..65535
	ret	nz
	inc	hl
	inc	(hl)
	ret

;-----------------------------------------------------------------------

; Increment the absolute time tick counter. Called from the timer interrupt
; routine with interrupts disabled.

INCTKC:	ld	hl,TICCNT
	inc	(hl)
	ret	nz
	inc	hl
	inc	(hl)
	ret	nz
	inc	hl
	inc	(hl)
	ret	nz
	inc	hl
	inc	(hl)
	ret

;-----------------------------------------------------------------------

; Copy block of data from one bank to another
; HL = src address, E' = src bank
; DE = dst address, D' = dst bank
; BC = count
; Notes:
; - should be called with interrupts disabled, unless the stack is
;   in common area.
; - uses B'C'

MEMCPY:	ld	a,b		; check count
	or	c		; anything to move?
	ret	z		; return if not
	exx
	in0	c,(BBR)		; remember initial mapping
	in0	b,(CBAR)	; save also CBAR (task may be in superv. mode)
	exx
	ld	a,(UCBAR)
	out0	(CBAR),a	; force user (normal) CBAR mode
	ld	a,b
	or	a		; less than 256 bytes?
	jr	z,memcp2	; then go directly to last part
memcp1:	exx
	out0	(BBR),e		; set src bank
	exx
	ld	(tmpadr),de	; note we cannot use stack, as it may be
	ld	(tmpcnt),bc	;  out of context
	ld	de,MBUF
	ld	bc,256
	ldir			; copy 256 bytes from src address to buffer
	ld	de,(tmpadr)
	exx
	out0	(BBR),d		; set dst bank
	exx
	ld	(tmpadr),hl
	ld	hl,MBUF
	ld	bc,256
	ldir			; copy 256 bytes from buffer to dest address
	ld	bc,(tmpcnt)
	ld	hl,(tmpadr)
	djnz	memcp1
memcp2:	ld	a,c
	or	a		; any bytes remaining?
	jr	z,memcp3	; finish if not
	exx
	out0	(BBR),e		; set src bank
	exx
	ld	(tmpadr),de	; note we cannot use stack, as it may be
	ld	(tmpcnt),bc	;  out of context
	ld	de,MBUF
	ldir			; copy remaining bytes from src address to buffer
	ld	bc,(tmpcnt)
	ld	de,(tmpadr)
	exx
	out0	(BBR),d		; set dst bank
	exx
	ld	(tmpadr),hl
	ld	hl,MBUF
	ldir			; copy remaining bytes from buffer to dest address
	ld	hl,(tmpadr)
memcp3:	exx
	out0	(CBAR),b
	out0	(BBR),c		; restore original mapping
	exx
	xor	a
	ret

MBUF:	ds	256
tmpadr:	ds	2
tmpcnt:	ds	2

; Get byte from task space into A, address BC. Call with interrupts disabled
; unless the stack is in common area, otherwise if an interrupt happens
; after BBR is modified the stack will be mapped out and CPU registers will
; be pushed in the wrong locations by the interrupt routine, corrupting
; memory.

UGETB:	push	ix
	push	de
	in0	d,(BBR)		; save mapping
	in0	e,(CBAR)
	ld	a,(UCBAR)
	out0	(CBAR),a	; force user-mode mapping
	ld	ix,(CPCB)
	ld	a,(ix+P.BASE)
	out0	(BBR),a		; select task's bank
	ld	a,(bc)		; read value
	out0	(CBAR),e	; restore mapping
	out0	(BBR),d
	pop	de
	pop	ix
	ret

; Write byte in A to task space, address BC. See above comment concerning
; interrupts.

UPUTB:	push	ix
	push	de
	push	hl
	in0	d,(BBR)		; save mapping
	ld	ix,(CPCB)
	ld	e,(ix+P.BASE)
	out0	(BBR),e		; select task's bank
	in0	e,(CBAR)
	ld	l,a
	ld	a,(UCBAR)
	out0	(CBAR),a	; force user-mode mapping
	ld	a,l
	ld	(bc),a		; store byte
	out0	(CBAR),e	; restore mapping
	out0	(BBR),d
	pop	hl
	pop	de
	pop	ix
	ret

; Write byte in A to bank E address HL. See previous comment concerning
; interrupts.

UPUTBB:	push	de
	push	bc
	in0	d,(BBR)		; save mapping
	out0	(BBR),e		; select bank
	in0	e,(CBAR)
	ld	c,a
	ld	a,(UCBAR)	; force user-mode mapping
	out0	(CBAR),a
	ld	a,c
	ld	(hl),a		; store byte
	out0	(CBAR),e	; restore mapping
	out0	(BBR),d
	pop	bc
	pop	de
	ret

; Read byte from bank E address HL into A. See previous comment concerning
; interrupts.

UGETBB:	push	bc
	in0	b,(BBR)		; save mapping
	in0	c,(CBAR)
	ld	a,(UCBAR)
	out0	(CBAR),a	; force user-mode mapping
	out0	(BBR),e		; select bank
	ld	a,(hl)		; read byte
	out0	(CBAR),c	; restore mapping
	out0	(BBR),b
	pop	bc
	ret

; Write word in BC to bank E address HL. Returns with HL += 2
; See previous comment concerning interrupts.

UPUTWB:	push	de
	push	af
	in0	d,(CBAR)	; save mapping
	ld	a,(UCBAR)
	out0	(CBAR),a	; force user-mode mapping
	in0	a,(BBR)
	out0	(BBR),e		; select new bank
	ld	(hl),c		; store word
	inc	hl
	ld	(hl),b
	inc	hl
	out0	(BBR),a		; restore mapping
	out0	(CBAR),d
	pop	af
	pop	de
	ret

; Read word from bank E address HL into BC. Returns with HL += 2
; See previous comment concerning interrupts.

UGETWB:	push	de
	push	af
	in0	d,(CBAR)	; save mapping
	ld	a,(UCBAR)
	out0	(CBAR),a	; force user-mode mapping
	in0	a,(BBR)
	out0	(BBR),e		; select new bank
	ld	c,(hl)		; read word
	inc	hl
	ld	b,(hl)
	inc	hl
	out0	(BBR),a		; restore mapping
	out0	(CBAR),d
	pop	af
	pop	de
	ret

; ----- data areas

;;	DSEG

TICSEC:	ds	1		; ticks per second
TICCNT:	ds	4		; absolute time count in ticks
UPTIME:	ds	6		; uptime in BCD

TFLAG:	ds	1		; CHKCLQ timer tick pending

SYSBBR:	ds	1		; system BBR
APPBBR:	ds	1		; first available BBR after system
USRBBR:	ds	1		; to be removed!!!

UCBAR:	ds	1		; user (normal) CBAR
SCBAR:	ds	1		; supervisor mode CBAR

ITBLP:	ds	2		; interrupt table address
ITBL:	ds	256+128*2	; space for the interrupt table

	IF	DBGINT
	public	STUBS
STUBS:	ds	128*5
	ENDIF

	ds	64		; space for interrupt stack
IHSTK	equ	$
IHSP:	ds	2

IHPTR:	ds	2
IHPOOL:	ds	256		; space for stub handlers that call code
				; in another bank, created dynamically:
				; (Interrupt Transfer Block)
				;
				; inth:	di
				;	ld	(IHSP),sp
				;	ld	sp,IHSTK
				;	push	af
				;	in0	a,(BBR)
				;	push	af
				;	ld	a,[intbbr]
				;	out0	(BBR),a
				;	call	[handler]
				;	pop	af
				;	out0	(BBR),a
				;	pop	af
				;	ld	sp,(IHSP)
				;	ei
				;	ret

