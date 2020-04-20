#include <iostream>
#include <vector>


using namespace std;

int main()
{

	size_t n, m, a;

	cin >> n >> m;
	vector<size_t> mas(n);

	for(size_t i = 0; i < n; ++i)
		cin >> mas[i];

	for(size_t i = 0; i < m; ++i)
	{
		cin >> a;
		size_t sum = 0, l = 0, r = 0;

		bool flag = false;

		while(l < n && r < n)
		{
			if(sum == a)
			{
				cout << l + 1 << ' ' << r + 1 << endl;
				flag = true;
				break;
			}

			if(sum < a)
				sum += mas[r++];
			else if(sum > a)
				sum -= mas[l++];

		}

		if(!flag)
			cout << "Not found" << endl;

	}

	return 0;
}