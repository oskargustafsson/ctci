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

using namespace std;

int* get_magic_unique(int* numbers, int start, int end) {
	if (start == end) {
		return nullptr;
	}

	int middle = (end + start) / 2;
	int middle_val = numbers[middle];

	if (middle == middle_val) {
		return numbers + middle;
	} else if (middle < middle_val) {
		return get_magic_unique(numbers, start, middle);
	} else {
		return get_magic_unique(numbers, middle + 1, end);
	}

	return nullptr;
}

int* get_magic(int* numbers, int start, int end) {
	if (end <= start) {
		return nullptr;
	}

	int middle = (end + start) / 2;
	int middle_val = numbers[middle];

	if (middle == middle_val) {
		return numbers + middle;
	}

	if (int* left_val = get_magic(numbers, start, min(middle, middle_val))) {
		return left_val;
	}

	return get_magic(numbers, max(middle + 1, middle_val), end);
}

int main(int argc, char** argv) {
	{
		int numbers[] = { -1, 1, 3, 5, 6, 10, 32, 34, 35, 36, 37, 38 };
		int n_numbers = sizeof(numbers) / sizeof(*numbers);
		int* magic = get_magic_unique(numbers, 0, n_numbers);
		printf("Magic pos/val (unique vals): %i\n", magic ? *magic : -1);
	}

	{
		int numbers[] = { -100, -30, -2, -1, -1, 1, 7, 8, 8, 32, 34, 35, 36, 37, 38 };
		int n_numbers = sizeof(numbers) / sizeof(*numbers);
		int* magic = get_magic(numbers, 0, n_numbers);
		printf("Magic pos/val: %i\n", magic ? *magic : -1);
	}
}
