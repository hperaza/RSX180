# Path to Linux utilities
ZXCC    = zxcc
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = acnt.mac \
	bye.mac \
	cot.mac \
	dmo.mac \
	hel.mac \
	ini.mac \
	ins.mac \
	mcr.mac \
	mou.mac \
	shutup.mac \
	sys.mac \
	tkn.mac \
	ufd.mac

LIBSRCS = fdboot.mac \
	hdboot.mac \
	ttputch.mac

LIBOBJS = $(LIBSRCS:.mac=.rel)

OBJS = $(SRCS:.mac=.rel)

BINS = $(OBJS:.rel=.bin)

PROGS = $(BINS:.bin=.tsk)

all: $(PROGS)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(LIBOBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(BINS): %.bin: %.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,syslib.lib[s]"

acnt.tsk: acnt.bin
	$(MKTASK) $< -o $@ -name "ACNT" -id "01.00" -inc 512 -priv

bye.tsk: bye.bin
	$(MKTASK) $< -o $@ -name "...BYE" -id "01.00" -pri 50 -priv

cot.bin: cot.rel syslib.lib fcslib.lib
	$(ZXCC) $(DRLINK) -"$@[nr]=$<,fcslib.lib[s],syslib.lib[s]"

cot.tsk: cot.bin
	$(MKTASK) $< -o $@ -name "COT..." -id "1.0" -pri 150 -priv

dmo.tsk: dmo.bin
	$(MKTASK) $< -o $@ -name "...DMO" -id "01.02" -pri 160 -priv

hel.tsk: hel.bin
	$(MKTASK) $< -o $@ -name "...HEL" -id "03.01" -pri 50 -priv

ini.bin: ini.rel fdboot.rel hdboot.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@=ini,fdboot,hdboot,syslib.lib[s]"

ini.tsk: ini.bin
	$(MKTASK) $< -o $@ -name "...INI" -id "01.01" -pri 60 -priv

ins.bin: ins.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@=ins,syslib.lib[s]"

ins.tsk: ins.bin
	$(MKTASK) $< -o $@ -name "...INS" -id "01.00" -pri 100 -priv

mcr.bin: mcr.rel ttputch.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@=mcr,ttputch,syslib.lib[s]"

mcr.tsk: mcr.bin
	$(MKTASK) $< -o $@ -name "MCR..." -id "02.10" -pri 160 -priv

mou.tsk: mou.bin
	$(MKTASK) $< -o $@ -name "...MOU" -id "01.02" -pri 160 -priv

shutup.tsk: shutup.bin
	$(MKTASK) $< -o $@ -name "SHUTUP" -id "01.02" -pri 100 -priv

sys.tsk: sys.bin
	$(MKTASK) $< -o $@ -name "...MCR" -id "02.10" -pri 160 -priv

tkn.bin: tkn.rel ttputch.rel syslib.lib
	$(ZXCC) $(DRLINK) -"$@=tkn,ttputch,syslib.lib[s]"

tkn.tsk: tkn.bin
	$(MKTASK) $< -o $@ -name "TKTN" -id "02.01" -pri 250 -priv

ufd.tsk: ufd.bin
	$(MKTASK) $< -o $@ -name "...UFD" -id "01.00" -pri 100 -priv

#$(PROGS): %.tsk: %.bin
#	$(MKTASK) $< -o $@

clean:
	rm -f $(PROG) *.rel *.prn *.sym core *.bin *.tsk *~ *.\$$\$$\$$
