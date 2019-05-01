# Path to Linux utilities
ZXCC = zxcc

# Path to CP/M utilities
ZSM4 = ../Tools/cpm/zsm4.com
LBR  = ../Tools/cpm/lbr.com

SRCS = bitmap.mac \
	buffer.mac \
	blockio.mac \
	mount.mac \
	fileio.mac \
	indexf.mac \
	main.mac

INC = tcb.inc \
	dcb.inc \
	fcb.inc \
	vcb.inc \
	sysfn.inc \
	errors.inc \
	z180.inc

OBJS = $(SRCS:.mac=.rel)

PROG = sysfcp.lib

all: $(PROG)

.SUFFIXES:		# delete the default suffixes
.SUFFIXES: .mac .rel

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

sysfcp.lib: $(OBJS)
	$(ZXCC) $(LBR) -"$@=main/e+fileio/e+mount/e+indexf/e+bitmap/e+buffer/e+blockio/e"

clean:
	rm -f $(OBJS) $(PROG) *.sym *.prn core *~ *.\$$\$$\$$
