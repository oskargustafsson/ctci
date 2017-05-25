#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>

struct node {
	enum class state { UNVISITED, VISITED };
	node(char value) : val(val) {}
	char val;
	state state = state::UNVISITED;
	std::vector<node*> adjacent;
};

bool is_connected(node* n0, node* n1) {
	std::queue<node*> queue;
	queue.push(n0);
	while (!queue.empty()) {
		node* n = queue.front();
		queue.pop();
		if (n == n1) {
			return true;
		}
		if (n->state == node::state::VISITED) {
			continue;
		}
		n->state = node::state::VISITED;
		for (node* node : n->adjacent) {
			queue.push(node);
		}
	}
	return false;
}

void reset_nodes(std::vector<node*>& nodes) {
	for (node* node : nodes) {
		node->state = node::state::UNVISITED;
	}
}

int main(int argc, char** argv) {
	auto a = new node('a');
	auto b = new node('b');
	auto c = new node('c');
	auto d = new node('d');
	auto e = new node('e');
	auto f = new node('f');

	std::vector<node*> nodes = { a, b, c, d, e, f };

	a->adjacent.push_back(b);
	a->adjacent.push_back(c);

	b->adjacent.push_back(d);
	b->adjacent.push_back(f);

	//c->adjacent.push_back(e);

	e->adjacent.push_back(d);
	e->adjacent.push_back(f);

	printf("%i\n", is_connected(a, f));
	reset_nodes(nodes);
	printf("%i\n", is_connected(a, e));
}
