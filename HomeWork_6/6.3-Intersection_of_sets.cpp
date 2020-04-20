#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<unsigned short> freq(1000, 0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unsigned short N, M, max = 0;
	int curr;
	cin >> N >> M;
	unordered_map<int, vector<unsigned short>> MAP;
	for (unsigned short j = 0; j < M; ++j) {
		cin >> curr;
		MAP[curr].push_back(0);
	}
	for (unsigned short i = 1; i < N; ++i) {
		for (unsigned short j = 0; j < M; ++j) {
			cin >> curr;

			if(MAP.find(curr) == MAP.end())
				MAP[curr].push_back(i);
			else {
				for (int k = 0; k < MAP[curr].size(); ++k)
					++freq[MAP[curr][k]];
				MAP[curr].push_back(i);
			}
		}
		for (unsigned short k = 0; k < i; ++k) {
			if(freq[k] > max)
				max = freq[k];
			freq[k] = 0;
		}
	}
	cout << max << '\n';
	return 0;
}