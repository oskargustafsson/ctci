#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
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

set<set<int>> get_all_subsets(const set<int>& a_set) {
	set<set<int>> sets;
	sets.insert(a_set);

	for (int i : a_set) {
		set<int> a_set_copy(a_set);
		a_set_copy.erase(i);
		for (const set<int>& subset : get_all_subsets(a_set_copy)) {
			sets.insert(subset);
		}
	}

	return sets;
}

int main(int argc, char** argv) {
	set<int> a_set = { 0, 1, 2, 3 };
	auto all_subsets = get_all_subsets(a_set);
	for (const set<int>& s : all_subsets) {
		cout << "{ ";
		for (int i : s) {
			cout << i << " ";
		}
		cout << "}" << endl;
	}
}
