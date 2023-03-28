# See LICENSE file for copyright and license details.
CC = gcc
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man


all:
	$(CC) -Wall -g -o stcalc stcalc.c

install: all
	mkdir -p "$(PREFIX)/bin"
	cp -f stcalc "$(PREFIX)/bin"
	chmod 755 "$(PREFIX)/bin/stcalc"
	mkdir -p "$(MANPREFIX)/man1"
	cp -f stcalc.1 "$(MANPREFIX)/man1"
	chmod 644 "$(MANPREFIX)/man1/stcalc.1"

uninstall:
	rm -f "$(PREFIX)/bin/stcalc"
	rm -f "$(MANPREFIX)/man1/stcalc.1"