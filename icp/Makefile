# Path to Linux utilities
ZXCC    = zxcc
VOL180  = ../Tools/linux/vol180/vol180
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = main.mac \
	commands.mac \
	vars.mac \
	spec.mac \
	eval.mac \
	subst.mac \
	utils.mac

OBJS = $(SRCS:.mac=.rel)

BIN = icp.bin

PROG = icp.tsk

all: $(PROG)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BIN): $(OBJS) fcslib.lib syslib.lib
	$(ZXCC) $(DRLINK) -"$@=main,commands,subst,eval,vars,spec,utils,syslib.lib[s]"
#	$(ZXCC) $(DRLINK) -"$@=main,commands,subst,eval,vars,spec,utils,fcslib.lib[s],syslib.lib[s]"

$(PROG): %.tsk: %.bin
	$(MKTASK) $< -o $@ -name "...AT." -id "2.36" -priv -pri 64 -inc 1024

clean:
	rm -f $(PROG) *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$

copy: $(PROG)
	@echo "cd system" > cpicp.cmd
	@echo "delete icp.tsk" >> cpicp.cmd
	@echo "import icp.tsk icp.tsk /c" >> cpicp.cmd
	@echo "bye" >> cpicp.cmd
	$(VOL180) /dev/fd0 < cpicp.cmd
	@rm cpicp.cmd
