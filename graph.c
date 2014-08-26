#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int width = atoi(argv[1]) - 25;
	double max = atof(argv[2]);

	double current = 0;

	char *buf = malloc(1024);

	while (fgets(buf, 1024, stdin) != NULL) {
		current = atof(buf);
		for (int c = 0; c < width * (current / max); c++) {
			printf("━");
		}
		printf(" %10.10f\n", current);
		fflush(stdout);
	}
	free(buf);
	return 0;
}
