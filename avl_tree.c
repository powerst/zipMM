#include "avl_tree.h"
#include <stdlib.h>

struct node {
	struct node* parent;
	struct node* left;
	struct node* right;
	void* e;
};

struct avl_tree {
	struct node* root;
	avl_cmp e_cmp;
	avl_e_free e_free;
};

static void rotLeft(struct avl_tree* t, struct node* n) {

}

static void rotRight(struct avl_tree* t, struct node* n) {

}

static void addRepair(struct avl_tree* t, struct node* n) {

}

static void add(struct avl_tree* t, struct node* cur, struct node* n) {

}


static void removeRepair(struct avl_tree* t, struct node* n) {

}

static void remove(struct avl_tree* t, struct node* n) {

}

static void* find(struct avl_tree* t, struct node* n, void* e) {
	int cmp_res;
	if(n != NULL) {
		cmp_res = t->e_cmp(e, n->e);
		if(cmp_res < 0)
			return find(t, n->left, e);
		else if(cmp_res == 0)
			return n->e;
		else
			return find(t, n->right, e);
	}
	else 
		return NULL;
}

struct node* node_init(struct node* parent, void* e) {
	struct node* ret = (struct node*)malloc(sizeof(struct node));
	ret->parent = parent;
	ret->e = e;
}
static void node_free(struct avl_tree* t, struct node* n) {
	if(n != NULL) {
		node_free(t, n->left);
		node_free(t, n->right);
		t->e_free(n->e);
		free(n);
	}
}

struct avl_tree* avl_init(avl_cmp e_cmp, avl_e_free e_free) {
	struct avl_tree* t = (struct avl_tree*)malloc(sizeof(struct avl_tree));
	t->e_cmp = e_cmp;
	t->e_free = e_free;
	t->root = NULL;
	return t;
}

void avl_add(struct avl_tree* t, void* e) {
	if(t->root == NULL)
		t->root = node_init(NULL, e);
	else
		add(t, t->root, e);
}

int avl_remove(struct avl_tree* t, void* e) {
	struct node* n = find(t, t->root, e);
	if(n != NULL) {
		remove(t, n);
		return 1;
	}
	else
		return 0;
}

void* avl_find(struct avl_tree* t, void* e) {
	return find(t, t->root, e);
}

void avl_free(struct avl_tree* t) {
	node_free(t, t->root);
	free(t);
}
