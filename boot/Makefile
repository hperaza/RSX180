# Path to Linux utilities
ZXCC    = zxcc
CKSBOOT = ../Tools/linux/cksboot/cksboot

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = fdboot.mac hdboot.mac

OBJS = $(SRCS:.mac=.rel)

all: fdboot.bin hdboot.bin

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

fdboot.bin: fdboot.rel
	$(ZXCC) $(DRLINK) -"$@=fdboot[nr,oc,l0]"
	$(CKSBOOT) $@

hdboot.bin: hdboot.rel
	$(ZXCC) $(DRLINK) -"$@=hdboot[nr,oc,l0]"
	$(CKSBOOT) $@

cpboot: fdboot.bin
	dd if=fdboot.bin of=/dev/fd0

clean:
	rm -f *.bin *.rel *.prn *.sym core *~ *.\$$\$$\$$
