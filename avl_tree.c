#include "avl_tree.h"
#include <stdlib.h>

/*
Actual avl tree struct. Holds the root of the tree,
and the function pointers we need for comparison
and freeing of entries
*/
struct avl_tree {
	struct node* root;
	avl_cmp e_cmp;
	avl_cleanup e_free;
};

/*
Avl tree node
*/
struct node {
	struct node* parent;
	struct node* left;
	struct node* right;
	void* e;
};

/*
Init a node with entry e and parent parent
*/
struct node* node_init(struct node* parent, void* e) {
	struct node* ret = (struct node*)malloc(sizeof(struct node));
	ret->parent = parent;
	ret->e = e;
}

/*
Free a node n in avl_tree t 
*/
static void node_free(struct avl_tree* t, struct node* n) {
	if(n != NULL) {
		t->e_free(n->e);
		free(n);
	}
}

/*
Free a node n in avl_tree t without freeing the entry
returns the entry
*/
static void* node_free_noe(struct avl_tree* t, struct node* n) {
	void* olde = NULL;
	if(n != NULL) {
		olde = n->e;
		free(n);
	}
	return olde;
}

/*
Free a subtree with root node f in avl_tree t
*/
static void subtree_free(struct avl_tree* t, struct node* r) {
	if(r != NULL) {
		t->e_free(r->e);
		subtree_free(t, r->left);
		subtree_free(t, r->right);
		free(r);
	}
}

//compare two nodes in avl_tree t - follows <0,0,>0 comparator semantics
static int node_cmp(struct avl_tree* t, struct node* a, struct node* b) {
	return t->e_cmp(a->e, b->e);
}

/*
Rotate the subtree with root node n left.
This function must take into account n possibly
being the root of the tree
*/
static void rotLeft(struct avl_tree* t, struct node* n) {

}

/*
Rotate the subtree with root node n right
This function must take into account n possibly
being the root of the tree
*/
static void rotRight(struct avl_tree* t, struct node* n) {

}

//Find the height of a subtree with root node n
static int height(struct node* n) {
	if(n == NULL)
		return 0;
	else
		return height(n->left) + height(n->right);
}

/*
Get the balance factor of a subtree with root node n
height(left) - height(right)
Anything <-1 or >1 is unbalanced
*/
static int balance_factor(struct node* n) {
	return height(n->left) - height(n->right);
}

/*
Repair the AVL tree after an insertion. Use rotations
to re-balance the tree
*/
static void putRepair(struct avl_tree* t, struct node* n) {

}

/*
Put node n to the binary tree. put n just as if this is a regular 
binary search tree (cur is the node we are currently comparing to),
then call addRepair to restore AVL properties if necessary

Returns the old node if there is one, null otherwise - dont
free the old node!
Note - add never has to deal with t->root being null (and 
hence cur never being null if there are no bugs) as this case 
is covered in avl_add
*/
struct node* put(struct avl_tree* t, struct node* cur, struct node* n) {

}

/*
Repair the AVL tree after removal. Use rotations to re-balance
the tree
*/
static void removeRepair(struct avl_tree* t, struct node* n) {

}

/*
Remove node n from the tree (use n->parent) and do a basic
fix on the tree. Call removeRepair to restore AVL properties
don't free n!
*/
static void remove(struct avl_tree* t, struct node* n) {

}

/*
Find entry e in the avl_tree t, cur being the current
node we are looking at. return NULL if it does not exist
Read-only operation - no AVL repair needed
*/
static void* find(struct avl_tree* t, struct node* cur, void* e) {
	int cmp_res;
	if(cur != NULL) {
		cmp_res = t->e_cmp(e, cur->e);
		if(cmp_res < 0)
			return find(t, cur->left, e);
		else if(cmp_res == 0)
			return cur->e;
		else
			return find(t, cur->right, e);
	}
	else 
		return NULL;
}

/*
init an avl_tree with comparator e_cmp and entry freer e_free
*/
struct avl_tree* avl_init(avl_cmp e_cmp, avl_cleanup e_free) {
	struct avl_tree* t = (struct avl_tree*)malloc(sizeof(struct avl_tree));
	t->e_cmp = e_cmp;
	t->e_free = e_free;
	t->root = NULL;
	return t;
}

/*
put entry e in the avl_tree, returning the old entry if there is one
*/
void* avl_put(struct avl_tree* t, void* e) {
	struct node* old;
	if(t->root == NULL) {
		t->root = node_init(NULL, e);
		return NULL;
	}
	else {
		old = put(t, t->root, node_init(NULL, e));
		if(old != NULL)
			return node_free_noe(t, old);
		else
			return NULL;
	}
}

/*
remove node with entry from the avl tree if it exists
returns the old entry if it existed, or null otherwise 
*/
void* avl_remove(struct avl_tree* t, void* e) {
	struct node* n = find(t, t->root, e);
	if(n != NULL) {
		remove(t, n);
		return node_free_noe(t, n);
	}
	else
		return NULL;
}

/*
get the entry of the node that compares to entry e in avl_tree t if it exists
*/
void* avl_find(struct avl_tree* t, void* e) {
	struct node* n = find(t, t->root, e);
	if(n != NULL)
		return n->e;
	else
		return NULL;
}

/*
	free an avl_tree
*/
void avl_free(struct avl_tree* t) {
	subtree_free(t, t->root);
	free(t);
}
