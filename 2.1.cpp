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

void remove_duplicates(node* current) {
	while (current) {
		node* runner = current;
		while (runner->next) {
			if (runner->next->value == current->value) {
				runner->next = runner->next->next;
			} else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

int main(int argc, char** argv) {
	node* head = new node;
	node* current = head;
	for (int i = 0; i < 10; i++) {
		node* new_node = new node;
		new_node->value = (i + 1) % 5;
		current->next = new_node;
		current = new_node;
	}
	print_list(head);
	remove_duplicates(head);
	print_list(head);
}
