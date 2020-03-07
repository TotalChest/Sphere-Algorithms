#include <stdio.h>
#include <vector>
#include <iostream>

using ul = unsigned long;

const ul MAX = 20000000;

std::vector<bool> prime(MAX, true);
std::vector<ul> v;

int main()
{
	ul m, n;
	long k = -1; 

	scanf("%ld %ld", &m, &n);

	for(ul p = 2; p*p < MAX; ++p){
		if(prime[p])
			for(ul j = p*p; j < MAX; j += p)
				prime[j] = false;
	}

	ul l = 2, r = n + 1, count = 0;

	for(ul i = l; i <= r; ++i)
		if(prime[i])
			++count;


	for(ul i = l; i < MAX - n; ++i)
	{
		if(count == m)
		{
			k = i;
			break;
		}
		
		if(prime[++r])
			++count;
		if(prime[l++])
			--count;
	}


	printf("%ld", k);


	return 0;

}