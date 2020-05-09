#include <iostream>
#include  <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	vector<vector<unsigned long long>> tbl(30, vector<unsigned long long> (str.size(), 0));

	for(int i = 0; i < str.size(); ++i)
		tbl[i][i] = 1;

	for(int len = 1; len < str.size(); ++len)
		for(int i = 0; i + len < str.size(); i++) {
			int j = i + len;
			if (str[i] == str[j])
				tbl[i][j] = tbl[i+1][j] + tbl[i][j-1] + 1;
			else
				tbl[i][j] = tbl[i+1][j] + tbl[i][j-1] - tbl[i+1][j-1];
		}

	cout << tbl[0][str.size() - 1];
	return 0;
}