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

	ifndef	Z80182
Z80182	equ	1
	include	Z180.INC
	endif

CR	equ	0Dh
LF	equ	0Ah

FALSE	equ	0
TRUE	equ	NOT FALSE

	public	BADINT,TMRINT,$UGETB,$UPUTB,$UGETW,$UPUTW,$MCOPY
	public	ITBL,ITBLP,$SBANK,$UBANK,IHPOOL,IHPTR,IHSP,IHSTK
	public	UCBAR,SCBAR,UPTIME,TICSEC,TICCNT,INTACK,TFLAG

	extrn	CHKWD,DECCT,DOCLKQ,$CTCB,LNKFQB

;--------------------------------------------------------------------

; Dummy interrupt handler

BADINT:	ret

;--------------------------------------------------------------------

; Timer interrupt handler.

TMRINT:	di
	push	af
	call	INTACK
	push	hl
	call	INCTKC		; increment absolute time counter
	call	INCUPT		; increment uptime counter
	ld	hl,TFLAG
	set	0,(hl)
	pop	hl
	ld	a,(SYSLVL)	; check system level
	dec	a		; user state?
	jr	z,user		; branch if yes

	; interrupt from system or user priv mode

	push	bc
	push	de
	push	hl
	push	ix
	push	iy
	ld	hl,0
	inc	a
	jp	m,sys

	; interrupt from privileged task in exclusive access mode

	add	hl,sp
	ld	sp,SYSSTK	; switch to system stack
	ld	a,($SBANK)
	out0	(BBR),a		; map kernel in

sys:	; interrupt from system mode, kernel is mapped in
	; just handle device timeouts and exit

	push	hl
	call	CHKWD
	call	DECCT
	pop	hl

	; Because SYSLVL=-1 we cannot call DOCLKQ, as we may have interrupted
	; a fork process or system function that modifies the pool state
	; and/or the task list. Instead, we set a flag (see TFLAG above)
	; and execute the action in SYSXIT.

	ld	a,h
	or	l
	jr	z,sret

	ld	a,($UBANK)
	out0	(BBR),a
	ld	sp,hl

sret:	pop	iy
	pop	ix
	pop	hl
	pop	de
	pop	bc
	pop	af
	ei
	ret

user:	; interrupt from user mode, dispatch next task

	push	bc
	push	de
	push	hl
	ex	af,af'
	push	af
	ex	af,af'
	exx
	push	bc
	push	de
	push	hl
	exx
	push	ix
	push	iy
	ld	hl,0
	add	hl,sp		; get task's SP into HL
	ld	a,($SBANK)	; switch to system context
	out0	(BBR),a		;  (TCB's reside in system memory)
	ld	sp,SYSSTK	; switch to system stack
	ld	ix,($CTCB)	; get pointer to current TCB
	ld	(ix+T.SP),l	; save SP in task's TCB
	ld	(ix+T.SP+1),h
	ld	a,-1
	ld	(SYSLVL),a	; we're in global system state
	call	CHKWD		; handle device timeouts
	call	DECCT		; decrement interval counters
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
; HL = src address, HL' = src bank
; DE = dst address, DE' = dst bank
; BC = count
; Notes:
; - should be called with interrupts disabled, unless the stack is
;   in common area.
; - don't call via SWSTK, since the last enables interrupts.
; - only 8-bit bank numbers are supported
; - uses B'C'

$MCOPY:	ld	a,b		; check count
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
	out0	(BBR),l		; set src bank
	exx
	ld	(tmpadr),de	; note we cannot use stack, as it may be
	ld	(tmpcnt),bc	;  out of context
	ld	de,MBUF
	ld	bc,256
	ldir			; copy 256 bytes from src address to buffer
	ld	de,(tmpadr)
	exx
	out0	(BBR),e		; set dst bank
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
	out0	(BBR),l		; set src bank
	exx
	ld	(tmpadr),de	; note we cannot use stack, as it may be
	ld	(tmpcnt),bc	;  out of context
	ld	de,MBUF
	ldir			; copy remaining bytes from src address to buffer
	ld	bc,(tmpcnt)
	ld	de,(tmpadr)
	exx
	out0	(BBR),e		; set dst bank
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

; Get byte from bank E, address HL into A, Call with interrupts disabled
; unless the stack is in common area, otherwise if an interrupt happens
; after BBR is modified the stack will be mapped out and CPU registers will
; be pushed onto the wrong locations by the interrupt routine, corrupting
; memory.

$UGETB:	push	bc
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

; Write byte in A to bank E, address HL. See previous comment concerning
; interrupts.

$UPUTB:	push	de
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

; Read word from bank E, address HL into BC. Returns with HL += 2
; See previous comment concerning interrupts.

$UGETW:	push	de
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

; Write word in BC to bank E, address HL. Returns with HL += 2
; See previous comment concerning interrupts.

$UPUTW:	push	de
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

; ----- data areas

;;	DSEG

TICSEC:	ds	1		; ticks per second
TICCNT:	ds	4		; absolute time count in ticks
UPTIME:	ds	6		; uptime in BCD

TFLAG:	ds	1		; bit 0 = clock queue tick elapsed
				; bit 1 = round-robin interval elapsed
				; bit 2 = swap interval elapsed

$SBANK:	ds	1		; system BBR
$UBANK:	ds	1		; user BBR

UCBAR:	ds	1		; user (normal) CBAR
SCBAR:	ds	1		; supervisor mode CBAR

ITBLP:	ds	2		; interrupt table address
ITBL:	ds	256+128*2	; space for the interrupt table

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

