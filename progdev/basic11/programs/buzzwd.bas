100 PRINT"THIS COMPUTER DEMONSTRATION IS A NEW AID FOR"
110 PRINT"PREPARING SPEECHES AND BRIEFINGS.  IT'S A BUZZWORD"
120 PRINT"GENERATOR WHICH PROVIDES YOU WITH A SET OF 3 HIGHLY"
130 PRINT"ACCEPTABLE WORDS TO WORK INTO YOUR MATERIAL.  THE WORDS"
140 PRINT"DON'T ACTUALLY MEAN ANYTHING, BUT THEY SOUND GREAT."
150 PRINT
160 PRINT"THE PROCEDURE:"
170 PRINT"     THINK OF ANY THREE NUMBERS BETWEEN 0 AND 9.  ENTER"
180 PRINT"     THEM AFTER THE '?' SEPARATED BY COMMAS.   YOUR"
190 PRINT"     BUZZWORD WILL BE PRINTED OUT.  TYPING '100' FOR"
191 PRINT"     EACH OF YOUR CHOICES STOPS THIS PROGRAM."
210 PRINT "WHAT ARE YOUR THREE NUMBERS";
220 GOTO260
230 PRINT
240 PRINT
250 PRINT"THREE MORE NUMBERS";
260 INPUT N,M,P
265 IF N=100 THEN 1290
270 IF N<O THEN 1240
280 IF P<0 THEN 1240
290 IF M<0 THEN 1240
300 IF N>9 THEN 1240
310 IF P>9 THEN 1240
320 IF M>9 THEN 1240
330 PRINT
340 IF N=0 THEN 640
350 IF N=1THEN 660
360 IF N=2THEN 680
370 IF N=3THEN 700
380 IF N=4 THEN 720
390 IF N=5THEN 740
400 IF N=6THEN 760
410 IF N=7THEN 780
420 IF N=8THEN 800
430 IF N=9THEN 820
440 IF M=0 THEN 840
450 IF M=1 THEN 860
460 IF M=2 THEN 880
470 IF M=3 THEN 900
480 IF M=4 THEN 920
490 IF M=5 THEN 940
500 IF M=6 THEN 960
510 IF M=7 THEN 980
520 IF M=8 THEN 1000
530 IF M=9 THEN 1020
540 IF P=0 THEN 1040
550 IF P=1 THEN 1060
560 IF P=2 THEN 1080
570 IF P=3 THEN 1100
580 IFP=4 THEN 1120
590 IF P=5 THEN 1140
600 IF P=6 THEN 1160
610 IF P=7  THEN 1180
620 IF P=8 THEN 1200
630 IF P=9 THEN 1220
640 PRINT" INTEGRATED";
650 GOTO440
660 PRINT" TOTAL";
670 GOTO440
680 PRINT "SYSTEMATIZED";
690 GOTO440
700 PRINT" PARALLEL";
710 GO TO 440
720 PRINT" FUNCTIONAL";
730 GOTO440
740 PRINT" RESPONSIVE";
750 GOTO440
760 PRINT" OPTIMAL";
770 GOTO440
780 PRINT" SYNCHRONIZED";
790 GOTO440
800 PRINT " COMPATIBLE";
810 GOTO440
820 PRINT" BALANCED";
830 GOTO440
840 PRINT" MANAGEMENT";
850 GOTO 540
860 PRINT" ORGANIZATIONAL";
870 GOTO 540
880 PRINT" MONITORED";
890 GOTO 540
900 PRINT" RECIPROCAL";
910 GOTO 540
920 PRINT" DIGITAL";
930 GOTO 540
940 PRINT" LOGISTICAL";
950 GOTO 540
960 PRINT " TRANSITIONAL";
970 GOTO 540
980 PRINT" INCREMENTAL";
990 GOTO 540
1000 PRINT" THIRD-GENERATION";
1010 GO TO 540
1020 PRINT" POLICY";
1030 GOTO 540
1040 PRINT" OPTIONS"
1050 GOTO 230
1060 PRINT " FLEXIBILITY"
1070 GO TO 230
1080 PRINT" CAPABILITY"
1090 GOTO230
1100 PRINT" MOBILITY"
1110 GOTO230
1120 PRINT" PROGRAMMING"
1130 GO TO 230
1140 PRINT" CONCEPT"
1150 GOTO230
1160 PRINT" TIME-PHASE"
1170 GOTO230
1180 PRINT" PROJECTION"
1190 GOTO230
1200 PRINT" HARDWARE"
1210 GOTO230
1220 PRINT" CONTINGENCY"
1230 GOTO230
1240 PRINT
1250 PRINT
1260 PRINT"NUMBERS MUST BE BETWEEN 0 AND 9.  PLEASE SELECT THREE MORE."
1270 GOTO 260
1280 GOTO 260
1290 PRINT "GOODBYE FOR NOW!    "
1300 PRINT\PRINT\PRINT
1320 END
