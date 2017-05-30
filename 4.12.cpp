#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>
#include <map>

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

int count_subpaths(node* current, int target_sum, int running_sum, map<int, int>& path_counts) {
	if (current == nullptr) {
		return 0;
	}

	running_sum += current->val;
	int diff = running_sum - target_sum;
	int count = path_counts[diff];

	if (running_sum == target_sum) {
		count++;
	}

	path_counts[running_sum]++;
	count += count_subpaths(current->left, target_sum, running_sum, path_counts);
	count += count_subpaths(current->right, target_sum, running_sum, path_counts);
	path_counts[running_sum]--;

	return count;
}

int count_subpaths(node* root, int target_sum) {
	map<int, int> path_counts;
	return count_subpaths(root, target_sum, 0, path_counts);
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
	int sorted_list[] = { 1, -5, 2, -6, -8, 3, -1, 8, -4, 7 }; // Not sorted -> pseudorandom tree
	node* root = make_bst(sorted_list, sizeof sorted_list / sizeof *sorted_list);
	print_tree(root);

	for (int i = 0; i < 10; i++) {
		printf("Subpaths with sum %i: %i\n", i, count_subpaths(root, i));
	}
}
