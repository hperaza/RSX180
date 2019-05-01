;
;	EXAMP.CMD
;
	.ENABLE SUBSTITUTION
	.ENABLE GLOBAL
	.;------------------------------------------------------------
	.;
	.; This procedure calculates the day of the week from the
	.; date obtained from the system.
	.;
	.;------------------------------------------------------------
	.;
	.; DAYS OF THE WEEK.
	.;
	.SETS DAYS "SUN   MON   TUES  WEDNESTHURS FRI   SATUR SUN   "
	.;
	.; MONTHS OF THE YEAR.
	.;
	.SETS MONTHS "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC"
	.;
	.; NUMBERS FOR DAYS OF THE MONTH.
	.;
	.SETS DAT "'<DATE>'"			! GET TODAYS DATE.
	.SETS TIM "'<TIME>'"			! GET THE TIME.
	.SETS DAY DAT[1:2]			! EXTRACT THE DAY
	.SETN DAYN 'DAY'
	.SETS MONTH DAT[4:6]			! EXTRACT THE MONTH
	.SETS YEAR DAT[8:11]			! EXTRACT THE YEAR
	.SETN YEARN 'YEAR'
	.SETN MONCNT 1				! INIT MONTH COUNTER
	.SETN NDX 1				! INIT MONTH INDEX
.MLOOP:
	.SETS TEMP MONTHS[NDX:NDX+2]		! SET TEMP TO MONTH
	.IF TEMP = MONTH .GOTO 10		! BRANCH IF CORRECT MONTH
	.INC MONCNT				! BUMP MONTH COUNTER
	.SETN NDX NDX+3				! POINT AT NEXT MONTH
	.GOTO MLOOP				! TRY NEXT MONTH
	.;
	.;
.10:
	.SETN Y YEARN
	.IF MONCNT < 3 .DEC Y
	.SETS TS "032503514624"
	.SETS TN TS[MONCNT:MONCNT]
	.SETN T 'TN'
	.SETN W Y+Y/4-Y/100+Y/400+T+DAYN
	.SETN DAYNDX W%7			! DAY INDEX (SUNDAY = 0)
	.SETN DAYNDX DAYNDX*6+1			! INDEX INTO DAYS LIST
	.SETS $DAY DAYS[DAYNDX:DAYNDX+5]	! GET DAY OF THE WEEK
	;
	; The date is 'DAT',
	; The time is 'TIM', and
	; Today is '$DAY%C'DAY.
	;
	; See you tomorrow.
	;
