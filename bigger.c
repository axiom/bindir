#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double limit = atof(argv[1]);
	double current = 0;

	char *buf = malloc(1024);

	while (fgets(buf, 1024, stdin) != NULL) {
		current = atof(buf);
		if (limit <= current) {
			printf("%10.10f\n", current);
		}
	}
	free(buf);
	return 0;
}
