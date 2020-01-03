# Path to Linux utilities
ZXCC = zxcc

# Path to CP/M utilities
ZSM4 = ../Tools/cpm/zsm4.com
TKB  = ../Tools/cpm/tkb.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = cal.mac \
	clock.mac \
	cookie.mac \
	dmp.mac \
	md5.mac \
	murphy.mac \
	quote.mac \
	view.mac

OBJS = $(SRCS:.mac=.rel)
PROGS = $(OBJS:.rel=.tsk)

all: $(PROGS)

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$</l"

$(PROGS): %.tsk: %.rel syslib.lib fcslib.lib
	$(ZXCC) $(TKB) -"$@=$</ofmt=tsk,fcslib/lb,syslib/lb"

cal.tsk: cal.rel
	$(ZXCC) $(TKB) -"$@=$</ofmt=tsk/task=...CAL"

clock.tsk: clock.rel fcslib.lib
	$(ZXCC) $(TKB) -"$@=$</ofmt=tsk,syslib/lb/task=...CLK"

dmp.tsk: dmp.rel fcslib.lib syslib.lib
	$(ZXCC) $(TKB) -"$@=$</ofmt=tsk,fcslib/lb,syslib/lb/task=...DMP"

md5.tsk: md5.rel fcslib.lib syslib.lib
	$(ZXCC) $(TKB) -"$@=$</ofmt=tsk,fcslib/lb,syslib/lb/task=...MD5"

view.tsk: view.rel syslib.lib
	$(ZXCC) $(TKB) -"$@=$</ofmt=tsk,syslib/lb/ext=10000/task=...VIE"

clean:
	rm -f *.rel *.prn *.sym core *.map *.tsk *~ *.\$$\$$\$$
