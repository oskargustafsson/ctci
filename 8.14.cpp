#include <stdio.h>
#include <stdlib.h>
#include <initializer_list>
#include <algorithm>
#include <stack>
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

int count_eval(const char* expr, int length, bool should_be_true) {
	if (length == 1) {
		int count = (should_be_true ? 1 : 0) == (expr[0] - '0');
		return count;
	}
	int count = 0;
	for (int i = 0; i < length; i++) {
		char ch = expr[i];
		switch (ch) {
			case '|': {
				int n_left_false = count_eval(expr, i, false);
				int n_right_false = count_eval(expr + i + 1, length - (i + 1), false);
				if (should_be_true) {
					int n_left_true = count_eval(expr, i, true);
					int n_right_true = count_eval(expr + i + 1, length - (i + 1), true);
					count += (n_left_true * n_right_true) + (n_left_true * n_right_false) + (n_left_false * n_right_true);
				} else {
					count += (n_left_false * n_right_false);
				}
				break;
			}
			case '&': {
				int n_left_true = count_eval(expr, i, true);
				int n_right_true = count_eval(expr + i + 1, length - (i + 1), true);
				if (should_be_true) {
					count += (n_left_true * n_right_true);
				} else {
					int n_left_false = count_eval(expr, i, false);
					int n_right_false = count_eval(expr + i + 1, length - (i + 1), false);
					count += (n_left_false * n_right_false) + (n_left_false * n_right_true) + (n_left_true * n_right_false);
				}
				break;
			}
			case '^': {
				int n_left_true = count_eval(expr, i, true);
				int n_left_false = count_eval(expr, i, false);
				int n_right_true = count_eval(expr + i + 1, length - (i + 1), true);
				int n_right_false = count_eval(expr + i + 1, length - (i + 1), false);
				if (should_be_true) {
					count += (n_left_true * n_right_false) + (n_left_false * n_right_true);
				} else {
					count += (n_left_true * n_right_true) + (n_left_false * n_right_false);
				}
				break;
			}
		}
	}
	return count;
}

int main(int argc, char** argv) {
	{
		char expr[] = "1^0|0|1";
		int expr_len = sizeof(expr) - 1;
		printf("Parenthezations of %s that evaluates to %i: %i\n", expr, false, count_eval(expr, expr_len, false));
	}
	{
		char expr[] = "0&0&0&1^1|0";
		int expr_len = sizeof(expr) - 1;
		printf("Parenthezations of %s that evaluates to %i: %i\n", expr, true, count_eval(expr, expr_len, true));
	}
}
