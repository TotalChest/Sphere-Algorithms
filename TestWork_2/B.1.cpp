#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long N, H, W;
	cin >> W >> H >> N;
	unsigned long long cur = H > W ? H*N : W*N;
	unsigned long long r = cur, l = 1;
	while(r - l > 1){
		unsigned long long mid = (r+l)/2;
		if ((mid/H) * (mid/W) >= N)
			r = mid;
		else 
			l = mid;
	}
	cout << r;
	return 0;
}