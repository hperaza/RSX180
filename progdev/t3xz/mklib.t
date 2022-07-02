! Merge library image into the T3X/Z compiler source code.
! Nils M Holm, 2019
! Public domain / CC0

module mklib(t3x);

object	t[t3x];

const	BUFLEN = 128;

var	Outbuf::BUFLEN;

str_length(s) return t.memscan(s, 0, 32767);

writes(fd, s) do
	t.write(fd, s, str_length(s));
end

nl(fd) do var b::3;
	writes(fd, t.newline(b));
end

aw(s) do
	writes(T3X.SYSERR, s);
	nl(T3X.SYSERR);
end

wrnib(fd, n) do var c::1;
	ie (n > 9)
		c::0 := n+'a'-10;
	else
		c::0 := n+'0';
	t.write(fd, c, 1);
end

wrbyte(fd, n) do
	wrnib(fd, n>>4);
	wrnib(fd, n&15);
end

copylib(lfd, tfd) do var k, i, j, n, len;
	len := 32767;
	writes(tfd, "\t[ ");
	k := t.read(lfd, Outbuf, BUFLEN);
	if (k > 4) len := Outbuf::3 + (Outbuf::4 << 8);
	j := 0;
	while (k > 0) do
		if (j + k > len) k := len - j;
		writes(tfd, "0x");
		wrbyte(tfd, k >> 8);
		wrbyte(tfd, k & 255);
		writes(tfd, ",");
		nl(tfd);
		writes(tfd, "\t  packed [ ");
		nl(tfd);
		writes(tfd, "\t    ");
		n := 0;
		for (i=0, k) do
			n := n+1;
			j := j+1;
			ie (n > 12) do
				nl(tfd);
				writes(tfd, "\t    0x");
				n := 1;
			end
			else do
				writes(tfd, "0x");
			end
			wrbyte(tfd, Outbuf::i);
			if (i < k-1) writes(tfd, ",");
		end
		writes(tfd, " ],");
		nl(tfd);
		writes(tfd, "\t  ");
		if (j >= len) leave;
		k := t.read(lfd, Outbuf, BUFLEN);
	end
	writes(tfd, "0 ];");
	nl(tfd);
end

var	Inbuf::BUFLEN;
var	Line, Linebuf::BUFLEN;
var	Cp, Ep, More;

readln(fd) do var i, c;
	i := 0;
	while (1) do
		if (Cp >= Ep) do
			Ep := t.read(fd, Inbuf, BUFLEN);
			if (Ep < 1) do
				More := 0;
				leave;
			end
			Cp := 0;
		end
		c := Inbuf::Cp;
		Cp := Cp+1;
		if (c = '\r') loop;
		if (c = '\n') leave;
		if (i >= BUFLEN-1) leave;
		Line::i := c;
		i := i+1;
	end
	Line::i := 0;
	return i;
end

writeln(fd) do
	writes(fd, Line);
	nl(fd);
end

do var sfd, lfd, tfd, k;
	sfd := t.open("t.src", T3X.OREAD);
	if (sfd < 0) aw("mklib: 't.src' file missing");
	lfd := t.open("lib.bin", T3X.OREAD);
	if (lfd < 0) aw("mklib: 'lib.bin' file missing");
	tfd := t.open("t.t", T3X.OWRITE);
	if (tfd < 0) aw("mklib: cannot create 't.t' file");
	Line := "!! DO NOT EDIT THIS FILE, EDIT T.SRC INSTEAD !!";
	writeln(tfd);
	Line := "";
	writeln(tfd);
	Line := Linebuf;
	Cp := 0;
	Ep := 0;
	More := %1;
	k := readln(sfd);
	while (More) do
		if (	k >= 10 /\
			t.memcomp(Line, "\t!LIBRARY!", 10) = 0)
		do
			writeln(tfd);
			copylib(lfd, tfd);
		end
		writeln(tfd);
		k := readln(sfd);
	end
	t.close(tfd);
	t.close(sfd);
	t.close(lfd);
end
