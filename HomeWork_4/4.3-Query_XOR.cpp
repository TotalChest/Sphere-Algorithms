#include <cstdio>
#include <vector>

using namespace std;

struct IntervalTree
{
	vector<unsigned int> body;
	unsigned int C;

	IntervalTree(unsigned int size)
	{
		int count = 0;
		body.resize(4*size, 0);
		C = 0;
		while(size)
		{
			count += size & 1;
			size >>= 1u;
			++C;
		}
		C = 1u << (count == 1 ? C-1 : C);
	}

	void insert(unsigned int i, unsigned int val)
	{
		body[C + i] = val;
		propagate(i);
	}

	void propagate(unsigned int index)
	{
		index = index + C;
		while(index > 1)
		{
			unsigned int neighbor_index;
			if(index & 1)
				neighbor_index = index - 1;
			else
				neighbor_index = index + 1;
			unsigned int parent = body[index] ^ body[neighbor_index];
			body[index/2] = parent;
			index /= 2;
		}
	}

	unsigned int XOR(unsigned l, unsigned int r)
	{
		unsigned int Res = 0;
		if (l & 1u) Res = Res ^ body[l++];
		if (!(r & 1u)) Res = Res ^ body[r--];
		if (r > l) Res = Res ^ XOR(l/2,r/2);
		return Res;
	}

	void print()
	{
		for(auto out : body)
			printf("%d\n", out); 
	}

};

int main()
{
	unsigned int N, M, temp;

	scanf("%d %d", &N, &M);

	IntervalTree IT(N);

	for(unsigned int i = 0; i < N; ++i)
	{
		scanf("%d", &temp);
		IT.insert(i, temp);
	}
	
	for(unsigned int i = 0; i < M; ++i)
	{
		unsigned int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		if(op == 1){
			op = IT.XOR(l + IT.C, r + IT.C);
			printf("%d\n", op);
		}
		else
			IT.insert(l, r);
	}
	


	return 0;
}