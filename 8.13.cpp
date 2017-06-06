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

struct Box {
	int x, y, z;
	bool operator==(const Box& rhs) {
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}
};

int get_stack_height(list<Box>& boxes) {
	int acc_y = 0;
	for (Box& box : boxes) {
		acc_y += box.y;
	}
	return acc_y;
}

list<Box> get_tallest_stack(const list<Box>& boxes, const Box* prev_box) {
	list<Box> ret;
	int max_height = 0;
	for (const Box& box : boxes) {
		if (!prev_box || box.x > prev_box->x && box.y > prev_box->y && box.z > prev_box->z) {
			list<Box> boxes_copy(boxes);
			boxes_copy.remove(box);
			list<Box> a_stack = get_tallest_stack(boxes_copy, &box);
			int a_stack_height = box.y + get_stack_height(a_stack);
			if (a_stack_height >= max_height) {
				a_stack.push_front(box);
				ret = a_stack;
				max_height = a_stack_height;
			}
		}
	}
	return ret;
}

int main(int argc, char** argv) {
	list<Box> boxes { {1,2,3}, {3,2,1}, {4,4,4}, {4,5,6}, {5,4,3}, {3,3,2}, {1,1,1}, {2,2,1} };

	for (const Box& box : get_tallest_stack(boxes, nullptr)) {
		printf("(%i %i %i)\n", box.x, box.y, box.z);
	}
}
