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

node* partition(node* current, int val) {
	node* lt = nullptr;
	node* gte = nullptr;
	while (current) {
		node* next = current->next;
		node** list_head = current->value < val ? &lt : &gte;
		current->next = *list_head;
		(*list_head) = current;
		current = next;
	}
	if (!lt) {
		return gte;
	}
	node* head = lt;
	while (lt->next) {
		lt = lt->next;
	}
	lt->next = gte;
	return head;
}

// Alt solution: store head, filter out gte into new list, add that list at the end of the filtered list

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
	node* new_list = partition(head, 2);
	print_list(new_list);
}
