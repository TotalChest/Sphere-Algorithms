#include <stdio.h>
#include <vector>

using ul = unsigned long;

int main()
{
	ul n, r, i_min = 0;
	unsigned long long temp = 0;

	scanf("%ld %ld", &n, &r);
	std::vector<ul> v(r, 0);

	for(ul i = 0; i < n; i++)
	{
		ul a;
		scanf("%ld", &a);
		++v[a];
		temp += r - a;
	}

	unsigned long long min = temp;

	for(ul i = 1; i < r; i++)
	{
		temp = temp + n - v[i]*r;
		if(temp < min)
		{
			min = temp;
			i_min = i;
		}
	}

	printf("%ld", i_min);

	return 0;
}