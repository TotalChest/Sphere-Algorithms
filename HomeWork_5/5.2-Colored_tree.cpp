#include <iostream>
#include <string>

using namespace std;

int check(string &str, int &i, bool black)
{
	int n = 0;
	++i;
	switch(str[i])
	{
	case 'g':
		++i;
		while(str[i] == ',')
			n += check(str, ++i, black);
		++i;
		break;
	case 'b':
		++i;
		while(str[i] == ',')
			n += check(str, ++i, true);
		++i;
		break;
	case 'w':
		if(black)
			n++;
		++i;
		while(str[i] == ',')
			n += check(str, ++i, black);
		++i;
		break;
	}
	return n;
}

int main()
{
	string str;
	cin >> str;
	int i = 0;
	cout << check(str, i, false);
	return 0;
}