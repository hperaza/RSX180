.enable display
.enable substitution
;
; logical variable test
;
.ask v
;result: 'v'
.ask v test with prompt
;result: 'v'
;
; string variable test
;
.asks v text with spaces
;result: 'v'
;
; numeric variable test
;
.askn n enter a number
;result: 'n'
;
; substitution test
;
.disable display
.asks cmd Enter a MCR command: 
.enable display
'cmd'
.ask [t] v
;'v'
