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

node* delete_middle_node(node* current) {
	current->value = current->next->value;
	current->next = current->next->next;
}

int main(int argc, char** argv) {
	node* head = new node;
	node* current = head;
	node* a_middle_node = nullptr;
	for (int i = 0; i < 9; i++) {
		node* new_node = new node;
		new_node->value = (i + 1) % 5;
		current->next = new_node;
		current = new_node;
		if (i == 3) {
			a_middle_node = current;
		}
	}
	print_list(head);
	delete_middle_node(a_middle_node);
	print_list(head);
}
