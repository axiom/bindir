CFLAGS=-std=c99 -Wpedantic

%: %.d
	dmd -release $@

all: stderr stdout bigger graph i numnorm numsum randarg unixtime bsonobjectiddate
