# Path to Linux utilities
ZXCC = zxcc

# Path to CP/M utilities
ZSM4 = ../Tools/cpm/zsm4.com
LBR  = ../Tools/cpm/lbr.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = devdy.mac \
	devdu.mac \
	devtt.mac \
	devnl.mac \
	devlp.mac \
	devco.mac \
	devct.mac \
	pseudo.mac

OBJS = $(SRCS:.mac=.rel)

all: drivers.lib

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

drivers.lib: $(OBJS)
	$(ZXCC) $(LBR) -"$@=devdy,devdu,devtt,devlp,devct,devco,devnl,pseudo"

list: drivers.lib
	$(ZXCC) $(LBR) -",tty:/li=drivers.lib"

clean:
	rm -f *.rel *.lib *.prn *.sym core *~ *.\$$\$$\$$
