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

void merge_sorted(int* a, int a_len, int* b, int b_len) {
	int a_pos = a_len - 1;
	int b_pos = b_len - 1;
	int end_pos = a_len + b_len - 1;

	while (b_pos >= 0) {
		if (a_pos >= 0 && a[a_pos] > b[b_pos]) {
			a[end_pos--] = a[a_pos];
			a_pos--;
		} else {
			a[end_pos--] = b[b_pos];
			b_pos--;
		}
	}
}

int main(int argc, char** argv) {
	int a[] = { 0, 2, 4, 8, 16, 32, 100, 1000, 10001, 0, 0, 0, 0, 0, 0, 0 };
	int a_len = sizeof(a) / sizeof(*a);

	int b[] = { 1, 3, 7, 8, 16, 70, 81 };
	int b_len = sizeof(b) / sizeof(*b);

	a_len -= b_len; // account for extra space at the end of a

	merge_sorted(a, a_len, b, b_len);

	for (int a_val : a) {
		cout << a_val << " ";
	}
	cout << endl;
}
