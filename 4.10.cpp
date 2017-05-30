#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>

using namespace std;

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

string get_preorder_str(node* current) {
	return current ? to_string(current->val) + get_preorder_str(current->left) + get_preorder_str(current->right) : "-";
}

bool is_subtree(node* small_root, node* big_root) {
	string small_str = get_preorder_str(small_root);
	string big_str = get_preorder_str(big_root);
	return big_str.find(small_str) != string::npos;
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
	int big_sorted_list[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	node* big_root = make_bst(big_sorted_list, sizeof big_sorted_list / sizeof *big_sorted_list);
	print_tree(big_root);

	{
		printf("\n\n");
		int small_sorted_list[] = { 5, 6, 7 };
		node* small_root = make_bst(small_sorted_list, sizeof small_sorted_list / sizeof *small_sorted_list);
		print_tree(small_root);
		printf("Is subtree: %i\n", is_subtree(small_root, big_root));
	}

	{
		printf("\n\n");
		int small_sorted_list[] = { 0, 1, 2, 3 };
		node* small_root = make_bst(small_sorted_list, sizeof small_sorted_list / sizeof *small_sorted_list);
		print_tree(small_root);
		printf("Is subtree: %i\n", is_subtree(small_root, big_root));
	}
}
