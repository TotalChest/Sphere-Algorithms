#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned long long N, K;
	cin >> N >> K;
	unsigned long long pow = 1;
	while (pow * 10 <= K)
		pow *= 10;
	unsigned long long K1 = K;
	unsigned long long pow1 = pow;
	unsigned long long res = 0;
	while (pow1 >= 1) {
		res += K1 - pow1 + 1;
		pow1 /= 10;
		K1 /= 10;
	}
	if (K != pow)
		while (1){
			pow *= 10;
			if (pow > N)
				break;
			K *= 10;
			if (N < K) {
				res += N - pow + 1;
				break;
			}
			else
				res += K - pow;
		}
	cout << res;
	return 0;
}