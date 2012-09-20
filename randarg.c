#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * Pick one command line argument at random.
 */
int
main(int argc, char **argv)
{
	// Make sure there are arguments to choose from.
	if (argc == 1) {
		fprintf(stderr, "Usage: %s arg1 [arg2 [...]]\n", argv[0]);
		return 1;
	}

	// Get time, including micro seconds.
	struct timeval current;
	if (gettimeofday(&current, NULL) == -1) {
		fprintf(stderr, "Could not get time.\n");
		return 1;
	}

	// Set a random seed.
	srand(current.tv_sec + current.tv_usec);
	int index = rand() % (argc - 1) + 1;

	// Randomize from command line arguments.
	fprintf(stdout, "%s", argv[index]);
	return 0;
}