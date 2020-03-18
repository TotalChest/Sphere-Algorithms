#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const size_t COUNT = 26;

int main()
{
	vector<pair<size_t, char>> frequency(COUNT);

	for(size_t i = 0; i < COUNT; ++i)
	{
		frequency[i].first = 0;
		frequency[i].second = (char)('A' + i);
	}

	string str;
	cin >> str;

	for(size_t i = 0; i < str.length(); ++i)
		++frequency[str[i] - 'A'].first;

	sort(frequency.begin(), frequency.end(), [](pair<size_t, char> a, pair<size_t, char> b) -> bool
		{
			if(a.first > b.first)
				return true;
			else if(a.first < b.first)
				return false;
			else
				return a.second < b.second;
		});

	for(size_t i = 0; i < COUNT; ++i)
		if(frequency[i].first)
			cout << frequency[i].second << ' ' << frequency[i].first << endl;

	return 0;
}