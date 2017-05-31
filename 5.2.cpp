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

void print_as_binary(double num) {
	string num_str = "0.";
	double t = 0.5;
	while (num != 0.0) {
		if (num_str.size() > 32) {
			cout << "ERROR" << endl;
			return;
		}
		if (num >= t) {
			num_str += '1';
			num -= t;
		} else {
			num_str += '0';
		}
		t /= 2;
	}
	cout << num_str << endl;
}

int main(int argc, char** argv) {
	double n = 0.625;
	print_as_binary(n);
}
