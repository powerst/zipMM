#include <stdio.h>
#include "input.h"
#include "output.h"
#include "compress.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	if (argc <= 1) {
		printf("You must specify at least one file to be compressed.\n");
		return 1;
	}

	unsigned char buffer[BUFFER_SIZE];

	int i;
	for (i = 1; i < argc; i++) {
		char *filePath = *(argv+i);
		FILE *in = fopen(filePath, "rb");
		if (in == NULL) {
			printf("Error opening file: %s\n", filePath);
			continue;
		}
		
		// read input, compress, write output

		fclose(in);
	}

	return 0;
}
