#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(){
	int M, N;
	cin >> M >> N;
	map<int, vector<string>> mas;
	for(int i = 0; i < N; ++i)
	{
		string name;
		int points;
		cin >> name >> points;
		mas[points].push_back(name);
	}

	set<string> S;

	for(auto i = --mas.end(); i != mas.begin(); --i)
		for(auto out: i->second)
		{
			if(S.find(out) == S.end())
				cout << out << "\n";
			S.insert(out);
		}

	for(auto out: mas.begin()->second)
	{
		if(S.find(out) == S.end())
			cout << out << "\n";
		S.insert(out);
	}

	return 0;
}