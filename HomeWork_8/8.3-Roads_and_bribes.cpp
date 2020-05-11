#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mp make_pair

int find_root(short r, vector<short> &p) {
	if (p[r] == r) return r;
	return p[r] = find_root(p[r], p);
}

void merge(short l, short r, vector<short> &p) {
	l = find_root(l, p);
	r = find_root(r, p);
	if (rand() % 1)
		p[l] = r;
	else 
		p[r] = l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, pair<short, short>>> Edges;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			int a;
			cin >> a;
			if (j <= i || a == 0)
				continue;
			Edges.push_back(mp(a, mp(i, j)));
		}

	sort(Edges.begin(), Edges.end());
	reverse(Edges.begin(), Edges.end());

	vector<short> p(N);
	for(int i = 0; i < N; ++i)
		p[i] = i;

	int MST_count = 0;
	int curr = 0;
	int answer = 0;

	while(MST_count != N - 1) {
		short a = Edges[curr].second.first;
		short b = Edges[curr].second.second;

		if (find_root(a, p) == find_root(b, p)) {
			++curr;
			continue;
		}
		++MST_count;
		answer += Edges[curr].first;
		++curr;
		merge(a, b, p);
	}

	cout << answer;

	return 0;
}