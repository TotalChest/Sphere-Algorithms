#include <stdio.h>
#include <vector>
#include <algorithm>

using ul = unsigned long;

int main()
{

	ul n, count = 0, i = 0;
	float k;

	scanf("%ld", &n);

	std::vector<float> points(n);

	for(ul i = 0; i < n; ++i)
		scanf("%f", &points[i]);

	std::sort(points.begin(), points.end());


	while(i < n)
	{
		k = points[i];

		while (i < n && points[i] <= k + 1)
			i += 1;

		count += 1;

	}

	printf("%ld\n", count);
	

	return 0;
}