# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = vdo.mac \
	vdocpm.mac \
	vdorsx.mac

OBJS = $(SRCS:.mac=.rel)

all: vdo.com vdo.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

vdo.com: $(OBJS)
	$(ZXCC) $(DRLINK) -"$@=vdo,vdocpm"

vdo.bin: $(OBJS) syslib.lib
	$(ZXCC) $(DRLINK) -"$@=vdo,vdorsx,syslib.lib[s]"

vdo.tsk: vdo.bin
	$(MKTASK) $< -o $@ -name "...VDO" -id "V2.1" -inc 30000 -pri 65

copy:
	cpmrm -f p112 /dev/fd0 0:vdo.com
	cpmcp -f p112 /dev/fd0 vdo.com 0:

clean:
	rm -f vdo.com vdo.bin vdo.tsk *.rel *.sym *.prn *.crf core *~ *.\$$\$$\$$
