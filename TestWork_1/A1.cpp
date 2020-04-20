#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int n ,m;

	cin >> n >> m;

	vector<int> vec1(n);
	vector<int> vec2(m);

	for(int i = 0; i < n; ++i)
		cin >> vec1[i];

	for(int i = 0; i < m; ++i)
		cin >> vec2[i];


	int count = 0, i = 0, j = 0;


	while(i < n && j < m)
	{
		if(vec1[i] == vec2[j])
		{
			++count;
			++i;
			++j;
		}
		else if(vec1[i] < vec2[j])
			++i;
		else
			++j;
	}

	cout << count << endl;

	return 0;
}