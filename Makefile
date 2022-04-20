# st - simple terminal
# See LICENSE file for copyright and license details.

all:
	meson build
	meson compile -C build

clean:

dist: clean

install: all

uninstall:

.PHONY: all options clean dist install uninstall
