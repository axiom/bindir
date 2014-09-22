#include <stdio.h>

int main(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		fprintf(stdout, "%s", argv[i]);

		if (i + 1 < argc) {
			fprintf(stdout, " ");
		}
	}
	fprintf(stdout, "\n");
	return 0;
}
