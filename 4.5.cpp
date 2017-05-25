#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>

struct node {
	node(int val) : val(val) {}
	int val;
	node* left;
	node* right;
};

node* make_bst(int* list, int length) {
	if (length < 1) {
		return nullptr;
	}

	const int middle = length / 2;
	node* n = new node(list[middle]);
	n->left = make_bst(list, middle);
	n->right = make_bst(list + middle + 1, length - (middle + 1));

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

bool is_bst_inner(node* node, int min, int max) {
	if (node == nullptr) {
		return true;
	}

	if (node->val <= min || max < node->val) {
		return false;
	}

	return is_bst_inner(node->left, min, node->val) && is_bst_inner(node->right, node->val, max);
}

bool is_bst(node* node) {
	return is_bst_inner(node, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int main(int argc, char** argv) {
	int sorted_list[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	node* root = make_bst(sorted_list, 9);

	// Make into non-bst
	root->right->left->left->val = 20;

	print_tree(root);

	printf("Is BST? %i\n", is_bst(root));
}
