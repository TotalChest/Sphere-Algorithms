#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

const unsigned long long PR = 24571;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_set<unsigned long long> S;
	int N, M, K;
	unsigned long long curr;
	cin >> N >> M >> K;
	vector<unsigned long long> tab(M);
	tab[0] = 1;
	for (int j = 0; j < M; ++j)
		tab[j] =  PR * tab[j-1];

	for (int i = 0; i < N; ++i) {
		unsigned long long hash = 0;
		vector <unsigned long long> tmp(M);
		for (int j = 0; j < M; ++j)
			cin >> tmp[j];
		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < M; ++j)
			hash += tmp[j] * tab[j];
		S.insert(hash);
	}

	for (int i = 0; i < K; ++i) {
		unsigned long long hash = 0;
		vector <unsigned long long> tmp(M);
		for (int j = 0; j < M; ++j)
			cin >> tmp[j];
		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < M; ++j)
			hash += tmp[j] * tab[j];
		if(S.find(hash) != S.end())
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}