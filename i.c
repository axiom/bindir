#include <stdio.h>
#include <ctype.h>

void process_str(char *);
void print_integer(int);

int
main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		process_str(argv[i]);
	}

	if (1 < argc) return 0;

	char buffer[255];
	while (fgets(buffer, sizeof(buffer), stdin))
	{
		process_str(buffer);
	}

	return 0;
}


void
process_str(char *str)
{
	int integer    = 0;
	char character = 0;

	if (1 == sscanf(str, "%i", &integer))
		print_integer(integer);
	else
	{
		int k = 0;
		while (1 == sscanf(str + k, "%c", &character))
		{
			print_integer((int) character);
			k++;
		}
	}
}


void
print_integer(int i)
{
	printf("0x%02x 0%03o %3d", i, i, i);

	if (isprint(i))
		printf(" %c", (char) i);

	printf("\n");
}
