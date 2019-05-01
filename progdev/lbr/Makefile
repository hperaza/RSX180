# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../../Tools/cpm/zsm4.com
DRLINK  = ../../Tools/cpm/drlink.com

.SUFFIXES:
.SUFFIXES: .mac .rel

SRCS = lbr.mac \
	cpmio.mac \
	rsxio.mac

OBJS = $(SRCS:.mac=.rel)
XRFS = $(SRCS:.mac=.crf)

all: lbr.com lbr.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

lbr.com: $(OBJS)
	$(ZXCC) $(DRLINK) -"$@=lbr,cpmio"

lbr.bin: $(OBJS) syslib.lib fcslib.lib
	$(ZXCC) $(DRLINK) -"$@=lbr,rsxio,fcslib.lib[s],syslib.lib[s]"

lbr.tsk: %.tsk: %.bin
	$(MKTASK) $< -o $@ -name "...LBR" -id "V1.3" -inc 4000

clean:
	rm -f *.com *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$
