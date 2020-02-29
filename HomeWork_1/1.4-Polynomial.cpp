#include <iostream>

int main()
{
	unsigned long N, M, MOD, res, x;
	std::cin >> N >> M >> MOD;

	unsigned long k[N+1];

	for(unsigned long i = 0; i < N + 1; i++)
	{	
		std::cin >> x;
		k[i] = x % MOD;
	}

	for(unsigned long j = 0; j < M; j++)
	{
		std::cin >> x;
		x = x % MOD; 
		res = k[0];

		for(unsigned long i = 0; i < N; i++)
		{
			res = (res * x + k[i+1]) % MOD;
		}

		std::cout << res << std::endl;
	}

	return 0;
}