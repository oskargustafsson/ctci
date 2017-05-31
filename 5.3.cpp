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

int get_longest_streak(uint n) {
	int longest_streak = 0;
	int current_streak = 0;
	bool used_one = false;
	for (int i = 0; i < 32; i++) {
		if (n & 1) {
			current_streak++;
		} else if (!used_one) {
			current_streak++;
			used_one = true;
		} else {
			current_streak = 0;
			used_one = false;
		}
		if (current_streak > longest_streak) {
			longest_streak = current_streak;
		}
		n >>= 1;
	}
	return longest_streak;
}

int main(int argc, char** argv) {
	{
		uint n = 0b10011011111011111010110111101111;
		print_bits(n);
		printf("Longest streak: %i\n", get_longest_streak(n));
	}

	{
		uint n = 0b10011011111001111010110111101111;
		print_bits(n);
		printf("Longest streak: %i\n", get_longest_streak(n));
	}
}
