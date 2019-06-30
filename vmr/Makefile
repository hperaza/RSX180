# Path to Linux utilities
ZXCC   = zxcc
VOL180 = ../Tools/linux/vol180/vol180
MKTASK = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4   = ../Tools/cpm/zsm4.com
DRLINK = ../Tools/cpm/drlink.com

.SUFFIXES:
.SUFFIXES: .mac .rel

SRCS = main.mac \
	symbols.mac \
	tasks.mac \
	pars.mac \
	devices.mac \
	pool.mac \
	vmem.mac

OBJS = $(SRCS:.mac=.rel)

all: vmr.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

vmr.bin: $(OBJS) syslib.lib
	$(ZXCC) $(DRLINK) -"$@=main,symbols,devices,tasks,pars,pool,vmem,syslib.lib[s]"

vmr.tsk: %.tsk: %.bin
	$(MKTASK) $< -o $@ -name "...VMR" -id "V1.0"

copy: vmr.tsk
	@echo "cd system" > copy.cmd
	@echo "delete vmr.tsk" >> copy.cmd
	@echo "import vmr.tsk vmr.tsk /c" >> copy.cmd
	@echo "dir" >> copy.cmd
	@echo "bye" >> copy.cmd
	$(VOL180) /dev/fd0 < copy.cmd
	@rm copy.cmd

clean:
	rm -f *.com *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$
