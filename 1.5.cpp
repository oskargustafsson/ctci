#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

bool is_similar(const char* s0, const char* s1) {
	int s0len = strlen(s0);
	int s1len = strlen(s1);

	if (s0len < s1len) {
		std::swap(s0, s1);
		std::swap(s0len, s1len);
	}

	if (s0len - s1len > 1) {
		return false;
	}

	int ops = 0, offset = 0;

	for (int i = 0; i < s0len; i++) {
		if (i < s1len && s0[i + offset] == s1[i]) {
			continue;
		}
		if (ops != 0) {
			return false;
		}
		if (i < s1len && s0[i + offset + 1] == s1[i]) {
			offset++;
		}
		ops++;
	}

	return true;
}

int main(int argc, char** argv) {
	printf("%i\n", is_similar(argv[1], argv[2]));
}
