#include <stdio.h>
#include <vector>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct tree
{
	size_t freq;
	tree *children[2]{}; // Такая инициализация только в с++11
	int code{-1};
};

tree* build_tree(vector<size_t> const &freq)
{
	size_t non_zeroes = 0;
	for(auto q: freq)
		non_zeroes += q != 0;
	priority_queue pq(non_zeroes);
	for(size_t c = 0; c < freq.size(); c++)
	{
		if(freq[c] = 0) continue;
		tree *t = new tree();
		t->freq = freq[c];
		t->code = c;
		pqnode p;
		p.priority = (int)freq[c];
		p.value = (void*)t;
		pq.insert(p);
	}

	//debug
	while(pq.size() > 0)
	{
		auto p = pq,fetchMin();
		printf("p.pryority=%d\n", p.priority);
	}
}
int main()
{

	vector<size_t> freq(256);
	FILE *in = fopen("input","rb");
	if (in == nulptr) {printf("no input file\n"); return 0;}
	for(int c = fgetc(in); c!= EOF; c = fgetc(in))
		freq[c]++;
	rewind(in);
	auto root = build_tree(freq);

	fclose(in);




	return 0;
}