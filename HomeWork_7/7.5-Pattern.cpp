#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char text[705], pattern[705];
	int t_len = 0, p_len = 0;
	scanf("%s %s", text, pattern);
	t_len = strlen(text);
	p_len = strlen(pattern);

	int t_pos = 0, p_pos = 0, index_p = -1, index_t = -1; 

	while(t_pos < t_len)
		if((text[t_pos] == pattern[p_pos] || pattern[p_pos] == '?') && p_pos < p_len){
			++t_pos;
			++p_pos;
		}
		else if(p_pos < p_len && pattern[p_pos] == '*') {
			index_t = t_pos;
			index_p = p_pos;
			++p_pos;
		}
		else if(index_p != -1) {
			t_pos = index_t + 1;
			p_pos = index_p + 1;
			++index_t;
		}
		else{
			printf("NO\n");
			return 0;
		}
	while(p_pos < p_len && pattern[p_pos] == '*')
		++p_pos;

	if(p_pos == p_len) {
		printf("YES\n");
		return 0;
	}

	printf("NO\n");
	return 0;
}