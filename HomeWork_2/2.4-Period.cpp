#include <stdio.h>
#include <vector>
#include <unordered_map>

using us = unsigned short;
using ul = unsigned long;

int main()
{

	ul m, n, i = 0, k;
	bool flag = false;

	scanf("%ld %ld", &m, &n);
	printf("0.");
	std::unordered_map<ul, ul> ch; // Числители
	std::vector<us> zn; // Цифры на вывод


	while(1)
	{

		if(ch.find(m) != ch.end())
		{
			k = (*ch.find(m)).second;
			flag = true;
			break;
		}

		ch.insert(std::make_pair(m, i));
		++i;


		zn.push_back((m * 10) / n);

		m = (m * 10) % n;

		if(m == 0)
			break;
	}

	if(flag)
	{
		for(ul i = 0; i < zn.size(); ++i)
		{
			if(i == k)
				printf("(");
			printf("%d", zn[i]);
		}
		printf(")");
	}
	else
		for(us n : zn)
			printf("%d", n);


	return 0;
}