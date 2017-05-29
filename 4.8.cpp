#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>

struct node {
	node(int val) : val(val) {}
	int val;
	node* left;
	node* right;
	node* parent;
};

node* make_bst(int* list, int length, node* parent = nullptr) {
	if (length < 1) {
		return nullptr;
	}

	const int middle = length / 2;
	node* n = new node(list[middle]);
	n->parent = parent;
	n->left = make_bst(list, middle, n);
	n->right = make_bst(list + middle + 1, length - (middle + 1), n);

	return n;
}

void print_tree(node* node, const int depth = 0) {
	if (node == nullptr) {
		return;
	}

	int indents = 3 * depth;
	char spaces[indents + 1] = { '\0' };
	for (int i = 0; i < indents; i++) {
		spaces[i] = ' ';
	}

	print_tree(node->left, depth + 1);
	printf("%s%i\n", spaces, node->val);
	print_tree(node->right, depth + 1);
}

int get_depth(node* n) {
	int depth = 0;
	while (n = n->parent) {
		depth++;
	}
	return depth;
}

node* get_common_ancestor(node* n0, node* n1) {
	int n0depth = get_depth(n0);
	int n1depth = get_depth(n1);

	node** node_to_advance = n0depth > n1depth ? &n0 : &n1;
	for (int i = 0; i < std::abs(n0depth - n1depth); i++) {
		*node_to_advance = (*node_to_advance)->parent;
	}

	while (n0 != n1) {
		n0 = n0->parent;
		n1 = n1->parent;
	}

	return n0;
}

int main(int argc, char** argv) {
	int sorted_list[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	node* root = make_bst(sorted_list, 15);
	print_tree(root);

	printf(
		"%i %i -> %i\n",
		root->left->left->left->val,
		root->left->right->val,
		get_common_ancestor(
			root->left->left->left,
			root->left->right)->val);

	printf(
		"%i %i -> %i\n",
		root->left->val,
		root->right->right->right->val,
		get_common_ancestor(
			root->left,
			root->right->right->right)->val);
}
