#include <iostream>
#include <stdio.h>
#include <unordered_map>
using namespace std;

void set_rang(string curr, int rang, unordered_map<string, int> &MAP) {
	if (MAP.find(curr) != MAP.end())
		if (rang < MAP[curr])
			MAP[curr] = rang;
		else
			return;
	else
		MAP[curr] = rang;

	if (rang > 32)
		return;

	int pos = curr.find("0");

	string tmp = curr;
	if (pos + 3 <= 8) {
		swap(tmp[pos], tmp[pos+3]);
		set_rang(tmp, rang + 1, MAP);
	}
	tmp = curr;
	if (pos - 3 >= 0) {
		swap(tmp[pos], tmp[pos-3]);
		set_rang(tmp, rang + 1, MAP);
	}
	tmp = curr;
	if ((pos + 1)%3 != 0) {
		swap(tmp[pos], tmp[pos+1]);
		set_rang(tmp, rang + 1, MAP);
	}
	tmp = curr;
	if (pos%3 != 0) {
		swap(tmp[pos], tmp[pos-1]);
		set_rang(tmp, rang + 1, MAP);
	}

	return;
}

int main() {

	string tbl("");
	for(int i = 0; i < 11; ++i){
		char d = getchar();
		if(d == '\n')
			continue;
		if(d == ' ')	
			tbl += '0';
		else
			tbl += d;
	}
	unordered_map<string, int> MAP;

	set_rang("123456780", 0, MAP);

	if (MAP.find(tbl) != MAP.end())
		cout << MAP[tbl];
	else
		cout << -1;

	return 0;
}