# Path to Linux utilities
ZXCC   = zxcc
MKTASK = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4   = ../Tools/cpm/zsm4.com
LBR    = ../Tools/cpm/lbr.com
DRLINK = ../Tools/cpm/drlink.com

SRCS = main.mac

OBJS = $(SRCS:.mac=.rel)

PROG = ldr.tsk

all: $(PROG)

.SUFFIXES:		# delete the default suffixes
.SUFFIXES: .mac .rel

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

ldr.tsk: $(OBJS)
	$(ZXCC) $(DRLINK) -"ldr.bin=main"
	$(MKTASK) ldr.bin -o $@ -name LDR... -id V6.07 -par LDRPAR -pri 250 -priv

clean:
	rm -f $(OBJS) $(PROG) ldr.bin *.sym *.prn core *~ *.\$$\$$\$$
