#include <cstdio>
#include <vector>

using namespace std;

const unsigned int NN = 65536;

union double_word{
	unsigned int a;
	unsigned short c[2];
};

std::vector<unsigned short> mas[NN];

int main()
{
	unsigned int N, K, M, L;
	unsigned long long sum = 0, totalcount = 0;

	scanf("%d %d %d %d", &N, &K, &M, &L);

	double_word temp;
	
	temp.a = K;
	mas[temp.c[1]].push_back(temp.c[0]);

	for (unsigned int i = 0; i < N-1; ++i)
	{
		temp.a = (unsigned int)((temp.a*(unsigned long long)M)&0xFFFFFFFFU)%L;
		mas[temp.c[1]].push_back(temp.c[0]);
	}

	for (unsigned int i = 0; i < NN; ++i)
		if(!mas[i].empty())
		{
			vector<unsigned int> count(NN, 0);
			for(unsigned short elem: mas[i])
				++count[elem];
			for (unsigned int j = 0; j < NN; ++j)
				if(count[j])
				{
					temp.c[1] = i;
					temp.c[0] = j;
					sum += (((count[j] - (totalcount & 1u)) + 1u) >> 1u) * temp.a;
					totalcount += count[j];
				}
		}


	printf("%llu ", sum % L);

	return 0;
}