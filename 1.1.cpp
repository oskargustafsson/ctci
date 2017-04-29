#include "stdio.h"

bool areAllCharsUnique(char* str) {
	bool existingChars[255] = { 0 };
	int pos = 0;
	while (char ch = str[pos]) {
		if (existingChars[ch]) {
			return false;
		}
		existingChars[ch] = true;
		pos++;
	}
	return true;
}

int main(int argc, char** argv) {
	char* str = argv[1];
	printf("%s unique: %i\n", str, areAllCharsUnique(str));
}
