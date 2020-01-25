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
	$(ZXCC) $(LBR) -"$@=devdy/e+devdu/e+devtt/e+devlp/e+devct/e"
	@cp $@ src.lib
	$(ZXCC) $(LBR) -"$@=src.lib/e+devco/e+devnl/e+pseudo/e"
	@rm src.lib

list: drivers.lib
	$(ZXCC) $(LBR) -",tty:=drivers.lib"

clean:
	rm -f *.rel *.lib *.prn *.sym core *~ *.\$$\$$\$$
