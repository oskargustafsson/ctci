#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* urlify(char* str, int strLen) {
	for (int i = 0; i < strLen; i++) {
		char* substr = str + i;
		if (substr[0] == ' ') {
			memcpy(substr + 2, substr, strLen - i);
			memcpy(substr, "%20", 3);
			i += 2;
			strLen += 2;
		}
	}
	str[strLen] = '\0';
	return str;
}

char* urlify_better(char* str, int strLen) {
	int nSpaces = 0;
	for (int i = 0; i < strLen; i++) {
		if (str[i] == ' ') {
			nSpaces++;
		}
	}

	int head = strLen;
	int tail = strLen + 2 * nSpaces;
	str[tail] = '\0';

	while (head > 0) {
		char ch = str[head];
		if (ch == ' ') {
			memcpy(str + tail - 2, "%20", 3);
			tail -= 2;
		} else {
			str[tail] = str[head];
		}
		head--;
		tail--;
	}

	return str;
}

int main(int argc, char** argv) {
	char* origStr = argv[1];
	int strLen = atoi(argv[2]);

	{
		char str[strLen + 100];
		strcpy(str, origStr);
		printf("urlify1: %s, %s\n", origStr, urlify(str, strLen));
	}

	{
		char str[strLen + 100];
		strcpy(str, origStr);
		printf("urlify2: %s, %s\n", origStr, urlify_better(str, strLen));
	}
}
