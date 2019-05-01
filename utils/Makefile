# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = cal.mac \
	clock.mac \
	cookie.mac \
	dmp.mac \
	md5.mac \
	murphy.mac \
	quote.mac \
	view.mac

OBJS = $(SRCS:.mac=.rel)
BINS = $(OBJS:.rel=.bin)
PROGS = $(BINS:.bin=.tsk)

all: $(PROGS)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BINS): %.bin: %.rel syslib.lib fcslib.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,fcslib.lib[s],syslib.lib[s]"

$(PROGS): %.tsk: %.bin
	$(MKTASK) $< -o $@

cal.tsk: cal.bin
	$(MKTASK) $< -o $@ -name "...CAL" -id "V01.00"

clock.tsk: clock.bin
	$(MKTASK) $< -o $@ -name "...CLK" -id "V01.00"

dmp.tsk: dmp.bin
	$(MKTASK) $< -o $@ -name "...DMP" -id "V3.11"

md5.tsk: md5.bin
	$(MKTASK) $< -o $@ -name "...MD5" -id "V1.01"

view.tsk: view.bin
	$(MKTASK) $< -o $@ -inc 10000 -name "...VIE" -id "4.0"

clean:
	rm -f *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$
