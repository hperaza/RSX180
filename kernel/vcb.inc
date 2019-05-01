; Mounted Volume Control Block (VCB) fields

M.LNK	equ	0		; link to next item in list (2 bytes)
M.DEV	equ	M.LNK + 2	; mounted physical device name (2 bytes)
M.UNIT	equ	M.DEV + 2	; mounted physical device unit (1 byte)
M.LABEL	equ	M.UNIT + 1	; volume label (16 bytes)
M.NBLKS	equ	M.LABEL + 16	; number of blocks (2 bytes)
M.DFPR	equ	M.NBLKS + 2	; default file protection bits (2 bytes)
M.FCBL	equ	M.DFPR + 2	; FCB list head (2 bytes)
M.IXFB	equ	M.FCBL + 2	; starting block of index file (2 bytes)
M.IXNB	equ	M.IXFB + 2	; size of index file in blocks (2 bytes)
M.BMFB	equ	M.IXNB + 2	; starting block of bitmap file (2 bytes)
M.MFCB	equ	M.BMFB + 2	; master directory FCB address (2 bytes)
M.FTCB	equ	M.MFCB + 2	; TCB of FCP task managing this unit (2 bytes)

; Mount table entry size

MNTSZ	equ	M.FTCB + 2

