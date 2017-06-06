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

int n_solutions = 0;

template <int S>
struct Board {
	int& operator()(int x, int y) { return squares[S * y + x]; }
	void print() {
		for (int i = 0; i < S * S; i++) {
			int val = squares[i];
			if (val == -1) {
				cout << "Q ";
			} else {
				cout << ". ";
			}
			if (i % S == S - 1) {
				cout << endl;
			}
		}
		cout << endl;
	}
	int squares[S * S] = { 0 };
};

template <int S>
void mark_board(Board<S>& board, int x, int y, int delta) {
	board(x, y) += delta * -1; // Mark the queen
	for (int i = 1; y + i < S; i++) {
		board(x, y + i) += delta;
		if (x - i >= 0) {
			board(x - i, y + i) += delta;
		}
		if (x + i < S) {
			board(x + i, y + i) += delta;
		}
	}
}

template <int S>
void eight_queens(Board<S>& board, int y) {
	for (int x = 0; x < S; x++) {
		if (board(x, y) != 0) {
			continue;
		}
		mark_board(board, x, y, 1);
		if (y == S - 1) {
			cout << n_solutions++ << endl;
			board.print();
		} else {
			eight_queens(board, y + 1);
		}
		mark_board(board, x, y, -1);
	}
}

int main(int argc, char** argv) {
	Board<8> board;
	eight_queens(board, 0);
}
