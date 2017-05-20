#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

template<typename T>
class queue {
	enum state { STACK, QUEUE };
public:
	void enqueue(const T& t) {
		if (my_state != state::STACK) {
			toggle_state();
		}
		my_stack.push(t);
	}
	T dequeue() {
		if (my_state != state::QUEUE) {
			toggle_state();
		}
		const T value = my_queue.top();
		my_queue.pop();
		return value;
	}
	bool is_empty() {
		return my_stack.empty() && my_queue.empty();
	}
private:
	void toggle_state() {
		bool is_stack = my_state == state::STACK;
		std::stack<T>& to_fill = is_stack ? my_queue : my_stack;
		std::stack<T>& to_drain = is_stack ? my_stack : my_queue;
		while (!to_drain.empty()) {
			to_fill.push(to_drain.top());
			to_drain.pop();
		}
		my_state = is_stack ? state::QUEUE : state::STACK;
	}
	state my_state = state::STACK;
	std::stack<T> my_stack;
	std::stack<T> my_queue;
};


int main(int argc, char** argv) {
	queue<int> a_queue;

	a_queue.enqueue(0);
	a_queue.enqueue(1);
	a_queue.dequeue();
	a_queue.enqueue(2);
	a_queue.enqueue(3);

	while (!a_queue.is_empty()) {
		printf("%i\n", a_queue.dequeue());
	}
}
