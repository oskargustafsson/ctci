#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct node {
	int value = 0;
	node* next = nullptr;
};

void print_list(node* current) {
	while (current) {
		printf("%i ", current->value);
		current = current->next;
	}
	printf("\n");
}

node* get_nth_last(node* current, int nth_last) {
	if (!current) {
		return nullptr;
	}

	int list_length = 0;
	node* runner = current;

	while (runner = runner->next) {
		list_length++;
	}

	runner = current;
	for (int i = list_length - nth_last - 1; i >= 0; i--) {
		runner = runner->next;
	}

	return runner;
}

int main(int argc, char** argv) {
	node* head = new node;
	node* current = head;
	for (int i = 0; i < 9; i++) {
		node* new_node = new node;
		new_node->value = (i + 1) % 5;
		current->next = new_node;
		current = new_node;
	}
	print_list(head);
	for (int i = 0; i < 10; i++) {
		printf("%i\n", get_nth_last(head, i)->value);
	}
}
