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

int binary_search(int value, const int* values, int begin, int end) {
	while (begin < end) {
		int mid = (begin + end) / 2;
		int mid_value = values[mid];
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
	int values[] = { 0, 2, 4, 8, 16, 32, 100, 1000, 10001 };
	int n_values = sizeof(values) / sizeof(*values);
	for (int value : values) {
		printf("%i is at index %i\n", value, binary_search(value, values, 0, n_values));
	}
	printf("%i is at index %i\n", 123, binary_search(123, values, 0, n_values));
}
