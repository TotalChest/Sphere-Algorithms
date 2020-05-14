#include <iostream>
#include <vector>
#include <set>
using namespace std;

int count;

int find_root(int r, vector<int> &p) {
	if (p[r] == r) return r;
	return p[r] = find_root(p[r], p);
}

void merge(int l, int r, vector<int> &p) {
	l = find_root(l, p);
	r = find_root(r, p);
	if (l != r)
		--count;
	if (rand() % 1)
		p[l] = r;
	else 
		p[r] = l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, E, M;
	cin >> V >> E >> M;
	count = V;
	vector<int> Vert(V);
	set<pair<int, int>> edges;
	for (int i = 0; i < V; ++i)
		Vert[i] = i;

	for (int i = 0; i < E; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			edges.insert(make_pair(a, b));
		else
			edges.insert(make_pair(b, a));
	}

	vector<pair<int, int>> mas(M);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			mas[i] = make_pair(a, b);
		else
			mas[i] = make_pair(b, a);
		edges.erase(mas[i]);
	}

	for (auto elem: edges)
		merge(elem.first, elem.second, Vert);

	
	vector<int> answer(M);

	for (int i = M-1; i >= 0; --i) {
		answer[i] = count;
		merge(mas[i].first, mas[i].second, Vert);
	}

	cout << count << '\n';
	for (int i = 0; i < M; ++i)
		cout << answer[i] << '\n';

	return 0;
}