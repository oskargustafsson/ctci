#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_permutation_of_palindrome(char* str) {
	int char_counts[255] = {0};
	int pos = 0;

	while (char ch = str[pos++]) {
		if (ch != ' ') {
			char_counts[ch]++;
		}
	}

	int n_odd_char_counts = 0;
	for (int char_count : char_counts) {
		if ((char_count & 1) == 1) {
			n_odd_char_counts++;
		}
	}

	return n_odd_char_counts < 2;
}

int main(int argc, char** argv) {
	char* str = argv[1];
	printf("%s %i\n", str, is_permutation_of_palindrome(str));
}
