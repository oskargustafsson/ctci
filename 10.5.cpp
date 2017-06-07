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

int find_closest_value_idx(const vector<string>& values, int pos) {
	cout << endl;
	for (int i = 1; i <= values.size(); i++) {
		int new_pos = pos + (i * (1 - 2 * (i & 1)) / 2);
		cout << new_pos << endl;
		if (0 <= new_pos && new_pos < values.size() && values[new_pos] != "") {
			return new_pos;
		}
	}
	pos = -1;
}

int find_nonempty_value_idx(const vector<string>& values, int pos, int dir) {
	while (0 <= pos && pos < values.size() && values[pos] == "") {
		pos += dir;
	}
	return pos;
}

/*int sparse_binary_search(const string& value, const vector<string>& values) {
	int begin = 0;
	int end = values.size();
	while (begin < end) {
		int mid = (begin + end) / 2;
		int new_mid = find_nonempty_value_idx(values, mid, 1);
		if (new_mid == values.size()) {
			new_mid = find_nonempty_value_idx(values, mid, -1);
		}
		if (new_mid == -1) {
			return new_mid;
		}
		const string& mid_value = values[new_mid];
		if (mid_value == value) {
			return mid;
		} else if (value < mid_value) {
			end = find_nonempty_value_idx(values, mid, -1);
		} else {
			begin = mid + 1;
		}
	}
	return -1;
}*/

int sparse_binary_search(const string& value, const vector<string>& values) {
	int begin = 0;
	int end = values.size();
	int dir = 1;
	while (begin < end) {
		int mid = (begin + end) / 2;
		int new_mid = find_nonempty_value_idx(values, mid, dir);
		if (new_mid == -1 || new_mid == values.size()) {
			dir *= -1;
			new_mid = find_nonempty_value_idx(values, mid, dir);
		}
		const string& mid_value = values[new_mid];
		if (mid_value == value) {
			return new_mid;
		} else if (value < mid_value) {
			dir = -1;
			end = new_mid;
		} else {
			dir = 1;
			begin = new_mid + 1;
		}
	}
	return -1;
}

int main(int argc, char** argv) {
	vector<string> strings = { "", "at", "", "", "", "ball", "", "", "", "", "car", "", "", "", "", "dad", "", "" };
	//vector<string> strings = { "at", "", "", "", "ball", "", "", "", "", "", "", "", "", "", "", "", "" };
	string needles[] = { "at", "ball", "car", "dad" };
	for (string& needle : needles) {
		printf("The position of %s is %i\n", needle.c_str(), sparse_binary_search(needle, strings));
	}
}
