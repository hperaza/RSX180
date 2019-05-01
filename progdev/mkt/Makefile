# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../../Tools/linux/mktask/mktask
VOL180  = ../../Tools/linux/vol180/vol180

# Path to CP/M utilities
ZSM4    = ../../Tools/cpm/zsm4.com
DRLINK  = ../../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = main.mac
OBJS = $(SRCS:.mac=.rel)

all: mkt.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

mkt.bin: $(OBJS) syslib.lib fcslib.lib
	$(ZXCC) $(DRLINK) -"$@=main,fcslib.lib[s],syslib.lib[s]"

mkt.tsk: mkt.bin
	$(MKTASK) $< -o $@ -name "...MKT" -id "160520" -asg "SY0:1-4,TI:5"

copy: mkt.tsk
	@echo "cd system" > cpmkt.cmd
	@echo "delete mkt.tsk" >> cpmkt.cmd
	@echo "import mkt.tsk mkt.tsk /c" >> cpmkt.cmd
	@echo "dir" >> cpmkt.cmd
	@echo "bye" >> cpmkt.cmd
	$(VOL180) /dev/fd0 < cpmkt.cmd
	@rm cpmkt.cmd

clean:
	rm -f mkt.bin mkt.tsk *.rel *.sym *.prn *.crf core *~ *.\$$\$$\$$
