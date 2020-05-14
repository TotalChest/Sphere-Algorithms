#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int max = 0;
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> v(N, vector<int>(M, -1));
	queue<pair<int, int>> Q;
	for (int i = 0; i < K; ++i){
		int a, b;
		cin >> a >> b;
		Q.push(make_pair(a,b));
		v[a][b] = 0;
	}

	while (!Q.empty()) {
		pair<int, int> tmp = Q.front();
		Q.pop();
		int curr = v[tmp.first][tmp.second];
		if (curr > max)
			max = curr;
		if(tmp.first + 1 < N && v[tmp.first+1][tmp.second] == -1) {
			v[tmp.first+1][tmp.second] = curr + 1;
			Q.push(make_pair(tmp.first+1, tmp.second));
		}
		if(tmp.first - 1 >= 0 && v[tmp.first-1][tmp.second] == -1) {
			v[tmp.first-1][tmp.second] = curr + 1;
			Q.push(make_pair(tmp.first-1, tmp.second));
		}
		if(tmp.second + 1 < M && v[tmp.first][tmp.second+1] == -1) {
			v[tmp.first][tmp.second+1] = curr + 1;
			Q.push(make_pair(tmp.first, tmp.second+1));
		}
		if(tmp.second - 1 >= 0 && v[tmp.first][tmp.second-1] == -1) {
			v[tmp.first][tmp.second-1] = curr + 1;
			Q.push(make_pair(tmp.first, tmp.second-1));
		}
	}

	cout << max;
	return 0;
}