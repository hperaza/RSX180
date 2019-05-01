; .GOSUB/.RETURN test
;
; single call
	.gosub sub1
; nested call
	.gosub sub2
; return without call - error
	.return
	.stop
.sub1:
;	on sub 1
	.return
.sub2:
;	on sub 2
	.gosub sub1
;	on sub 2 after call to sub 1
	.return
