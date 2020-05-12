#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K, S, F;

vector<int> dist(int src, map<int, vector<pair<int, int>>> &edges) {
	vector<int> d(N, -1);
	vector<int> color(N, 0);
	queue<int> Q;

	Q.push(src);
	d[src] = 0;
	color[src] = 1;

	while(!(Q.empty())) {
		int curr = Q.front();
		Q.pop();
		color[curr] = 1;
		vector<pair<int, int>> tmp = edges[curr];
		sort(tmp.begin(), tmp.end());
		for(auto elem: tmp) {
			if(color[elem.second] == 0)
				Q.push(elem.second);
			if (d[elem.second] == -1 || d[elem.second] > d[curr] + elem.first) {
				d[elem.second] = d[curr] + elem.first;
			}
		}
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	vector<int> f(K);
	map<int, vector<pair<int, int>>> edges;
	for (int i = 0; i < K; ++i) {
		cin >> f[i];
		--f[i];
	}
	for (int i = 0; i < M; ++i) {
		int s, d, w;
		cin >> s >> d >> w;
		--s;
		--d;
		edges[s].push_back(make_pair(w,d));
		edges[d].push_back(make_pair(w,s));
	}
	cin >> S >> F; --S; --F;
	vector<int> d = dist(F, edges);
	if (d[S] == -1) {
		cout << -1;
		return 0;
	}
	int exit = d[S], min = 1000000000;;
	for (int i = 0; i < K; ++i)
		if (d[f[i]] < min)
			min = d[f[i]];
	if (min < exit)
		cout << -1;
	else
		cout << exit;

	return 0;
}