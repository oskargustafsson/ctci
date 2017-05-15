#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

bool is_rotation(const char* s0, const char* s1) {
	const int s0len = strlen(s0);
	const int s1len = strlen(s0);

	if (s0len != s1len) {
		return false;
	}

	char s0s0[2 * s0len + 1];
	strcpy(s0s0, s0);
	strcpy(s0s0 + s0len, s0);

	return strstr(s0s0, s1) != nullptr;
}

int main(int argc, char** argv) {
	printf("%i\n", is_rotation(argv[1], argv[2]));
}
