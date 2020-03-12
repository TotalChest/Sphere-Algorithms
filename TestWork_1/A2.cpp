#include <iostream>
#include <vector>

using namespace std;

int main()
{

	unsigned long long n_f = 1, m, n, n_iter;

	cin >> n >> m;
	vector<bool> mas(n, true);

	for(int i = 2; i <= n; ++i)
		n_f *= i;

	unsigned long long k, c, nn = n_f / n;

	m -= 1;
	n_iter = n;

	while(nn > 0)
	{
		k =  m / nn;

		c = 0;
		for(unsigned long long i = 0; i < n_iter; ++i)
		{
			if(c == k && mas[i] == true)
			{
				cout << i + 1 <<' ';
				mas[i] = false;
				break;
			}
			else if(mas[i])
				++c;
		}

		m %= nn;
		n -= 1;
		if(!n)
			break;
		nn /= n;

	}

	return 0;
}