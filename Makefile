CFLAGS=-std=c99 -Wpedantic

%: %.d
	dmd $@

all: stderr stdout bigger graph i numnorm numsum randarg unixtime
