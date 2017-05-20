#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

struct node {
	node(int value = 0, node* next = nullptr) : value(value), next(next) {}
	int value;
	node* next;
};

void print_list(node* current) {
	while (current) {
		printf("%i ", current->value);
		current = current->next;
	}
	printf("\n");
}

node* get_loop_start(node* current) {
	node* head = current;
	node* slow = current;
	node* fast = current;

	if (!(current && current->next && current->next->next)) {
		return nullptr;
	}

	do {
		slow = slow->next;
		fast = fast->next->next;
	} while (fast != slow);

	while (head != slow) {
		slow = slow->next;
		head = head->next;
	}

	return head;
}

int main(int argc, char** argv) {
	node* head = new node;
	node* tail = head;
	node* middle;
	for (int i = 0; i < 11; i++) {
		node* new_node = new node(i + 1);
		tail->next = new_node;
		tail = new_node;
		if (i == 5) {
			middle = new_node;
		}
	}

	tail->next = middle;

	node* loop_start = get_loop_start(head->next);
	printf("%i\n", loop_start ? loop_start->value : -1);
}
