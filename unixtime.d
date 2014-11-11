import std.stdio;
import std.datetime;
import std.conv;

/*
 * Print current unix time stamp, or convert command line arguments from unix
 * time stamp into human readable time.
 */
int main(string[] args) {
	// Handle the simple case first.
	if (args.length <= 1) {
		writeln(Clock.currTime().toUnixTime);
		return 0;
	}

	try {
		foreach (input; args[1 .. $]) {
			immutable unixTime = parse!long(input);
			immutable t = SysTime(unixTimeToStdTime(unixTime));
			writeln(t.toISOExtString());
		}
	} catch (std.conv.ConvException exc) {
		stderr.writeln("Could not parse input as unix time stamp.");
		stderr.writeln("Exception: ", exc.msg);
		return 1;
	}

	return 0;
}
