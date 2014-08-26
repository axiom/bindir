#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *buf = malloc(1024);
	double current = 0;
	double max = 0;

	while (fgets(buf, 1024, stdin) != NULL) {
		current = atof(buf);
		if (current > max) {
			max = current;
		}
	}
	printf("%10.10f\n", max);
	free(buf);
	return 0;
}
