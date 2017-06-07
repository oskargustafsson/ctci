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

int find_rotation_offset(const int* values, int begin, int end) {
	while (end - begin > 1) {
		int mid = (begin + end) / 2;
		if (values[begin] > values[mid]) {
			end = mid;
		} else {
			begin = mid;
		}
	}
	return end;
}

int binary_search_rotated(int value, const int* values, int begin, int end) {
	int n_values = end;
	int offset = find_rotation_offset(values, begin, end);
	while (begin < end) {
		int mid = (begin + end) / 2;
		int mid_value = values[(mid + offset) % n_values];
		if (mid_value == value) {
			return (mid + offset) % n_values;
		} else if (value < mid_value) {
			end = mid;
		} else {
			begin = mid + 1;
		}
	}
	return -1;
}

int main(int argc, char** argv) {
	//int values[] = { 8, 9, 12, 23, 45, 67, 98, 1, 3, 5 };
	int values[] = { 2, 2, 2, 2, 3, 4, 5, 2 };
	int n_values = sizeof(values) / sizeof(*values);
	for (int value : values) {
		printf("%i is at index %i\n", value, binary_search_rotated(value, values, 0, n_values));
	}
	printf("%i is at index %i\n", 123, binary_search_rotated(123, values, 0, n_values));
}
