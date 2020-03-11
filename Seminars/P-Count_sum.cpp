#include <cstdio>

using ul = unsigned long;

int main()
{
	ul x, count = 0;

	scanf("%lu", &x);

	for(ul a = 1; a <= x/4; ++a)
		for(ul b = a; b <= (x - a)/3; ++b)
			count += (x - a - b)/2 - b + 1;

	printf("%lu", count);

	return 0;
}