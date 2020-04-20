#include <cstdio>
#include <vector>

using namespace std;

long long merge_sort(vector<long> &vec, long l, long r)
{
	if(r - l == 1)
		return 0;

	long long count = 0;
	long mid = (r + l) / 2;
	count += merge_sort(vec, l, mid);
	count += merge_sort(vec, mid, r);
	
	vector<long> tmp(r - l);

	long a = l, b = mid;

	for(long i = 0; i < r - l; ++i)
	{
		if(a < mid && b < r)
			if(vec[a] <= vec[b])
				tmp[i] = vec[a++];
			else
			{
				count += mid - a;
				tmp[i] = vec[b++];
			}
		else
			if(a == mid)
				tmp[i] = vec[b++];
			else
				tmp[i] = vec[a++];
	}


	copy(tmp.begin(), tmp.end(), vec.begin() + l);

	return count;

}


int main()
{
	long N;
	scanf("%ld", &N);
	vector<long> vec(N);

	for(long i = 0; i < N; ++i)
		scanf("%ld", &vec[i]);

	long long count = merge_sort(vec, 0l, N);

	printf("%lld\n", count);

 	return 0;
}