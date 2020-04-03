#include <stdio.h>
#include <vector>
#include <string>
#include "priority_queue.h"
#include <cassert>

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
		if(freq[c] == 0) continue;
		tree *t = new tree();
		t->freq = freq[c];
		t->code = c;
		pqnode p;
		p.priority = (int)freq[c];
		p.value = (void*)t;
		pq.insert(p);
	}

#if 0
	//debug
	pq.print();
	while(pq.size() > 0)
	{
		auto p = pq.fetchMin();
		printf("p.priority=%d\n", p.priority);
		pq.removeMin();
	}
#endif
	while(pq.size() > 1)
	{
		auto left = pq.fetchMin();
		pq.removeMin();
		auto right = pq.fetchMin();
		pq.removeMin();
		pqnode sum;
		sum.priority = left.priority + right.priority;
		tree* t = new tree();
		t->freq = sum.priority;
		t->children[0] = (tree *)left.value;
		t->children[1] = (tree *)right.value;
		sum.value = (void *)t;
	}
	auto root = pq.fetchMin();
	return root;
}

void walk(tree const *root, string code, vector<string> &repr)
{
	for(int i = 0; i < 2; ++i)
		if(root->children[i] != nullptr)
			walk(root->children[i], code + to_string(i), repr);
	if (root->code >= 0)
		repr[root->code] = code;
}

void walk_free(tree *root)
{
	for(int i = 0; i < 2; ++i)
		if(root->children[i] != nullptr)
			walk(root->children[i])
	delete root;
}

void fill_repr(tree const *root, vector<string> &repr)
{
	walk(root, "", repr);
}

void encode()
{

	vector<size_t> freq(257);
	FILE *in = fopen("input","rb");
	if (in == nullptr) {printf("No input file\n"); return;}
	for(int c = fgetc(in); c!= EOF; c = fgetc(in))
		freq[c]++;
	freq[256]++;
	rewind(in);
	FILE *out = fopen("output", "w");
	auto root = build_tree(freq);
	vector<string> repr(257);
	fill_repr(root, repr);
	walk_free(root);
	for(size_t i = 0; i < repr; ++i)
		if(!repr[i].empty())
			fprintf(out, "%zu %s\n", i, repr[i].c_str());
	for(int c = fgetc(in); c != EOF; c = fgetc(in))
		fprintf(out, repr[c].c_str());
	fprintf(out, repr[256].c_str());

	fclose(out);
	fclose(in);
}

void add_code(tree * &root, int code, const string repr)
{
	if(root == nullptr) root = new tree();
	auto curr = root;
	for(auto c: repr)
	{
		assert(c == '0' || c == '1');
		if(curr->children[c-'0'] == nullptr)
			curr->children[c-'0'] = new tree();
		curr = root->children[c-'0'];
	}
	curr->code = code;
}

void decode()
{
	FILE *in = fopen("output", "r");
	if(in == nullptr) {printf("No input file\n"); return;}
	char buf[256];
	tree *t{};
	for(;;)
	{
		fgets(buf, sizeof buf, in);
		int code;
		char repr[40];
		sscanf(buf, "%d %s", &code, repr);
		printf("%d %s\n", code, repr);
		add_code(t, code, repr);
		if(code == 256) break;
	}
	auto curr = t;
	for(;;)
	{
		int c = fgetc(in);
		assert(c == '0' || c == '1');
		c -= '0';
		curr = curr->children[c];
		if(curr->code == 256) break;
		if(curr->code >= 0)
		{
			putchar(curr->code);
			curr = t;
		}
	}
}

int main()
{
	encode();
	decode();
	return 0;
}