#include <stdio.h>
#include <stdlib.h>
#include <initializer_list>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>
#include <map>
#include <iostream>
#include <array>
#include <set>

using namespace std;

int get_intermediate(int from, int to) {
	return 3 - (from + to);
}

void print_stacks(const array<stack<int>, 3>& stacks) {
	for (const auto& a_stack : stacks) {
		for (int i = 0; i < a_stack.size(); i++) {
			cout << "|";
		}
		cout << endl;
	}
	cout << endl;
}

void move_disks(array<stack<int>, 3>& stacks, int count, int from, int to) {
	if (count == 1) {
		int val = stacks[from].top();
		stacks[from].pop();
		stacks[to].push(val);
		return;
	}

	int intermediate = get_intermediate(from, to);
	move_disks(stacks, count - 1, from, intermediate);
	move_disks(stacks, 1, from, to);
	move_disks(stacks, count - 1, intermediate, to);
}

int main(int argc, char** argv) {
	array<stack<int>, 3> stacks;
	stacks[0].push(4);
	stacks[0].push(3);
	stacks[0].push(2);
	stacks[0].push(1);
	move_disks(stacks, 4, 0, 2);
	print_stacks(stacks);
}
