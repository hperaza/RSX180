# Path to Linux utilities
ZXCC    = zxcc
VOL180  = ../Tools/linux/vol180/vol180
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = main.mac \
	mem.mac \
	atd.mac \
	tskhdr.mac \
	command.mac \
	misc.mac \
	help.mac \
	date.mac \
	disk.mac \
	uptime.mac \
	pool.mac \
	vbuf.mac

OBJS = $(SRCS:.mac=.rel)

BIN = rmd.bin

PROG = rmd.tsk

all: $(PROG)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"="$</l

$(BIN): $(OBJS) syslib.lib
	$(ZXCC) $(DRLINK) $@=main,date,uptime,atd,mem,tskhdr,disk,pool,help,command,misc,vbuf,syslib.lib[s]

$(PROG): $(BIN)
	$(MKTASK) $< -o $@ -name "...RMD" -id "V6.03" -pri 225 -priv

copy: $(PROG)
	@echo "cd system" > cprmd.cmd
	@echo "delete rmd.tsk" >> cprmd.cmd
	@echo "import rmd.tsk rmd.tsk /c" >> cprmd.cmd
	@echo "dir" >> cprmd.cmd
	@echo "bye" >> cprmd.cmd
	$(VOL180) /dev/fd0 < cprmd.cmd
	@rm cprmd.cmd

clean:
	rm -f *.rel *.prn *.sym core *.bin $(PROG) *~ *.\$$\$$\$$
