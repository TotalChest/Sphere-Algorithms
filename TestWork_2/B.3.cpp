#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> vec(N);
	for(int i = 0; i < N; ++i)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	int ans;
	for(int i = 0; i < M; ++i) {
		int l = 0, r = N-1;
		cin >> ans;
		while(l < r) {
			if(vec[r] + vec[l] == ans)
				break;
			if(vec[r] + vec[l] > ans)
				--r;
			else
				++l;
		}
		if(l == r)
			cout << "Not found\n";
		else
			cout << vec[l] << ' ' << vec[r] << "\n";
	}

}