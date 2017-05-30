#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>
#include <random>

using namespace std;

default_random_engine generator;

struct node {
	node(int val) : val(val) {}

	void insert_in_order(int val) {
		node** child = val < this->val ? &left : &right;
		if (*child == nullptr) {
			*child = new node(val);
		} else {
			(*child)->insert_in_order(val);
		}
		size++;
	}

	node* get_random() {
		//uniform_int_distribution<int> distribution(0, size - 1);
		//int val = generator(distribution);
		int val = rand() % size;
		if (val == size - 1) {
			return this;
		}
		int left_size = left ? left->size : 0;
		node* child = val < left_size ? left : right;
		return child->get_random();
	}

	int val;
	node* left;
	node* right;
	int size = 1;
};

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
	node* root = new node(3);
	root->insert_in_order(1);
	root->insert_in_order(5);
	root->insert_in_order(4);
	root->insert_in_order(2);
	root->insert_in_order(6);
	print_tree(root);

	for (int i = 0; i < 100; i++) {
		printf("%i ", root->get_random()->val);
	}
	printf("\n");
}
