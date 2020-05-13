#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<bool>> tbl(N, vector<bool>(N));

	for(int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for(int j = 0; j < N; ++j)
			tbl[i][j] = tmp[j]-'0' ? true : false;
	}

	for(int k = 0; k < N; ++k)
  		for(int i = 0; i < N; ++i)
    		for(int j = 0; j < N; ++j)
     			tbl[i][j] ||= (tbl[i][k] && tbl[k][j]);

    for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			cout << tbl[i][j];
		cout << '\n';
    }

	return 0;
}