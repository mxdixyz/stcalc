CC = gcc
PREFIX = /usr
MANPREFIX = $(PREFIX)/share/man


install:
	$(CC) -o stcalc stcalc.c
	cp -f stcalc $(PREFIX)/bin/
	cp -f stcalc.1 $(MANPREFIX)/man1/

uninstall:
	rm -f stcalc $(PREFIX)/bin/stcalc $(MANPREFIX)/man1/stcalc.1
