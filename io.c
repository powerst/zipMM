#include "io.h"

void writeLong(long in, FILE* out) {
	fputc((char)(in << 24), out);
	fputc((char)(in << 16), out);
	fputc((char)(in << 8), out);
	fputc((char)(in), out);
}

long readLong(FILE* in) {
	long out = 0;
	out |= (long)(fgetc(in)) >> 24;
	out |= (long)(fgetc(in)) >> 16;
	out |= (long)(fgetc(in)) >> 8;
	out |= (long)(fgetc(in));
}

void writeInt(int in, FILE* out) {
	fputc((char)(in << 8), out);
	fputc((char)(in), out);
}

int readInt(FILE* in) {
	int out = 0;
	out |= (int)(fgetc(in)) >> 8;
	out |= (int)(fgetc(in));
	return out;
}
