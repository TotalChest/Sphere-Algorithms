#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <queue>
using namespace std;

void F(string tbl) {

	unordered_map<string, int> MAP;
	queue<pair<string, int>> Q;

	Q.push(make_pair("123456780",0));

	while(!Q.empty()) {
		pair<string, int> tmp = Q.front();
		Q.pop();

		if (MAP.find(tmp.first) != MAP.end())
			continue;
		else
			MAP[tmp.first] = 1;

		if (tbl == tmp.first) {
			cout << tmp.second;
			return;
		}

		string curr = tmp.first;
		int pos = curr.find("0");
		if (pos + 3 <= 8) {
			swap(curr[pos], curr[pos+3]);
			Q.push(make_pair(curr, tmp.second + 1));
		}
		curr = tmp.first;
		if (pos - 3 >= 0) {
			swap(curr[pos], curr[pos-3]);
			Q.push(make_pair(curr, tmp.second + 1));
		}
		curr = tmp.first;
		if ((pos + 1)%3 != 0) {
			swap(curr[pos], curr[pos+1]);
			Q.push(make_pair(curr, tmp.second + 1));
		}
		curr = tmp.first;
		if (pos%3 != 0) {
			swap(curr[pos], curr[pos-1]);
			Q.push(make_pair(curr, tmp.second + 1));
		}
	}

	cout << -1;
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

	F(tbl);

	return 0;
}