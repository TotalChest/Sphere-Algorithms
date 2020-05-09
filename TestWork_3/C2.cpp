#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int N, M;

unsigned long long F(int x, int y, int K, vector<vector<char>> &tbl, map<tuple<int, int, int>, unsigned long long> &MAP) {
	if(tbl[x][y] == '#' and K == 0)
		return 1;
	if(K == 0)
		return 0;
	if(MAP.find(make_tuple(x, y, K)) != MAP.end())
		return MAP[make_tuple(x, y, K)];

	unsigned long long count = 0;
	if(x+1 < N and tbl[x+1][y] != '+')
		count += F(x+1, y, K-1, tbl, MAP);
	if(y+1 < M and tbl[x][y+1] != '+')
		count += F(x, y+1, K-1, tbl, MAP);
	if(x-1 >= 0 and tbl[x-1][y] != '+')
		count += F(x-1, y, K-1, tbl, MAP);
	if(y-1 >= 0 and tbl[x][y-1] != '+')
		count += F(x, y-1, K-1, tbl, MAP);
	MAP[make_tuple(x, y, K)] = count;
	return count;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K,x, y;
	cin >> N >> M >> K;

	vector<vector<char>> tbl(M, vector<char>(M));
	map<tuple<int, int, int>, unsigned long long> MAP; 


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			cin >> tbl[i][j];
			if(tbl[i][j] == '@'){
				x = i;
				y = j;
			}
		}

	cout << F(x, y, K, tbl, MAP);

	return 0;
}