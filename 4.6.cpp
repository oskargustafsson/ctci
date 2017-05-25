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

node* get_successor(node* current) {
	if (current->right) {
		current = current->right;
		while (current->left) {
			current = current->left;
		}
		return current;
	}

	while (current->parent && current->parent->right == current) {
		current = current->parent;
	}
	current = current->parent;

	return current;
}

void print_successors(node* current) {
	if (current == nullptr) {
		return;
	}
	node* successor = get_successor(current);
	printf("Successor of %i is %i\n", current->val, successor ? successor->val : -1);
	print_successors(current->left);
	print_successors(current->right);
}

int main(int argc, char** argv) {
	int sorted_list[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	node* root = make_bst(sorted_list, 9);
	print_tree(root);
	print_successors(root);
}
