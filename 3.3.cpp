#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

template<typename T, int max_stack_size>
class stack_of_stacks {
public:
	void push(const T& value) {
		std::stack<T>& top_stack = top == 0 || peek_stack()->size() == max_stack_size ? push_stack() : *peek_stack();
		top_stack.push(value);
	}
	void pop() {
		peek_nonempty_stack()->pop();
	}
	void popAt(int i) {
		peek_nonempty_stack(i)->pop();
	}
	T peek() {
		return peek_nonempty_stack()->top();
	}
	bool is_empty() {
		return peek_nonempty_stack() == nullptr;
	}
private:
	std::stack<T>& push_stack() {
		return stacks[top++] = std::stack<T>();
	}
	std::stack<T>* pop_stack() {
		if (top == 0) {
			return nullptr;
		}
		top--;
		return peek_stack();
	}
	std::stack<T>* peek_stack() {
		return top == 0 ? nullptr : stacks + (top - 1);
	}
	std::stack<T>* peek_nonempty_stack(int i = -1) {
		std::stack<T>* top_stack = i == -1 ? peek_stack() : stacks + i;
		while (top_stack && top_stack->empty()) {
			top_stack = i == -1 ? pop_stack() : stacks + (--i);
		}
		return top_stack;
	}
	int top = 0;
	std::stack<T> stacks[100];
};


int main(int argc, char** argv) {
	stack_of_stacks<int, 3> sos;
	for (int i = 0; i < 9; i++) {
		sos.push(i);
	}

	sos.popAt(1);
	sos.popAt(1);
	sos.popAt(1);
	sos.popAt(1);

	while (!sos.is_empty()) {
		printf("%i\n", sos.peek());
		sos.pop();
	}
}
