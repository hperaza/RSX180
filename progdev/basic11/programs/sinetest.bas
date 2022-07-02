10 DEF FNC$(X,Y)=CHR$(27)&"["&STR$(Y+1)&";"&STR$(X+1)&"H"
20 E$=CHR$(27) \ REM escape
30 H0$=E$+"[H" \ REM home cursor
40 E1$=E$+"[J" \ REM clear to end of screen
50 A=TTYSET(255,255)
60 PRINT H0$+E1$ \ REM clear screen
70 FOR Y=21 TO 1 STEP -1
80 PRINT FNC$(5,Y)+"|"
90 NEXT Y
100 PRINT FNC$(5,1)+"^"
110 PRINT FNC$(5,11)+"+";
120 FOR X=6 TO 75
130 PRINT "-";
140 NEXT X
150 PRINT ">"
160 PRINT FNC$(4,1)+"Y"
170 PRINT FNC$(75,12)+"X"
180 PRINT FNC$(3,11);"0"
190 FOR I=0 TO 68
200 X=I*PI/34
210 Y=SIN(X)
220 PRINT FNC$(INT(5+I),INT(11-9*Y+.5));"*"
230 NEXT I
240 A=TTYSET(255,73)
250 PRINT FNC$(0,21);
260 END
