#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

double F(int N, unsigned long long M, vector<unordered_map<unsigned long long, double>> &S) {
	if(N == 1 && M >= 1 && M <= 6)
		return 1/6.0;
	if(N == 1 || (long long)M <= 0)
		return 0;
	if(S[N-1].find(M) != S[N-1].end())
		return S[N-1][M]/6.0;
	S[N-1][M] = 0;
	for (int i = 1; i <= 6; ++i)
		S[N-1][M] += F(N-1, M-i, S);
	return S[N-1][M]/6.0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long M;
	int N;
	cin >> N >> M;
	vector<unordered_map<unsigned long long, double>> S(N);
	cout.precision(12);
	cout << F(N, M, S);
	return 0;
}