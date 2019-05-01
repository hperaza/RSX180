# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../../Tools/linux/mktask/mktask
VOL180  = ../../Tools/linux/vol180/vol180

# Path to CP/M utilities
ZSM4    = ../../Tools/cpm/zsm4.com
DRLINK  = ../../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = link.mac \
	linkcpm.mac \
	linkrsx.mac

OBJS = $(SRCS:.mac=.rel)

all: tkb.com tkb.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l/s8"

tkb.com: $(OBJS)
	$(ZXCC) $(DRLINK) -"tkb=link,linkcpm"
	cp tkb.sym tkbcpm.sym

tkb.bin: $(OBJS) syslib.lib
	$(ZXCC) $(DRLINK) -"tkb.bin=link,linkrsx,syslib.lib[s]"
	cp tkb.sym tkbrsx.sym

tkb.tsk: tkb.bin
	$(MKTASK) $< -o $@ -name "...TKB" -id "1.40" -inc 20000 -asg "TI:5,SY:1-4:6-14"

test: tkb.com
	@cp tkb.com tk.com
	$(ZXCC) tk -"tkb1=link,linkcpm"
	@rm tk.com
	comp tkb.com tkb1.com > comp_tkb_tkb1
	ls -l comp_tkb_tkb1

clean:
	rm -f tkb.com tkb.bin tkb.tsk *.rel *.sym *.prn *.crf core *~ *.\$$\$$\$$

copy: tkb.tsk
	@echo "cd system" > cptkb.cmd
	@echo "delete tkb.tsk" >> cptkb.cmd
	@echo "import tkb.tsk tkb.tsk /c" >> cptkb.cmd
	@echo "bye" >> cptkb.cmd
	$(VOL180) /dev/fd0 < cptkb.cmd
	@rm cptkb.cmd
