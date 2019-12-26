# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = hello.mac \
	ckp.mac \
	cmdprint.mac \
	dmpres.mac \
	sendtest.mac \
	recvtest.mac \
	test.mac \
	test1.mac \
	test2.mac \
	bintest.mac \
	iitest.mac \
	fcstest.mac \
	bcdtest.mac \
	filernd.mac \
	exttest.mac \
	block0.mac \
	gcmltest.mac \
	rnetest.mac \
	exstat.mac \
	ds1820.mac \
	tecken.mac \
	qtest.mac

OBJS = $(SRCS:.mac=.rel)
BINS = $(SRCS:.mac=.bin)
TSKS = $(SRCS:.mac=.tsk)

all: $(TSKS)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BINS): %.bin: %.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,syslib.lib[s]"

fcstest.bin: fcstest.rel syslib.lib fcslib.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,fcslib.lib[s],syslib.lib[s]"

bcdtest.bin: bcdtest.rel syslib.lib bcdflt.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,bcdflt.lib[s],syslib.lib[s]"

$(TSKS): %.tsk: %.bin
	$(MKTASK) $< -o $@

snake.tsk: snake.plm
	$(MKTASK) snake.com -o snake.tsk -inc 5000

block0.tsk: block0.bin
	$(MKTASK) $< -o $@ -priv

dmpres.tsk: dmpres.bin
	$(MKTASK) $< -o $@ -priv

exstat.tsk: exstat.bin
	$(MKTASK) $< -o $@

ckp.tsk: ckp.bin
	$(MKTASK) $< -o $@ -priv -name "...CKP"

clean:
	rm -f *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$
