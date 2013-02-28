all:
	gcc -o tarmm main.c compress.c io.c avl_tree.c
clean:
	rm -f tarmm
