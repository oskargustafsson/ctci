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

void add_all(vector<string>& a, vector<string>&& b, char prefix) {
	for (string& str : b) {
		a.push_back(prefix + str);
	}
}

vector<string> get_parentheses(int n_opening_remaining, int n_closing_remaining, int n_opened) {
	vector<string> parentheses;

	if (n_opening_remaining + n_closing_remaining == 0) {
		parentheses.push_back("");
		return parentheses;
	}

	if (n_opening_remaining > 0) {
		add_all(parentheses, get_parentheses(n_opening_remaining - 1, n_closing_remaining, n_opened + 1), '(');
	}

	if (n_closing_remaining > 0 && n_opened > 0) {
		add_all(parentheses, get_parentheses(n_opening_remaining, n_closing_remaining - 1, n_opened - 1), ')');
	}

	return parentheses;
}

vector<string> get_all_paretheses_combos(int n) {
	return get_parentheses(n, n, 0);
}

int main(int argc, char** argv) {
	for (int i = 0; i < 6; i++) {
		cout << i << endl;
		for (const string& str : get_all_paretheses_combos(i)) {
			cout << str << endl;
		}
	}
}
