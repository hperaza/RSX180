10 RANDOMIZE
20 PRINT "THIS IS A GAME OF......RUSSIAN ROULETTE."
30 PRINT  \ PRINT "HERE IS A REVOLVER."
40 PRINT "HIT (1) TO SPIN THE CHAMBER AND PULL TRIGGER."
50 PRINT "HIT (2) TO GIVE UP!"
60 PRINT " GO ";
70 LET N=0
80 INPUT I
90 IF I=1 THEN 120
100 PRINT "* * * * CHICKEN * * * * "
110 GO TO 190
120 LET N=N+1
130 IF RND(0)>.83333 THEN 170
140 IF N>5 THEN 210
150 PRINT "- CLICK -"
160 PRINT  \ GO TO 80
170 PRINT CHR$(7);"        BANG!!!!!   YOU'RE DEAD!"
180 PRINT "CONDOLENCES WILL BE SENT TO YOUR RELATIVES."
190 PRINT  \ PRINT  \ PRINT "......NEXT VICTIM......"
200 GO TO 40
210 PRINT "     YOU WIN!!!"
220 PRINT "LET SOMEONE ELSE BLOW HIS BRAINS OUT."
230 PRINT "WOULD YOU CARE TO TRY AGAIN? (1=YES, 0=NO)";
240 INPUT K
250 IF K=1 THEN 60
260 END
