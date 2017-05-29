#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <set>

using namespace std;

struct node {
	node(char val) : val(val) {}
	char val;
	vector<node*> dependers;
	int n_dependencies = 0;
};

using nodes = vector<node*>;
using node_pair = pair<node*, node*>;
using node_pairs = vector<node_pair>;

vector<node*> get_build_order(nodes& nodes, node_pairs& dep_pairs) {
	vector<node*> ordered_nodes;

	set<node*> without_deps;
	for (node* node : nodes) {
		without_deps.insert(node);
	}

	set<node*> with_deps;
	for (node_pair& node_pair : dep_pairs) {
		node_pair.first->dependers.push_back(node_pair.second);
		node_pair.second->n_dependencies++;
		with_deps.insert(node_pair.second);
		without_deps.erase(node_pair.second);
	}

	while (!without_deps.empty()) {
		node* dependency = *without_deps.begin();
		ordered_nodes.push_back(dependency);
		without_deps.erase(dependency);
		for (node* depender : dependency->dependers) {
			depender->n_dependencies--;
			if (depender->n_dependencies == 0) {
				with_deps.erase(depender);
				without_deps.insert(depender);
			}
		}
	}

	if (!with_deps.empty()) {
		throw "Cycle!";
	}

	return ordered_nodes;
}

int main(int argc, char** argv) {
	node a('a');
	node b('b');
	node c('c');
	node d('d');
	node e('e');
	node f('f');
	node g('g');

	nodes nodes = { &a, &b, &c, &d, &e, &f, &g, };

	node_pairs deps = {
		node_pair(&f, &c),
		node_pair(&f, &b),
		node_pair(&c, &a),
		node_pair(&b, &a),
		node_pair(&b, &e),
		node_pair(&a, &e),
		node_pair(&d, &g),
	};

	for (node* a_node : get_build_order(nodes, deps)) {
		printf("%c ", a_node->val);
	}
	printf("\n");
}
