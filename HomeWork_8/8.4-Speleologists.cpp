#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

long long N, M, K, S, F;

vector<long long> dist(long long src, map<long long, vector<pair<long long, long long>>> &edges) {
	vector<long long> d(N, -1);
	vector<long long> color(N, 0);
	queue<long long> Q;

	Q.push(src);
	d[src] = 0;
	color[src] = 1;

	while(!(Q.empty())) {
		long long curr = Q.front();
		Q.pop();
		color[curr] = 1;
		vector<pair<long long, long long>> tmp = edges[curr];
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
	vector<long long> f(K);
	map<long long, vector<pair<long long, long long>>> edges;
	for (int i = 0; i < K; ++i) {
		cin >> f[i];
		--f[i];
	}
	for (int i = 0; i < M; ++i) {
		long long s, d, w;
		cin >> s >> d >> w;
		--s;
		--d;
		if (s == d)
			continue;
		edges[s].push_back(make_pair(w,d));
		edges[d].push_back(make_pair(w,s));
	}
	cin >> S >> F; --S; --F;
	vector<long long> d = dist(F, edges);
	if (d[S] == -1) {
		cout << -1;
		return 0;
	}
	long long exit = d[S], min = 10000000000;;
	for (int i = 0; i < K; ++i)
		if (d[f[i]] < min)
			min = d[f[i]];
	if (min < exit)
		cout << -1;
	else
		cout << exit;

	return 0;
}