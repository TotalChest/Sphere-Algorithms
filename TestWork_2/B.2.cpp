#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	multiset<long long> S;
	int N, K;
	long long a;
	cin >> N >> K;
	for(int i = 0; i < N; ++i) {
		cin >> a;
		if(S.size() < K)
			S.insert(a);
		else
			if(a > *(S.begin())) {
				S.erase(S.begin());
				S.insert(a);
			}
	}

	for(auto it = S.rbegin(); it != S.rend(); ++it)
		cout << *(it) << '\n';
	
}