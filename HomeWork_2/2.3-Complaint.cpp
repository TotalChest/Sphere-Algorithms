#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using ul = unsigned long;

int main()
{
	ul n, max = 0, temp = 0;
	scanf("%ld", &n);

	std::vector<std::pair<ul, ul>> vec(2*n);

	for(int i = 0; i < n; ++i)
	{
		int h1, h2, m1, m2, s1, s2;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		vec[2*i] = {h1*60*60 + m1*60 + s1, 1}; 
		vec[2*i + 1] = {h2*60*60 + m2*60 + s2, 2};
	}

	std::sort(vec.begin(), vec.end());

	for(int i = 0; i < 2*n; ++i)
		if(vec[i].second == 1)
		{
			if(++temp > max)
				max = temp;
		}
		else
			--temp;

	printf("%ld", max);

	return 0;
}