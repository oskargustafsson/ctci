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
	bitset<8 * sizeof(T)> bits(*reinterpret_cast<unsigned long*>(&val));
	cout << bits << endl;
}

void print_next_biggest_smallest(int n) {
	int n_ones = 0;
	for (int i = 0; i < 32; i++) {
		n_ones += n & 1;
		n >>= 1;
	}
	printf("Ones: %i\n", n_ones);

	int biggest = ((1 << n_ones) - 1) << (31 - n_ones);
	printf("Biggest: %i\n", biggest);
	print_bits(biggest);

	int smallest = (1 << 31) | ((1 << (n_ones - 1)) - 1);
	printf("Smallest: %i\n", smallest);
	print_bits(smallest);
}

int main(int argc, char** argv) {
	// Note: misinterpreted the question, so this solves a different problem than what the book meant
	print_next_biggest_smallest(0b11011011);
}
