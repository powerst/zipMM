#ifndef AVL_TREE_H
#define AVL_TREE_H

struct avl_tree;

typedef int(*avl_cmp)(void*,void*);
typedef void(*avl_e_free)(void*);

struct avl_tree* avl_init(avl_cmp e_cmp, avl_e_free e_free);
void avl_add(struct avl_tree* t, void* e);
int avl_remove(struct avl_tree* t, void* e);
void* avl_find(struct avl_tree* t, void* e);
void avl_free(struct avl_tree* t);

#endif
