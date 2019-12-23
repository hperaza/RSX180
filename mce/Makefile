# Path to Linux utilities
ZXCC    = zxcc
VOL180  = ../Tools/linux/vol180/vol180
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = mce.mac

OBJS = $(SRCS:.mac=.rel)

BIN = mce.bin

PROG = mce.tsk

all: $(PROG)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BIN): $(OBJS) fcslib.lib syslib.lib
	$(ZXCC) $(DRLINK) -"$@=mce,fcslib.lib[s],syslib.lib[s]"

$(PROG): %.tsk: %.bin
	$(MKTASK) $< -o $@ -name "...MCE" -id "V4.29" -inc 1024 -pri 60

clean:
	rm -f $(PROG) *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$

copy: mce.tsk
	@echo "cd system" > cpmce.cmd
	@echo "delete mce.tsk" >> cpmce.cmd
	@echo "import mce.tsk mce.tsk /c" >> cpmce.cmd
	@echo "bye" >> cpmce.cmd
	$(VOL180) /dev/fd0 < cpmce.cmd
	@rm cpmce.cmd

copysrc:
	@echo "cd user" > cpmce.cmd
	@echo "delete mceini.cmd" >> cpmce.cmd
	@echo "import mceini.cmd mceini.cmd" >> cpmce.cmd
	@echo "delete mcebld.cmd" >> cpmce.cmd
	@echo "import mcebld.cmd mcebld.cmd" >> cpmce.cmd
	@echo "delete mce.mac" >> cpmce.cmd
	@echo "import mce.mac mce.mac" >> cpmce.cmd
	@echo "bye" >> cpmce.cmd
	$(VOL180) /dev/fd0 < cpmce.cmd
	@rm cpmce.cmd
