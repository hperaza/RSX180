; Buffer equates

BLKSZ	equ	512		; block size

; Buffer offsets

B.LNK	equ	0		; link to next buffer in list (2 bytes)
B.ST	equ	B.LNK + 2	; status (1 byte)
B.DEV	equ	B.ST + 1	; physical device name (2 bytes)
B.UNIT	equ	B.DEV + 2	; device unit (1 byte)
B.BLKNO	equ	B.UNIT + 1	; block number (2 bytes)
B.ACCS	equ	B.BLKNO + 2	; access count (1 byte)
B.DATA	equ	B.ACCS + 1	; start of data field (1 block = 512 bytes)

BUFSZ	equ	B.DATA + BLKSZ	; buffer size

; Status bits

BS.VAL	equ	0		; valid
BS.MOD	equ	1		; modified

