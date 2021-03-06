#include "compress.h"
#include "io.h"
#include <string.h>
#include <stdlib.h>


void compress(FILE* out, FILE* in, const char * name) {
	char buffer[CHUNK_SIZE];
	int count;
	//writing the header
	//1: Size of file name (2 bytes)
	writeInt(strlen(name), out);
	//2: File name
	fwrite(name, 1, strlen(name), out);
	//TODO: Actually compress the file
	//3: Size of file content (4 bytes)
	fseek(in, 0, SEEK_END);
	writeLong(ftell(in), out);
	fseek(in, 0, SEEK_SET);
	//4: File Content
	while(!feof(in)) {
		count = fread(buffer, 1, CHUNK_SIZE, in);
		fwrite(buffer, 1, count, out);
	}
}

void decompress(FILE* in) {
	char buffer[CHUNK_SIZE], *fileName;
	int count, nameSz;
	long contentSz;
	FILE* out;
	while(!feof(in)) {
		//reading the header
		//1: Size of file name (2 bytes)
		nameSz = readInt(in);
		if(feof(in)) {
			return;
		}
		//2: File name
		fileName = (char*)malloc(nameSz);
		fread(fileName, 1, nameSz, in);
		out = fopen(fileName, "wb+");
		if(out == NULL) {
			printf("Decompression Error: Could not create file %s\n", fileName);
			return;
		}
		free(fileName);
		//TODO: Actually decompress the file
		//3: Size of file content (4 bytes)
		contentSz = readLong(in);
		//4: Actual content
		while(contentSz > 0) {
			count = fread(buffer, 1, contentSz, in);
			fwrite(buffer, 1, count, out);
			contentSz -= count;
		}
		fclose(out);
	}
}
