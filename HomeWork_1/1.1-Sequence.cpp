#include <iostream>

int main(void)
{
	unsigned int N;
	unsigned long long K, L;

	std::cin >> N >> K >> L;

	for(unsigned long i = K; i <= L; i++)
	{
		unsigned long j = i - 1;
		unsigned long M = N;
		while(j != 0)
		{
			if(j >= 1<<(M-1))
				j -= ((1<<(M-1))-1);
			M--;
			j--;
		}

		std::cout << (char)((unsigned int)'a' + M - 1);
	}		
	
	return 0;
}