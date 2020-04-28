#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char text[705], pattern[705];
int t_len = 0, p_len = 0;

bool stars(int p) {
	for(int i = p; i < p_len; ++i)
		if(pattern[i] != '*')
			return false;
	return true;
}

bool Pat(int t, int p) {
	if(t  == t_len && (p == p_len || stars(p)))
		return true;
	if(p == p_len || t == t_len)
		return false;

	if(pattern[p] == '*') {
		while(pattern[p] == '*' && p < p_len)
			++p;
		if(p == p_len)
			return true;
		for (int i = 0; i < t_len-t; ++i)
			if(Pat(t+i, p))
				return true;
		return false;
	}

	if(pattern[p] == '?')
		return Pat(t+1, p+1);
	

	if(Pat(t+1, p+1)) {
		if(text[t] == pattern[p])
			return true;
		else
			return false;
	}

	return false;
}

int main() {
	scanf("%s %s", text, pattern);
	t_len = strlen(text);
	p_len = strlen(pattern);

	if(Pat(0, 0))
		printf("YES");
	else
		printf("NO");

	return 0;
}