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
#include <set>

using namespace std;

int multiply(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if (b == 1) {
		return a;
	}
	if (a & 1 == 0) {
		a >>= 1;
		return multiply(a, b) + multiply(a, b);
	}
	if (b & 1 == 0) {
		b >>= 1;
		return multiply(a, b) + multiply(a, b);
	}
	return a + multiply(a, b - 1);
}

int main(int argc, char** argv) {
	int a = 6;
	int b = 7;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%i * %i = %i\n", i, j, multiply(i, j));
		}
	}
}
