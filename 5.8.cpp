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
void print_bits(T val, bool add_newline = false) {
	bitset<8 * sizeof(T)> bits(*reinterpret_cast<unsigned long*>(&val));
	cout << bits;
	if (add_newline) {
		cout << endl;
	}
}

void draw_line(char* bytes, int width, int x0, int x1, int y) {
	int bytes_width = width / 8;
	int offset = y * bytes_width + x0 / 8;
	int n_bits_to_set = x1 - x0;

	int leading_bits_to_set = min(8 - (x0 % 8), n_bits_to_set);
	bytes[offset] = (1 << leading_bits_to_set) - 1;

	n_bits_to_set -= leading_bits_to_set;

	if (n_bits_to_set == 0) {
		bytes[offset] << 8 - (x0 % 8) - (x0 - x1);
	}

	offset++;

	while (n_bits_to_set > 0) {
		bytes[offset++] = n_bits_to_set > 7 ? 0b11111111 : (((1 << n_bits_to_set) - 1) << (8 - n_bits_to_set));
		n_bits_to_set -= 8;
	}
}

int main(int argc, char** argv) {
	constexpr int screen_width = 32;
	constexpr int screen_height = 32;
	constexpr int n_screen_bytes = screen_width * screen_height / 8;
	char bytes[n_screen_bytes] = { 0 };
	draw_line(bytes, screen_width, 3, 27, 3);
	for (int i = 0; i < n_screen_bytes; i++) {
		print_bits(bytes[i], ((i + 1) % 4) == 0);
	}
}
