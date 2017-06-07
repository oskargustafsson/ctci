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

struct Listy {
	int operator[](int idx) const {
		return idx < size ? values[idx] : -1;
	}
	int values[10] = { 1, 2, 5, 8, 9, 12, 23, 45, 67, 98 };
	int size = 10;
};

int find_size(const Listy& list) {
	if (list[0] == -1) { return 0; }
	int end = 1;
	while (list[end] != -1) {
		end *= 2;
	}
	int begin = end / 2;

	while (end - begin > 1) {
		int mid = (begin + end) / 2;
		if (list[mid] == -1) {
			end = mid;
		} else {
			begin = mid;
		}
	}
	return end;
}

int binary_search_nosize(int value, const Listy& list) {
	int begin = 0;
	int end = find_size(list);
	while (begin < end) {
		int mid = (begin + end) / 2;
		int mid_value = list[mid];
		if (mid_value == value) {
			return mid;
		} else if (value < mid_value) {
			end = mid;
		} else {
			begin = mid + 1;
		}
	}
	return -1;
}

int main(int argc, char** argv) {
	Listy list;
	for (int value : list.values) {
		printf("%i is at index %i\n", value, binary_search_nosize(value, list));
	}
	printf("%i is at index %i\n", 123, binary_search_nosize(123, list));
}
