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

uint swap_bit_pairs(uint a) {
	const uint mask = 0b01010101010101010101010101010101;
	return ((a & mask) << 1) | ((a & (~mask)) >> 1);
}

int main(int argc, char** argv) {
	uint a = 123456789;
	print_bits(a);
	print_bits(swap_bit_pairs(a));
}
