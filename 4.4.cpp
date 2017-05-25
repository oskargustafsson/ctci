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

bool is_balanced(node* node, int& depth) {
	if (node == nullptr) {
		return true;
	}

	int l_depth = depth + 1;
	bool l_balanced = is_balanced(node->left, l_depth);

	int r_depth = depth + 1;
	bool r_balanced = is_balanced(node->right, r_depth);

	depth = std::max(l_depth, r_depth);

	return l_balanced && r_balanced && std::abs(l_depth - r_depth) < 2;
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

int main(int argc, char** argv) {
	int sorted_list[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	node* root = make_bst(sorted_list, 9);

	// Make imbalanced
	root->right->left->left->left = new node(100);

	print_tree(root);

	int depth = 0;
	printf("Balanced? %i\n", is_balanced(root, depth));
}
