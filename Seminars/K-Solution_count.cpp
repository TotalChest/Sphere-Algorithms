#include <iostream>

int main()
{
	long long N, y0 = 0, count = 0;
	scanf("%lld", &N);
	long long p1 = y0*y0, p2 = (y0 + 1) * (y0 + 1);

	while(!(p1 < N && p2 >= N))
	{
		++y0;
		p1 = y0*y0, p2 = (y0 + 1) * (y0 + 1);
	}
	p1 = y0;
	for(long long i = 0; i <= p1; ++i)
	{
		while(i*i + y0*y0 >= N)
			--y0;
		count += y0 + 1;
	}

	printf("%lld", count);
	return 0;
}