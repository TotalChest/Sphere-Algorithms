#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, curr, max = 0;
	cin >> N >> M;
	unordered_map<int, vector<int>> MAP;
	vector<int> freq(N, 0);
	for (int j = 0; j < M; ++j) {
		cin >> curr;
		MAP[curr].push_back(0);
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> curr;

			if(MAP.find(curr) == MAP.end())
				MAP[curr].push_back(i);
			else {
				for (int k = 0; k < MAP[curr].size(); ++k)
					++freq[MAP[curr][k]];
				MAP[curr].push_back(i);
			}
		}
		for (int k = 0; k < i; ++k) {
			if(freq[k] > max)
				max = freq[k];
			freq[k] = 0;
		}
	}
	cout << max << '\n';
	return 0;
}