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

#include <chrono>
#include <thread>

using namespace std;

struct Coord {
	int x, y;
};

template <int W, int H, typename T>
struct Bitmap {
	T& operator()(int x, int y) { return pixels[W * y + x]; }
	T& operator()(Coord c) { return (*this)(c.x, c.y); }
	void print() {
		for (int i = 0; i < W * H; i++) {
			T val = pixels[i];
			if (val == 0) {
				cout << ' ';
			} else {
				cout << val;
			}
			if (i % W == W - 1) {
				cout << endl;
			}
		}
		cout << endl;
	}
	T pixels[W * H] = { 0 };
};

template <int W, int H, typename T>
void fill(Bitmap<W, H, T>& bitmap, Coord coord, T val) {
	T old_val = bitmap(coord);
	queue<Coord> fill_queue;
	fill_queue.push(coord);

	while (!fill_queue.empty()) {
		coord = fill_queue.front();
		fill_queue.pop();
		if (coord.x < 0 || W <= coord.x || coord.y < 0 || H <= coord.y || bitmap(coord) != old_val) {
			continue;
		}
		bitmap(coord) = val;
		fill_queue.push({ coord.x - 1, coord.y });
		fill_queue.push({ coord.x + 1, coord.y });
		fill_queue.push({ coord.x, coord.y + 1 });
		fill_queue.push({ coord.x, coord.y - 1 });

		bitmap.print();
		this_thread::sleep_for(chrono::milliseconds(23));
	}
}

int main(int argc, char** argv) {
	Bitmap<16, 16, char> bitmap;
	bitmap(2, 2) = '#';
	bitmap(3, 2) = '#';
	bitmap(4, 2) = '#';
	bitmap(5, 2) = '#';

	bitmap(2, 3) = '#';
	bitmap(2, 4) = '#';
	bitmap(2, 5) = '#';
	bitmap(2, 6) = '#';

	bitmap(9, 6) = '#';
	bitmap(9, 7) = '#';
	bitmap(9, 8) = '#';
	bitmap(9, 9) = '#';
	bitmap(9, 10) = '#';
	bitmap(9, 11) = '#';
	bitmap(9, 12) = '#';
	bitmap(9, 13) = '#';
	bitmap(9, 14) = '#';

	bitmap(10, 6) = '#';
	bitmap(11, 6) = '#';
	bitmap(12, 6) = '#';
	bitmap(13, 6) = '#';
	bitmap(14, 6) = '#';
	bitmap(15, 6) = '#';

	bitmap.print();
	fill(bitmap, Coord{4, 4}, '.');
	bitmap.print();
}
