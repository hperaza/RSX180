# Path to Linux utilities
ZXCC    = zxcc
VOL180  = ../Tools/linux/vol180/vol180
MKTASK  = ../Tools/linux/mktask/mktask

# Path to CP/M utilities
ZSM4    = ../Tools/cpm/zsm4.com
DRLINK  = ../Tools/cpm/drlink.com

.PREFIX:
.PREFIX: .mac .rel

SRCS = xonix.mac \
	snake.mac \
	pacman.mac \
	tetris.mac \
	volcano.mac \
	termdef.mac \
	cpmio.mac \
	rsxio.mac

OBJS = $(SRCS:.mac=.rel)
XRFS = $(SRCS:.mac=.crf)

all: xonix.com xonix.tsk \
	snake.com snake.tsk \
	pacman.com pacman.tsk \
	tetris.com tetris.tsk \
	volcano.com volcano.tsk

$(OBJS): %.rel: %.mac *.inc
	$(ZXCC) $(ZSM4) -"=$<"


xonix.com: xonix.rel termdef.rel cpmio.rel
	$(ZXCC) $(DRLINK) -"xonix=termdef,xonix,cpmio"

xonix.bin: xonix.rel termdef.rel rsxio.rel syslib.lib
	$(ZXCC) $(DRLINK) -"xonix.bin=termdef,xonix,rsxio,syslib.lib[s]"

xonix.tsk: xonix.bin
	$(MKTASK) $< -o $@ -name "...XON" -id "M580"


snake.com: snake.rel termdef.rel cpmio.rel
	$(ZXCC) $(DRLINK) -"snake=termdef,snake,cpmio"

snake.bin: snake.rel termdef.rel rsxio.rel syslib.lib
	$(ZXCC) $(DRLINK) -"snake.bin=termdef,snake,rsxio,syslib.lib[s]"

snake.tsk: snake.bin
	$(MKTASK) $< -o $@ -name "...SNA" -id "M580"


pacman.com: pacman.rel termdef.rel cpmio.rel
	$(ZXCC) $(DRLINK) -"pacman=termdef,pacman,cpmio"

pacman.bin: pacman.rel termdef.rel rsxio.rel syslib.lib
	$(ZXCC) $(DRLINK) -"pacman.bin=termdef,pacman,rsxio,syslib.lib[s]"

pacman.tsk: pacman.bin
	$(MKTASK) $< -o $@ -name "...PAC" -id "M580"


tetris.com: tetris.rel termdef.rel cpmio.rel
	$(ZXCC) $(DRLINK) -"tetris=termdef,tetris,cpmio"

tetris.bin: tetris.rel termdef.rel rsxio.rel syslib.lib
	$(ZXCC) $(DRLINK) -"tetris.bin=termdef,tetris,rsxio,syslib.lib[s]"

tetris.tsk: tetris.bin
	$(MKTASK) $< -o $@ -name "...TET" -id "M580"


volcano.com: volcano.rel termdef.rel cpmio.rel
	$(ZXCC) $(DRLINK) -"volcano=termdef,volcano,cpmio"

volcano.bin: volcano.rel termdef.rel rsxio.rel syslib.lib
	$(ZXCC) $(DRLINK) -"volcano.bin=termdef,volcano,rsxio,syslib.lib[s]"

volcano.tsk: volcano.bin
	$(MKTASK) $< -o $@ -name "...VOL" -id "M580"

cpcpm: xonix.com snake.com pacman.com tetris.com volcano.com
	cpmrm -f p112 /dev/fd0 0:xonix.com
	cpmrm -f p112 /dev/fd0 0:snake.com
	cpmrm -f p112 /dev/fd0 0:pacman.com
	cpmrm -f p112 /dev/fd0 0:tetris.com
	cpmrm -f p112 /dev/fd0 0:volcano.com
	cpmcp -f p112 /dev/fd0 xonix.com 0:
	cpmcp -f p112 /dev/fd0 snake.com 0:
	cpmcp -f p112 /dev/fd0 pacman.com 0:
	cpmcp -f p112 /dev/fd0 tetris.com 0:
	cpmcp -f p112 /dev/fd0 volcano.com 0:

cprsx: xonix.tsk snake.tsk pacman.tsk tetris.tsk volcano.tsk
	@echo "cd games" > copy.cmd
	@echo "delete xonix.tsk" >> copy.cmd
	@echo "delete snake.tsk" >> copy.cmd
	@echo "delete pacman.tsk" >> copy.cmd
	@echo "delete tetris.tsk" >> copy.cmd
	@echo "delete volcano.tsk" >> copy.cmd
	@echo "import xonix.tsk xonix.tsk /c" >> copy.cmd
	@echo "import snake.tsk snake.tsk /c" >> copy.cmd
	@echo "import pacman.tsk pacman.tsk /c" >> copy.cmd
	@echo "import tetris.tsk tetris.tsk /c" >> copy.cmd
	@echo "import volcano.tsk volcano.tsk /c" >> copy.cmd
	@echo "dir" >> copy.cmd
	@echo "bye" >> copy.cmd
	$(VOL180) /dev/fd0 < copy.cmd
	@rm copy.cmd

clean:
	rm -f *.com *.bin *.tsk *.rel *.sym *.prn *.crf core *~ *.\$$\$$\$$
