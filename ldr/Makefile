# Path to Linux utilities
ZXCC = zxcc

# Path to CP/M utilities
ZSM4   = ../Tools/cpm/zsm4.com
LBR    = ../Tools/cpm/lbr.com
DRLINK = ../Tools/cpm/drlink.com

SRCS = main.mac

INC = tcb.inc \
	dcb.inc \
	sysfn.inc \
	errors.inc \
	z180.inc

OBJS = $(SRCS:.mac=.rel)

PROG = ldr.lib

all: $(PROG)

.SUFFIXES:		# delete the default suffixes
.SUFFIXES: .mac .rel

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

ldr.lib: $(OBJS)
	$(ZXCC) $(LBR) -"$@=main/e"

clean:
	rm -f $(OBJS) $(PROG) *.sym *.prn core *~ *.\$$\$$\$$
