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

int get_different_bits_count(uint a, uint b) {
	int n_different = 0;
	for (uint i = a ^ b; i; i &= i - 1) {
		n_different++;
	}
	return n_different;
}

int main(int argc, char** argv) {
	uint a = 123;
	print_bits(a);
	uint b = 321;
	print_bits(b);
	printf("Number of different bits: %i\n", get_different_bits_count(a, b));
}
