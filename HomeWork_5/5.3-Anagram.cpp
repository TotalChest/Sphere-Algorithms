#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int main()
{
	char str[10002];
	int N;
	set<vector<unsigned short>> S;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		vector<unsigned short> freq(26, 0);
		scanf("%s", str);
		int len = strlen(str);
		for(int j = 0; j < len; ++j)
			freq[str[j]-'A']++;
		S.insert(freq);
	}
	printf("%ld\n", S.size());
	return 0;
}