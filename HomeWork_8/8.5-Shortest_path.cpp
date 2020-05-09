#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000;

struct edge{
	int src, dst, weigth;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, S;
	cin >> N >> M >> S;
	vector<edge> Edges(M);

	for (int i = 0; i < M; ++i)
		cin >> Edges[i].src >> Edges[i].dst >> Edges[i].weigth;

	vector<int> answer(N, INF);
	vector<int> color(N, 0);
	
	int k = S;
	do {
		if (color[k]) {
			k = (k + 1)%N;
			continue;
		}

		vector<int> d(N, INF);
		d[k] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j)
				if (d[Edges[j].src] < INF) {
					color[Edges[j].src] = 1;
					if (d[Edges[j].dst] > d[Edges[j].src]  + Edges[j].weigth) {
						d[Edges[j].dst] = d[Edges[j].src]  + Edges[j].weigth;
						if (i == N - 1) {
							cout << "IMPOSSIBLE\n";
							return 0;
						}
					}
				}
		}
		if (k == S)
			answer = d;
		k = (k + 1)%N;
	} while (k != S);

	for (int i = 0; i < N; ++i)
		if (answer[i] == INF)
			cout << "UNREACHABLE ";
		else
			cout << answer[i] << " ";

	return 0;
}