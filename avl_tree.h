#ifndef AVL_TREE_H
#define AVL_TREE_H

struct avl_tree;

//comparator for entries in the avl_tree
typedef int(*avl_cmp)(void*,void*);
//function to free an entry in the avl_tree
typedef void(*avl_cleanup)(void*);

//get a new avl tree with the specified comparator and entry cleaner
struct avl_tree* avl_init(avl_cmp e_cmp, avl_cleanup e_free);
//put a entry in the avl tree
void avl_put(struct avl_tree* t, void* e);
//remove an entry in the avl tree that compares to entry e
void avl_remove(struct avl_tree* t, void* e);
//find an entry in the avl tree that compares to entry e
void* avl_find(struct avl_tree* t, void* e);
//free the whole avl tree
void avl_free(struct avl_tree* t);

#endif
