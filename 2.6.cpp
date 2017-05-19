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

node* copy(node* current) {
	node* new_current;
	node* new_prev;
	node* new_head;
	while (current) {
		new_current = new node(current->value);
		if (new_prev) {
			new_prev->next = new_current;
		} else {
			new_head = new_current;
		}
		new_prev = new_current;
		current = current->next;
	}
	return new_head;
}

bool equals(node* current0, node* current1) {
	while (current0 && current1) {
		if (current0->value != current1->value) {
			return false;
		}
		current0 = current0->next;
		current1 = current1->next;
	}
	return !(current0 || current1);
}

bool is_palindrome(node* current) {
	node* reversed_copy = reverse(copy(current));
	return equals(current, reversed_copy);
}

bool is_palindrome2(node* current) {
	node* fast = current;
	node* slow = current;
	std::stack<int> stack;

	while (fast && fast->next) {
		stack.push(slow->value);
		slow = slow->next;
		fast = fast->next->next;
	}

	// If the list is of odd length, discard the middle element
	if (fast) {
		slow = slow->next;
	}

	while (slow) {
		if (slow->value != stack.top()) {
			return false;
		}
		stack.pop();
		slow = slow->next;
	}

	return true;
}

int main(int argc, char** argv) {
	node* head = new node;
	node* tail = head;
	for (int i = 0; i < 11; i++) {
		node* new_node = new node;
		new_node->value = abs(5 - i);
		// new_node->value = i < 5 ? i : 9 - i; // For even size lists
		tail->next = new_node;
		tail = new_node;
	}
	print_list(head->next);
	printf("%i\n", is_palindrome(head->next));
	printf("%i\n", is_palindrome2(head->next));
}
