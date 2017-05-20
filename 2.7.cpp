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
		//printf("%i -> %i\n", current->value, current->next ? current->next->value : -1);
		printf("%i ", current->value);
		current = current->next;
	}
	printf("\n");
}

node* get_intersection(node* current0, node* current1) {
	if (!(current0 && current1)) {
		return nullptr;
	}

	node* list0head = current0;
	int list0len = 1;
	while (current0->next) {
		list0len++;
		current0 = current0->next;
	}

	node* list1head = current1;
	int list1len = 1;
	while (current1->next) {
		list1len++;
		current1 = current1->next;
	}

	if (current0 != current1) {
		return nullptr; // Lists are not intersecting
	}

	int list_len_diff = list0len - list1len;
	node* short_list_head = list_len_diff < 0 ? list0head : list1head;
	node* long_list_head = list_len_diff < 0 ? list1head : list0head;

	for (int i = 0; i < abs(list_len_diff); i++) {
		long_list_head = long_list_head->next;
	}

	while (short_list_head != long_list_head) {
		long_list_head = long_list_head->next;
		short_list_head = short_list_head->next;
	}

	return short_list_head;
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

	node* head2 = new node;
	node* tail2 = head2;
	for (int i = 0;  i < 5; i++) {
		node* new_node = new node(i + 10);
		tail2->next = new_node;
		tail2 = new_node;
	}

	tail2->next = middle;

	print_list(head->next);
	print_list(head2->next);
	node* intersecting_node = get_intersection(head->next, head2->next);
	printf("%i\n", intersecting_node ? intersecting_node->value : -1);
}
