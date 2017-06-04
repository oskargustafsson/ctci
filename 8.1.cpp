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

// No optimization

template <int N>
int count_stair_climb_ways(int steps_left, const std::array<int, N>& step_counts) {
	if (steps_left == 0) {
		return 1;
	} else if (steps_left < 0) {
		return 0;
	}

	int n_step_ways = 0;
	for (int step_count : step_counts) {
		n_step_ways += count_stair_climb_ways<N>(steps_left - step_count, step_counts);
	}
	return n_step_ways;
}

// Memoization

template <int N>
int count_stair_climb_ways_memo_inner(int steps_left, const std::array<int, N>& step_counts, int* memo) {
	if (steps_left < 0) {
		return 0;
	}

	if (int memoized = memo[steps_left]) {
		return memoized;
	}

	int n_step_ways = 0;
	for (int step_count : step_counts) {
		n_step_ways += count_stair_climb_ways_memo_inner<N>(steps_left - step_count, step_counts, memo);
	}

	memo[steps_left] = n_step_ways;
	return n_step_ways;
}

template <int N>
int count_stair_climb_ways_memo(int steps_left, const std::array<int, N>& step_counts) {
	int memo[steps_left + 1] = { 1 };
	return count_stair_climb_ways_memo_inner<N>(steps_left, step_counts, memo);
}

// Dynamic programming

template <int N>
int count_stair_climb_ways_dyn(int n_steps, const std::array<int, N>& step_counts) {
	int memo[n_steps + 1] = { 1 };

	for (int i = 1; i <= n_steps; i++) {
		int n_step_ways = 0;
		for (int step_count : step_counts) {
			if (i - step_count >= 0) {
				memo[i] += memo[i - step_count];
			}
		}
	}

	return memo[n_steps];
}

////

int main(int argc, char** argv) {
	constexpr std::array<int, 3> step_counts = { 1, 2, 3 };
	constexpr int stair_steps = 10;

	printf("Ways to walk up stair with %i steps: %i\n", stair_steps, count_stair_climb_ways<3>(stair_steps, step_counts));
	printf("Ways to walk up stair with %i steps: %i\n", stair_steps, count_stair_climb_ways_memo<3>(stair_steps, step_counts));
	printf("Ways to walk up stair with %i steps: %i\n", stair_steps, count_stair_climb_ways_dyn<3>(stair_steps, step_counts));
}
