; Buffer equates

BLKSZ	equ	512		; block size

; Buffer offsets

B.LNK	equ	0		; link to next buffer in list (2 bytes)
B.DEV	equ	B.LNK + 2	; physical device name (2 bytes)
B.UNIT	equ	B.DEV + 2	; device unit (1 byte)
B.BLKNO	equ	B.UNIT + 1	; block number (2 bytes)
B.ACCS	equ	B.BLKNO + 2	; access counter (1 byte)
B.MODF	equ	B.ACCS + 1	; modified flag (1 byte)
B.VALID	equ	B.MODF + 1	; valid (loaded) flag (1 byte)
B.DATA	equ	B.VALID + 1	; data field (1 block = 512 bytes)

BUFSZ	equ	B.DATA + BLKSZ

