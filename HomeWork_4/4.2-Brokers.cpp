#include <cstdio>

using namespace std;

struct binary_heap
{
	unsigned long long *body;
	unsigned long long bodysize;
	unsigned long long numnodes;

	binary_heap(unsigned long long maxsize)
	{
		body = new unsigned long long[maxsize+1];
		bodysize = maxsize;
		numnodes = 0;
	}

	~binary_heap()
	{
		delete [] body;
	}

	unsigned long long fetchMin()
	{
		return numnodes == 0? 0 : body[1];
	}

	void swap(unsigned long long a, unsigned long long b)
	{
		unsigned long long temp = body[a];
		body[a] = body[b];
		body[b] = temp;
	}

	unsigned long long insert(unsigned long long node)
	{
		if(numnodes >= bodysize)
			return 1;
		body[++numnodes] = node;
		for(unsigned long long i = numnodes; i > 1 && body[i] < body[i/2]; i /= 2)
			swap(i, i/2);
		return 0;
	}

	void heapfy(unsigned long long index)
	{
		for(;;)
		{
			unsigned long long left = index + index;
			unsigned long long right = left + 1;
			unsigned long long min = index;
			if (left <= numnodes && body[left] < body[min])
				min = left;
			if (right <= numnodes && body[right] < body[min])
				min = right;
			if(min == index)
				break;
			swap(min, index);
			index = min;
		}
	}

	unsigned long long get_min()
	{
		unsigned long long temp = fetchMin();
		if(temp != 0)
		{
			body[1] = body[numnodes--];
			heapfy(1);
			return temp;
		}

	}
};


int main()
{
	unsigned long long N, temp;
	unsigned long long a, b;
	double sum;
	scanf("%lld", &N);

	binary_heap BH(N);

	for(unsigned long long i = 0; i < N; ++i)
	{
		scanf("%lld", &temp);
		BH.insert(temp);
	}

	for(unsigned long long i = 0; i < N-1; ++i)
	{
		a = BH.get_min();
		b = BH.get_min();
		sum += a + b;
		BH.insert(a + b);
	}

	printf("%.2f", sum/100);

	return 0;
}