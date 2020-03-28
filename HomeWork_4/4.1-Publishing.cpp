#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	size_t K, N, i = 0, d;
	size_t l = 0, r = 10000000, mid, sum;
	scanf("%lu %lu", &K, &N);
	vector<size_t> V(N);
	for(i = 0; i < N; ++i)
	{
		scanf("%ld", &V[i]);
		l = max(l, V[i]);
	}

	l = l -1;
	while(r-l>1)
	{
		mid = (l+r)/2;
		i = 0;
		d = 0;
		sum = 0;
		while(i < N)
		{
			if(sum + V[i] > mid)
			{
				++d;
				sum = 0;
			}
			sum += V[i];
			++i;
		}

		++d;

		if(d <= K)
			r = mid;
		else
			l = mid;
	}

	printf("%ld", r);

	return 0;
}