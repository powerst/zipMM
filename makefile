all:
	gcc -o tarmm main.c compress.c
clean:
	rm -f tarmm
