#include <stdio.h>
#include <string.h>
#include "compress.h"

int main(int argc, char **argv)
{
	FILE* archive, *in, *out;
	int i;
	if (argc < 3) {
		printf("Usage: tarMM -r [infile]\ntarMM -w [outfile] [file file ...]\n");
		return 1;
	}
	else if(strcmp(argv[1], "-r") == 0) {
		archive = fopen(argv[2], "rb+");
		if(archive == NULL) {
			printf("Error opening archive: %s\n", argv[2]);
			return 1;
		}
		else {
			while(!feof(archive)) {
				out = decompress(archive);
				if(out != NULL)
					fclose(out);
			}
			fclose(archive);
		}
	}
	else if(strcmp(argv[1], "-w") == 0) {
		archive = fopen(argv[2], "wb+");
		if(archive == NULL) {
			printf("Error opening archive: %s\n", argv[2]);
			return 1;
		}
		else {
			for (i = 3; i < argc; i++) {
				in = fopen(argv[i], "rb+");
				if (in == NULL) {
					printf("Error opening file: %s\n", argv[i]);
				}
				else {
					compress(archive, in, argv[i]);
					fclose(in);
				}
			}
			fclose(archive);
		}
	}
	else {
		printf("Unrecognized mode...\n");
		return 2;
	}
	return 0;
}
