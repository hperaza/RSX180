# Path to Linux utilities
ZXCC = zxcc

# Path to CP/M utilities
ZSM4 = ../Tools/cpm/zsm4.com
LBR  = ../Tools/cpm/lbr.com

SRCS = args.mac \
	ast.mac \
	clkq.mac \
	connect.mac \
	device.mac \
	flags.mac \
	fork.mac \
	ints.mac \
	kalloc.mac \
	pars.mac \
	mmu.mac \
	qio.mac \
	qmcr.mac \
	qldr.mac \
	qtktn.mac \
	session.mac \
	sndrcv.mac \
	syscom.mac \
	sysdat.mac \
	sysfn.mac \
	tskmgr.mac \
	p112.mac \
	startup.mac

INC = tcb.inc \
	z180.inc

OBJS = $(SRCS:.mac=.rel)

PROG = kernel.lib

all: startup.rel sysdat.rel $(PROG)

.SUFFIXES:		# delete the default suffixes
.SUFFIXES: .mac .rel

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

# Note: startup.rel and sysdat.rel are not included (will be linked first
# and last, respectively.)
kernel.lib: $(OBJS)
	$(ZXCC) $(LBR) -"$@=tskmgr,flags,sndrcv,device,session,connect,ints"
	@cp $@ src.lib
	$(ZXCC) $(LBR) -"$@=src.lib,kalloc,mmu,syscom,qio,qldr,qmcr,qtktn,ast"
	@cp $@ src.lib
	$(ZXCC) $(LBR) -"$@=src.lib,fork,pars,clkq,sysfn,args,p112"
	@rm src.lib

clean:
	rm -f $(OBJS) $(PROG) *.sym *.prn core *~ *.\$$\$$\$$
