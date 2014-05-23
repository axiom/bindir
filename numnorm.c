#include <stdio.h>
#include <stdlib.h>

// Normalize numbers on command line
int main(int argc, char **argv) {
	if (argc < 2) {
		return 0;
	}

	float sum = 0;
	float biggest = atof(argv[1]);
	for (int i = 1; i < argc; i++) {
		int value = atof(argv[i]);

		sum += value;
		if (value > biggest) {
			biggest = value;
		}
	}

	float divider = sum;
	if (argv[0] == "numnormbig") {
		divider = biggest;
	}


	for (int i = 1; i < argc; i++) {
		printf("%f ", atof(argv[i]) / divider);
	}

	printf("\n");

	return 0;
}
