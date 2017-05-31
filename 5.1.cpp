#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>
#include <map>
#include <bitset>
#include <iostream>

using namespace std;

template<typename T>
void print_bits(T val) {
	bitset<8 * sizeof(T)> bits(val);
	cout << bits << endl;
}

int set_bits(int n, int m, int i, int j) {
	int n_bits_to_clear = j - i;
	int mask = (1 << n_bits_to_clear) - 1;
	mask <<= i;
	n &= ~mask;
	n |= m << i;
	return n;
}

int main(int argc, char** argv) {
	int m = 0b1010;
	int n = 0xf0f0f0f0;
	print_bits(m);
	print_bits(n);
	print_bits(set_bits(n, m, 6, 10));
}
