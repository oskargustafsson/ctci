#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>

using namespace std;
using int_list = list<int>;
using list_vector = vector<int_list*>;

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

template<typename T>
void push_back_all(T* dest, T* source) {
	for (auto val : *source) {
		dest->push_back(val);
	}
}

void weave_lists(int_list* first, int_list* second, list_vector* results, int_list* prefix) {
	if (first->empty() || second->empty()) {
		auto result = new int_list(*prefix);
		push_back_all(result, first);
		push_back_all(result, second);
		results->push_back(result);
		return;
	}

	auto head_first = first->front();
	first->pop_front();
	prefix->push_back(head_first);
	weave_lists(first, second, results, prefix);
	prefix->pop_back();
	first->push_front(head_first);

	auto head_second = second->front();
	second->pop_front();
	prefix->push_back(head_second);
	weave_lists(second, second, results, prefix);
	prefix->pop_back();
	second->push_front(head_second);
}

list_vector* get_all_sequences(node* current) {
	auto result = new list_vector;

	if (current == nullptr) {
		result->push_back(new int_list);
		return result;
	}

	auto prefix = new int_list;
	prefix->push_back(current->val);

	auto left_seq = get_all_sequences(current->left);
	auto right_seq = get_all_sequences(current->right);

	for (auto left : *left_seq) {
		for (auto right : *right_seq) {
			auto weaved = new list_vector;
			weave_lists(left, right, weaved, prefix);
			push_back_all(result, weaved);
		}
	}

	return result;
}

int main(int argc, char** argv) {
	int sorted_list[] = { 0, 1, 2, 3, 4, 5, 6 };
	node* root = make_bst(sorted_list, 7);
	print_tree(root);

	// TODO: debug this, it's not producing correct results
	for (auto seq : *get_all_sequences(root)) {
		for (auto val : *seq) {
			printf("%i ", val);
		}
		printf("\n");
	}
}
