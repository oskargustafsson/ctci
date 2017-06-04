#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <string>
#include <memory>
#include <limits>
#include <list>
#include <map>
#include <iostream>
#include <array>

using namespace std;

string find_path(int pos_x, int pos_y, int grid_size_x, int grid_size_y, bool* off_limits) {
	if (pos_x < 0 || grid_size_x <= pos_x || pos_y < 0 || grid_size_y <= pos_y || off_limits[pos_y * grid_size_y + pos_x]) {
		return "";
	}

	if (pos_x == grid_size_x - 1 && pos_y == grid_size_y - 1) {
		return "X";
	}

	string path = find_path(pos_x + 1, pos_y, grid_size_x, grid_size_y, off_limits);
	if (!path.empty()) {
		return "R" + path;
	}

	path = find_path(pos_x, pos_y + 1, grid_size_x, grid_size_y, off_limits);
	if (!path.empty()) {
		return "D" + path;
	}

	off_limits[pos_y * grid_size_y + pos_x] = true;  // Memoization; remember bad paths
	return "";
}

int main(int argc, char** argv) {
	const int grid_size_x = 5;
	const int grid_size_y = 5;

	bool off_limits[grid_size_x * grid_size_y] = { 0 };

	off_limits[2 * grid_size_y + 3] = true;
	off_limits[2 * grid_size_y + 4] = true;

	cout << "Path: " << find_path(0, 0, grid_size_x, grid_size_y, off_limits) << endl;
}
