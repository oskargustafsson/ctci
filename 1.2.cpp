#include <stdio.h>
#include <string.h>

void countChars(int* countsInOut, char* str, int modifier) {
	int pos = 0;
	while (char ch = str[pos++]) {
		countsInOut[ch] += modifier;
	}
}

bool isPermutation(char* str0, char* str1) {
	if (strlen(str0) != strlen(str1)) {
		return false;
	}
	int charCounts[255] = { 0 };
	countChars(charCounts, str0, 1);
	countChars(charCounts, str1, -1);
	for (int charCount : charCounts) {
		if (charCount != 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	char* str0 = argv[1];
	char* str1 = argv[2];
	printf("%s %s permutation: %i\n", str0, str1, isPermutation(str0, str1));
}
