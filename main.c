#include <stdio.h>
#include "input.h"
#include "output.h"
#include "compress.h"

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	if (argc <= 1) {
		printf("You must specify at least one file to be compressed.");
		return 1;
	}

	unsigned char buffer[BUFFER_SIZE];

	argv++;
	int i;
	for (i = 1; i < argc; i++) {
		char *filePath = *argv;
		FILE *in = fopen(filePath, "rb");
		
		
		while (readInput(in, buffer, BUFFER_SIZE) != EOF) {
			
		}

		argv++;
	}

	return 0;
}
