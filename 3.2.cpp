#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

template<typename T>
class stack {
public:
	void push(const T& value) {
		item& new_item = items[top];
		new_item.value = value;
		new_item.substack_min = top == 0 || value < min() ? value : min();
		top++;
	}
	T pop() {
		return items[--top].value;
	}
	T peek() {
		return items[top - 1].value;
	}
	T min() {
		return items[top - 1].substack_min;
	}
	bool is_empty() {
		return top == 0;
	}
private:
	struct item {
		T value;
		T substack_min;
	};
	int top = 0;
	item items[100];
};

int main(int argc, char** argv) {
	stack<int> s;
	s.push(4);
	s.push(2);
	s.push(3);
	s.push(1);
	while (!s.is_empty()) {
		printf("min: %i\n", s.min());
		s.pop();
	}
}
