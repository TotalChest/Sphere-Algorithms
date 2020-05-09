#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	unordered_map<int, vector<int>> V;
	for (int i = 0; i < M; ++i) {
		int s, d;
		cin >> s >> d;
		V[s].push_back(d);
		V[d].push_back(s);
	}

	vector<char> color(N, '0');	
	queue<int> Q;
	char c[2] = {'1', '2'};
	int cur_color = 0;
	for (int i = 0; i < N; ++i)
		if (V.find(i) != V.end() && color[i] == '0') {
			Q.push(i);
			cur_color = 0;
			color[i] = c[cur_color];
			while(!Q.empty()) {
				int curr = Q.front();
				cur_color = color[curr]-'1';
				Q.pop();
				for (auto elem: V[curr]) {
					if (color[elem] == c[cur_color]) {
						cout << "NO\n";
						return 0;
					}
					if (color[elem] == '0') {
						color[elem] = c[(cur_color+1)&1];
						Q.push(elem);
					}
				}
			}
		}

	cout << "YES\n";
	return 0;
} 