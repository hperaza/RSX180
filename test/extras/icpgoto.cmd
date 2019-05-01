; .IF/.GOTO test
.;
	.enable substitution
	.setn i 1
.loop:
;	i = 'i'
	.setn i i+1
	.if i <= 10 .goto loop
	.stop
