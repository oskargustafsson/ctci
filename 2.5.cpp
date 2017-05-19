#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

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

// Least significant first
node* add(node* current0, node* current1) {
	node* sum_head = new node;
	node* sum_tail = sum_head;
	int carry = 0;
	while (current0 || current1) {
		int current_sum =
			carry +
			(current0 ? current0->value : 0) +
			(current1 ? current1->value : 0);

		if (current0) {
			current0 = current0->next;
		}

		if (current1) {
			current1 = current1->next;
		}

		if (current_sum > 9) {
			carry = 1;
			current_sum -= 10;
		} else {
			carry = 0;
		}

		sum_tail->next = new node(current_sum);
		sum_tail = sum_tail->next;
	}
	return sum_head->next;
}

node* reverse(node* current) {
	if (!current->next) {
		return current;
	}

	node* prev = current;
	current = current->next;
	prev->next = nullptr;

	while (current) {
		node* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

// Most significant first
node* add2(node* current0, node* current1) {
	node* current0_rev = reverse(current0);
	node* current1_rev = reverse(current1);
	node* sum_rev = add(current0_rev, current1_rev);
	return reverse(sum_rev);
}

int main(int argc, char** argv) {
	node* head0 = new node;
	node* head1 = new node;
	node* current0 = head0;
	node* current1 = head1;
	for (int i = 0; i < 9; i++) {
		{
			node* new_node = new node;
			new_node->value = (i + 1) % 5;
			current0->next = new_node;
			current0 = new_node;
		}
		if (i < 5) {
			node* new_node = new node;
			new_node->value = (i + 5) % 10;
			current1->next = new_node;
			current1 = new_node;
		}
	}
	print_list(head0);
	print_list(head1);

	{
		node* sum_list = add(head0, head1);
		print_list(sum_list);
	}

	{
		node* sum_list = add2(head0, head1);
		print_list(sum_list);
	}
}
