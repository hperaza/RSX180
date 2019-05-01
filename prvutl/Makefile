# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = bro.mac \
	ccl.mac \
	cpu.mac \
	dcu.mac \
	reboot.mac \
	uptime.mac \
	who.mac

OBJS = $(SRCS:.mac=.rel)

BINS = $(OBJS:.rel=.bin)

PROGS = $(BINS:.bin=.tsk)

all: $(PROGS)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BINS): %.bin: %.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,syslib.lib[s]"

$(PROGS): %.tsk: %.bin
	$(MKTASK) $< -o $@

bro.tsk: bro.bin
	$(MKTASK) $< -o $@ -name "...BRO" -id "01.00" -priv

ccl.tsk: ccl.bin
	$(MKTASK) $< -o $@ -name "...CCL" -id "1.65" -pri 90 -priv

# CPU is not really privileged, but it accesses directly the common area
cpu.tsk: cpu.bin
	$(MKTASK) $< -o $@ -name "...CPU" -id "V.2"

dcu.tsk: dcu.bin
	$(MKTASK) $< -o $@ -name "...DCU" -id "01.00" -priv

reboot.tsk: reboot.bin
	$(MKTASK) $< -o $@ -priv

uptime.tsk: uptime.bin
	$(MKTASK) $< -o $@ -priv -name "...UPT" -id "VER1.0"

who.tsk: who.bin
	$(MKTASK) $< -o $@ -pri 100 -priv -name "...WHO" -id "V1.2"

clean:
	rm -f *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$
