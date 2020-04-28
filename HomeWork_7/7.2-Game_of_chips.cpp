#include <iostream>
#include <vector>
using namespace std;

int X, Y;

bool F(int i, int j, vector<vector<char>> &table) {
	if(table[i][j]+1)
		return table[i][j] == 'w' ? true : false;
	for(int y = 1; y < Y-j; ++y)
		if(!F(i, j+y, table)) {
			table[i][j] = 'w';
			return true;
		}
	for(int x = 1; x < X-i; ++x)
		if(!F(i+x, j, table)) {
			table[i][j] = 'w';
			return true;
		}
	for(int k = 1; k < min(X-i, Y-j); ++k)
		if(!F(i+k, j+k, table)) {
			table[i][j] = 'w';
			return true;
		}
	table[i][j] = 'l';
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y;
	vector<vector<char>> table(X, vector<char>(Y, -1));
	table[X-1][Y-1] = 'l';
	

	if(F(0, 0, table))
		cout << 'F';
	else
		cout << 'S';

	return 0;
}