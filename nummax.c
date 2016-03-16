#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double current = 0;
	double max = 0;
	int numbers = -1;

	while ((numbers = scanf("%la", &current)) == 1) {
		if (current > max) {
			max = current;
		}
	}

	if (numbers == 0) {
		fprintf(stderr, "End of input?\n");
		return 1;
	}

	if (errno != 0) {
		printf("Got error: %i\n", errno);
		return 1;
	}

	printf("%10.10f\n", max);
	return 0;
}
