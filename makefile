all:
	gcc -o tarmm.exe main.c input.c output.c compress.c
clean:
	rm -f tarmm.exe
