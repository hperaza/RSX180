# Path to Linux utilities
ZXCC = zxcc

# Path to CP/M utilities
ZSM4 = ../Tools/cpm/zsm4.com
TKB  = ../Tools/cpm/tkb.com

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
	$(ZXCC) $(TKB) -"$@=vdo/of=com,vdocpm"

vdo.tsk: $(OBJS) syslib.lib
	$(ZXCC) $(TKB) -"$@=vdo/of=tsk,vdorsx,syslib/lb/task=...VDO/ext=30000/pri=65"

copy:
	cpmrm -f p112 /dev/fd0 0:vdo.com
	cpmcp -f p112 /dev/fd0 vdo.com 0:

clean:
	rm -f vdo.com vdo.tsk *.rel *.sym *.prn *.crf *.map core *~ *.\$$\$$\$$
