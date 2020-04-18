#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int max = 0;
	string str;
	cin >> str;

	for (int len = 1; len < str.size()+1; ++len) {
		unordered_map<string, int> MAP;
		for (int i = 0; i < str.size() - len + 1; ++i)
			if(MAP.find(str.substr(i, len)) == MAP.end())
				MAP[str.substr(i, len)] = 1;
			else
				MAP[str.substr(i, len)] += 1;

		for (auto elem: MAP)
			if (elem.second * len > max)
				max = elem.second * len;
		MAP.clear();
	}

	cout << max;

	return 0;
}