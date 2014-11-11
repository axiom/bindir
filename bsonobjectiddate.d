import std.stdio;
import std.string;
import std.conv;
import std.datetime;

SysTime toTime(string objectId) {
	immutable datepart = objectId[0 .. 8].to!ulong(16);
	return SysTime(unixTimeToStdTime(datepart));
}

void prettyDate(const SysTime date) {
	writeln(date.toISOExtString());
}

string toObjectId(const SysTime time) {
	return format("%x", time.toUnixTime()) ~ "0000000000000000";
}

void fromArgs(string[] args) {
	foreach (objectId; args[1 .. $]) {
		prettyDate(toTime(objectId));
	}
}

void fromStdin() {
	while (!stdin.eof()) {
		immutable line = chomp(readln());

		if (line == "") {
			continue;
		}

		prettyDate(toTime(line));
	}
}

void main(string[] args) {
	// If any arguments were given try to parse them as objectids.
	// Otherwise we try to get object ids from stdin.
	if (args.length > 1) {
		fromArgs(args);
	} else {
		fromStdin();
	}
}

unittest {
	immutable now = Clock.currTime();
	immutable objectId = "5460edbd0000000000000000";

	assert(toObjectId(toTime(objectId)) == objectId);
}
