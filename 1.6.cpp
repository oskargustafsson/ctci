#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const char* compress(const char* in) {
	const int inLen = strlen(in);
	char* out = new char[2 * inLen]();

	// TODO: handle strlen(in) == 0

	int inPos = 0, outPos = 0, repeats = 0;
	char prevCh = in[inPos++];

	for (;;) {
		char ch = in[inPos++];

		if (ch == prevCh) {
			repeats++;
		} else {
			out[outPos++] = prevCh;
			out[outPos++] = '1' + repeats; // TODO: > 9 repeats
			repeats = 0;
		}

		prevCh = ch;

		if (!ch) {
			break;
		}
	}

	if (inLen <= outPos) {
		strcpy(out, in);
	}

	return out;
}

int main(int argc, char** argv) {
	printf("%s\n", compress(argv[1]));
}
