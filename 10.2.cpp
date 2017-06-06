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

void anagram_sort(vector<string>& strings) {
	sort(strings.begin(), strings.end(), [](string str0, string str1) {
		sort(str0.begin(), str0.end());
		sort(str1.begin(), str1.end());
		return str0 < str1;
	});
}

void anagram_sort2(vector<string>& strings) {
	map<string, vector<string>> string_groups;
	for (string& str : strings) {
		string sorted_str = str;
		sort(sorted_str.begin(), sorted_str.end());
		string_groups[sorted_str].push_back(str);
	}

	strings.clear();
	for (auto& string_group : string_groups) {
		for (string& str : string_group.second) {
			strings.push_back(str);
		}
	}
}

int main(int argc, char** argv) {
	{
		vector<string> strings = { "aabb", "abcd", "cdef", "baab", "dcba", "test" };
		anagram_sort(strings);
		for (string& str : strings) {
			cout << str << endl;
		}
	}
	cout << endl;
	{
		vector<string> strings = { "aabb", "abcd", "cdef", "baab", "dcba", "test" };
		anagram_sort2(strings);
		for (string& str : strings) {
			cout << str << endl;
		}
	}
}
