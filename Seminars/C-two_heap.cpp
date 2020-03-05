#include <stdio.h>
#include <vector>

using ll = long long; //c++11

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> w(n);

	ll sum = 0;

	for(int i =0; i < n; ++i)
	{
		scanf("%d", &w[i]);
		sum += w[i];
	}

	ll min = sum + 1;

	ll temp = (1u << (n - 1)) - 1;

	for(unsigned g = (1u << n) - 1; g > temp; --g)
	{
		ll c = 0;

		unsigned mask = g;
		for(int i = 0; mask != 0; ++i)
		{
			c += (mask & 1) * w[i];
			mask >>= 1;
		}

		c = sum - c - c;

		if(c < 0)
			c = -c;

		if(c < min)
			min = c;

	}

	printf("%lld\n", min);

	return 0;
}