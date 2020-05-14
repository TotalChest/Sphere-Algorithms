#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<unsigned int>> tbl(N, vector<unsigned int>(N/32+1, 0));

	for(int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for(int j = 0; j < N; ++j) {
			int b = tmp[j] == '1' ? 1 : 0;
			tbl[i][j>>5] = tbl[i][j>>5] | b<<(j&31);
		}
	}

	for(int k = 0; k < N; ++k)
  		for(int i = 0; i < N; ++i)
  			if ((tbl[i][k>>5] >> (k&31) & 1))
    			for(int j = 0; j < (N>>5) + 1; ++j)
     				tbl[i][j] = tbl[i][j] | tbl[k][j];

    for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j) {
			int answer = tbl[i][j>>5]>>(j&31) & 1;
			cout << answer;
		}
		cout << '\n';
    }

	return 0;
}