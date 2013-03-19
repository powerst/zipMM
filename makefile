all:
	gcc -o zipmm main.c compress.c io.c avl_tree.c
clean:
	rm -f zipmm
