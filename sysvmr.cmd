[master]system
set /host=P112SBC		! set host name
set /par=syspar:0:16:task
set /par=ldrpar:*:1:task	! create 4K partition for loader
ins ldr				! install loader
fix ldr...			! fix loader in memory
set /par=fcppar:*:3:task	! create 12K partition for filesystem task
;set /par=par20k:*:5:sys
set /par=gen:*:*:sys		! everything else goes to GEN partition
ins sysfcp/acp=yes		! install filesystem task
ins tkn				! install task termination task
fix tktn
ins cot/acp=yes/cli=yes		! install console logger
;ins init
ins mcr				! install command processor
ins sys				! install display part of command processor
ins ins				! install install
ins acs				! install allocate checkpoint file
ins icp				! install indirect command processor
ins hel				! install login processor
ins bye				! install logout processor
ins mou				! install mount
ins dmo				! install dismount
ins ufd				! install user file directory builder
ins ini				! install volume initialization task
ins rmd				! install resource monitoring display task
ins pip				! install pip
ins bro				! install broadcast task
ins mac
ins tkb/inc=30000
ins lbr
ins mkt
ins zap
ins who
ins dmp
ins mce
ins uptime
ins vdo
ins view/task=...mor
ins basic/inc=15000
ins ccl/task=...ca.
ins ted/inc=10000/pri=65
ins md5
ins dcu
ins cpu
ins cal
ins acnt/task=...pwd
set /lower=tt0:
set /lower=tt1:
set /crt=tt0:
set /crt=tt1:
set /logon			! enable user logins
dev
par
tas
set /pool
set /host
