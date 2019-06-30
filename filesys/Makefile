# Path to Linux utilities
ZXCC = zxcc
MKT  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4 = ../Tools/cpm/zsm4.com
LINK = ../Tools/cpm/drlink.com

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

PROG = sysfcp.tsk

all: $(PROG)

.SUFFIXES:		# delete the default suffixes
.SUFFIXES: .mac .rel

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

sysfcp.tsk: $(OBJS)
	$(ZXCC) $(LINK) -"sysfcp.bin=main,fileio,mount,indexf,bitmap,buffer,blockio"
	$(MKT) sysfcp.bin -o $@ -name SYSFCP -par FCPPAR -id V4.1 -pri 200 -priv
	

clean:
	rm -f $(OBJS) $(PROG) sysfcp.bin *.sym *.prn core *~ *.\$$\$$\$$
