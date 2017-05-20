#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

template <typename T>
std::stack<T> sort_stack(std::stack<T> stack) {
	std::stack<T> sorted_stack;
	while (!stack.empty()) {
		T value = stack.top();
		stack.pop();
		if (sorted_stack.empty() || value <= sorted_stack.top()) {
			sorted_stack.push(value);
		} else {
			while (!sorted_stack.empty()) {
				T sorted_stack_value = sorted_stack.top();
				if (value <= sorted_stack_value) {
					break;
				}
				sorted_stack.pop();
				stack.push(sorted_stack_value);
			}
			stack.push(value);
		}
	}
	return sorted_stack;
}


int main(int argc, char** argv) {
	std::stack<int> stack;

	stack.push(3);
	stack.push(2);
	stack.push(1);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(10);
	stack.push(14);
	stack.push(3);
	stack.push(7);

	std::stack<int> sorted_stack = sort_stack(stack);

	while (!sorted_stack.empty()) {
		printf("%i\n", sorted_stack.top());
		sorted_stack.pop();
	}
}
