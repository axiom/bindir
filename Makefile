CFLAGS=-std=c99 -Wpedantic

%: %.d
	ldc2 -release $@

all: stderr stdout bigger graph i numnorm numsum randarg unixtime bsonobjectiddate
