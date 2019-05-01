# Path to Linux utilities
ZXCC    = zxcc
VOL180  = ../Tools/linux/vol180/vol180
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.SUFFIXES:		# delete the default suffixes
.SUFFIXES: .mac .rel

SRCS = main.mac \
	termdef.mac \
	cpmio.mac \
	rsxio.mac

OBJS = $(SRCS:.mac=.rel)

all:	zap.com zap.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

zap.com: $(OBJS)
	$(ZXCC) $(DRLINK) zap=termdef,main,cpmio[oc]

zap.bin: $(OBJS) syslib.lib
	$(ZXCC) $(DRLINK) zap.bin=termdef,main,rsxio,syslib.lib[s]

zap.tsk: zap.bin
	$(MKTASK) $< -o $@ -name "...ZAP" -id "1.0"

copy: cprsx

cpcpm: zap.com
	cpmrm -f p112 /dev/fd0 0:zap.com
	cpmcp -f p112 /dev/fd0 zap.com 0:

cprsx: zap.tsk
	@echo "cd system" > cpzap.cmd
	@echo "delete zap.tsk" >> cpzap.cmd
	@echo "import zap.tsk zap.tsk /c" >> cpzap.cmd
	@echo "bye" >> cpzap.cmd
	$(VOL180) /dev/fd0 < cpzap.cmd
	@rm cpzap.cmd

clean:
	rm -f $(OBJS) zap.com zap.bin zap.tsk *.sym *.prn core *~ *.\$$\$$\$$
