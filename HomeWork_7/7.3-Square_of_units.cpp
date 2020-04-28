#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, max = 0;;
	cin >> N;
	vector<vector <unsigned>> table(N, vector<unsigned>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			if (table[i][j] > max)
				max = 1;
		}
	
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j) 
			if (table[i][j] == 1) {
				table[i][j] = min({table[i-1][j-1],
								table[i][j-1],
								table[i-1][j]}) + 1;
				if (table[i][j] > max)
					max = table[i][j];
			}
	cout << max;

	return 0;
}