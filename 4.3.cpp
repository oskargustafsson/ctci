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

void make_depth_lists(node* node, int depth, std::vector<std::list<int>>& lists) {
	if (node == nullptr) {
		return;
	}

	if (lists.size() == depth) {
		lists.push_back(std::list<int>());
	}

	std::list<int>& list = lists[depth];
	list.push_back(node->val);

	make_depth_lists(node->left, depth + 1, lists);
	make_depth_lists(node->right, depth + 1, lists);
}

void print_lists(std::vector<std::list<int>>& lists) {
	int depth = 0;
	for (std::list<int> list : lists) {
		printf("Depth %i:", depth);
		for (int val : list) {
			printf(" %i", val);
		}
		printf("\n");
		depth++;
	}
}

int main(int argc, char** argv) {
	int sorted_list[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	node* root = make_bst(sorted_list, 9);
	print_tree(root);

	std::vector<std::list<int>> lists;
	make_depth_lists(root, 0, lists);
	print_lists(lists);
}
