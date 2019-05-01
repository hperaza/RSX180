.enable substitution
.sets dev p1
.if dev = "" .asks dev Enter device to initialize, e.g. DU2:
ini 'dev'"RSX180"
.if <exstat> ne <succes> .stop
mou 'dev'
.if <exstat> ne <succes> .stop
ufd 'dev'[system]/owner=[1,1]
pip 'dev'[system]=sy:[system]*.*/cd
pip 'dev'[master]system.sys;*/de
pip 'dev'[master]=sy:[master]system.sys/cd
ini 'dev'/wb
ufd 'dev'[help]/owner=[1,2]
pip 'dev'[help]=sy:[help]*.*/cd
ufd 'dev'[syslog]/owner=[1,5]
ufd 'dev'[basic]/owner=[20,1]
pip 'dev'[basic]=sy:[basic]*.*/cd
ufd 'dev'[user]/owner=[20,2]
pip 'dev'[user]=sy:[user]*.*/cd
ufd 'dev'[games]/owner=[20,3]
pip 'dev'[games]=sy:[games]*.*/cd
ufd 'dev'[test]/owner=[20,4]
pip 'dev'[test]=sy:[test]*.*/cd
pip 'dev'/fr
dmo 'dev'
