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
	dir.mac \
	copy.mac \
	delete.mac \
	unlock.mac \
	rename.mac \
	search.mac \
	match.mac

OBJS = $(SRCS:.mac=.rel)

BIN = pip.bin

PROG = pip.tsk

all: $(PROG)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BIN): $(OBJS) fcslib.lib syslib.lib
	$(ZXCC) $(DRLINK) -"$@=main,dir,copy,delete,unlock,rename,search,match,fcslib.lib[s],syslib.lib[s]"

$(PROG): %.tsk: %.bin
	$(MKTASK) $< -o $@ -name "...PIP" -id "M0319" -asg "SY:1-4:6-7,TI:5"

clean:
	rm -f $(PROG) *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$

copy: pip.tsk
	@echo "cd system" > cppip.cmd
	@echo "delete pip.tsk" >> cppip.cmd
	@echo "import pip.tsk pip.tsk /c" >> cppip.cmd
	@echo "bye" >> cppip.cmd
	$(VOL180) /dev/fd0 < cppip.cmd
	@rm cppip.cmd
