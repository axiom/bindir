import std.stdio;
import std.datetime;
import std.conv;

/*
 * Print current unix time stamp, or convert command line arguments from unix
 * time stamp into human readable time.
 */
void main(string[] args) {
	// Handle the simple case first.
	if (args.length <= 1) {
		writeln(Clock.currTime().toUnixTime);
		return;
	}

	foreach (input; args[1 .. $]) {
		immutable unixTime = parse!long(input);
		immutable t = SysTime(unixTimeToStdTime(unixTime));

		writeln(t.toISOExtString());
	}
}
