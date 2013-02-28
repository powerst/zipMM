#ifndef IO_H
#define IO_H
#include <stdio.h>
long readLong(FILE* in);
void writeLong(long in, FILE* out);
int readInt(FILE* out);
void writeInt(int in, FILE* out);
#endif
