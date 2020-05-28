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

	//BFS для всех компонент связности
	vector<char> color(N, '0');	
	queue<int> Q;
	for (int i = 0; i < N; ++i)
		if (V.find(i) != V.end() && color[i] == '0') {
			Q.push(i);
			color[i] = '1';
			while(!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				for (auto elem: V[curr])
					if (color[elem] == '0') {
						color[elem] = '1';
						Q.push(elem);
					}
			}
		}
		
	return 0;
} 