#include <iostream>


int main(void)
{
	int n, cur_1 = 0, cur_2 = 0, flag = 1;
	unsigned long count = 0, temp;
	std::cin >> n;

	unsigned long mas[n];
	for (int i = 0; i < n; i++)
		std::cin >> mas[i];

	std::cin >> temp;
	for (int i = 0; i < 2*n; i++)
	{	
		if(cur_1 < n && cur_2 < n)
		{
			if (temp < mas[cur_1])
			{
				if(flag == 1)
				{
					count += temp;
					flag = 0;
				}
				else
					flag = 1;
				cur_2++;
				if(cur_2 < n)
					std::cin >> temp;
			}
			else
			{	
				if(flag == 1)
				{
					count += mas[cur_1];
					flag = 0;
				}
				else
					flag = 1;
				cur_1++;
			} 
		}
		else
		{
			if(cur_2 < n)
			{
				if(flag == 1)
				{
					count += temp;
					flag = 0;
				}
				else
					flag = 1;
				cur_2++;
				if(cur_2 < n)
					std::cin >> temp;
			}
			else
			{
				if(flag == 1)
				{
					count += mas[cur_1];
					flag = 0;
				}
				else
					flag = 1;
				cur_1++;
			}
		}
	}

	std::cout << count%1000000000;


	return 0;
}
