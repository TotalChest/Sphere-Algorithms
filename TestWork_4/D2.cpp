#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int neighbours(int pos, unordered_set<int> &living) {
	int delta[] = {1, -1, M, -M, M+1, M-1, -M-1, -M+1};
	int delta_x[] = {0, 0, 1, -1, 1, 1, -1, -1};
	int delta_y[] = {1, -1, 0, 0, 1, -1, -1, 1};
	int count = 0;
	int x = pos / M;
	int y = pos % M;
	for (int j = 0; j < 8; ++j) {
		int new_x = x + delta_x[j];
		int new_y = y + delta_y[j];
		if (new_x >= N || new_x < 0 || new_y >= M || new_y < 0)
			continue;
		if (living.find(pos + delta[j]) != living.end())
			++count;
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L, K;
	cin >> N >> M >> L >> K;
	unordered_set<int> living;
	for (int i = 0; i < L; ++i) {
		int x, y;
		cin >> x >> y;
		living.insert(x*M + y);
	}

	int delta[] = {1, -1, M, -M, M+1, M-1, -M-1, -M+1};
	int delta_x[] = {0, 0, 1, -1, 1, 1, -1, -1};
	int delta_y[] = {1, -1, 0, 0, 1, -1, -1, 1};

	for (int i = 0; i < K; ++i) {
		unordered_set<int> new_living = living;
		for (auto elem: living) {
			int nb = neighbours(elem, living);
			if (nb != 2 && nb != 3)
				new_living.erase(elem);
		}
		for (auto elem: living) {
			int x = elem / M;
			int y = elem % M;
			for (int j = 0; j < 8; ++j){
				int new_x = x + delta_x[j];
				int new_y = y + delta_y[j];
				if (new_x >= N || new_x < 0 || new_y >= M || new_y < 0)
					continue;
				if (neighbours(elem + delta[j], living) == 3)
					new_living.insert(elem+delta[j]);
			}
		}
		living = new_living;
	}

	vector<pair<int, int>> answer;
	for (auto elem: living)
		answer.push_back(make_pair(elem / M, elem % M));
	sort(answer.begin(), answer.end());
	for (auto elem: answer)
		cout << elem.first << ' ' << elem.second << '\n';

	return 0;
}