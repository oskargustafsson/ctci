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

int get_n_ways(int amount, const vector<int>& denoms, int index) {
	if (index == denoms.size() - 1) {
		return 1;
	}
	int denom_amount = denoms[index];
	int ways = 0;
	for (int i = 0; i <= amount; i += denom_amount) {
		int remaining_amount = amount - i;
		ways += get_n_ways(remaining_amount, denoms, index + 1);
	}
	return ways;
}

int get_n_ways_dyn(int max_amount, const vector<int>& denoms) {
	const int n_denoms = denoms.size() + 1;
	const int n_amounts = max_amount + 1;
	int table[n_denoms][n_amounts];

	for (int i = 0; i < n_denoms; i++) {
		for (int j = 0; j < n_amounts; j++) {
			table[i][j] = 0;
		}
	}

	for (int i = 1; i <= denoms.size(); i++) {
		table[i][0] = 1;
	}

	for (int denom_idx = 1; denom_idx <= denoms.size(); denom_idx++) {
		for (int amount = 1; amount <= max_amount; amount++) {
			int without_denom = table[denom_idx - 1][amount];
			int denom = denoms[denom_idx - 1];
			int with_denom = amount >= denom ? table[denom_idx][amount - denom] : 0;
			if (without_denom > 1000 || with_denom > 1000) {
				int i = 0;
			}
			table[denom_idx][amount] = without_denom + with_denom;
		}
	}

	return table[denoms.size()][max_amount];
}

int main(int argc, char** argv) {
	const vector<int> coin_values = { 25, 10, 5, 1 };
	const vector<int> coin_values_rev = { 1, 5, 10, 25 };
	for (int i = 1; i <= 25; i++) {
		printf("Ways to represent %i cents: %i\n", i, get_n_ways(i, coin_values, 0));
		printf("Ways to represent %i cents: %i\n\n", i, get_n_ways_dyn(i, coin_values_rev));
	}
}
