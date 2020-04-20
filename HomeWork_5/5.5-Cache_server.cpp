#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N, M, count = 0;
	scanf("%d %d", &N, &M);
	unordered_map<unsigned long long, set<int>> interval; 
	unordered_set<unsigned long long> cache;
	vector<unsigned long long> vec(M);
	vector< pair<int, unsigned long long> > BH;

	for(int i = 0; i < M; ++i) {
		unsigned long long tmp; 
		scanf("%llu", &tmp);
		interval[tmp].insert(i);
		vec[i] = tmp;
	}

	int priority;
	unsigned long long val = 0;

	for(int i = 0; i < M; ++i) {
		for(int d = 0; d < BH.size(); ++d)
			BH[d].first -= 1;
		interval[vec[i]].erase(interval[vec[i]].begin());
		if(cache.find(vec[i]) == cache.end()) {
			++count;
			if(cache.size() < N) {
				cache.insert(vec[i]);
				if(interval[vec[i]].empty())
					priority = 1000000;
				else
					priority = *(interval[vec[i]].begin())-i;
				BH.push_back({priority, vec[i]});
			}
			else {
				int num = 0, pr = BH[0].first;
				vector< pair<int, unsigned long long> >::iterator it = BH.begin(), max_it = BH.begin();
				for(int d = 1; d < BH.size(); ++d) {
					it++;
					if(BH[d].first > pr) {
						num = d;
						pr = BH[d].first;
						max_it = it;
					}
				}
				unsigned long long k = BH[num].second;
				BH.erase(max_it);
				cache.erase(k);
				cache.insert(vec[i]);	
				if(interval[vec[i]].empty())
					priority = 1000000;
				else
					priority = *(interval[vec[i]].begin())-i;
				BH.push_back({priority, vec[i]});
			}
		}
		else{
			for(int d = 0; d < BH.size(); ++d)
				if(BH[d].second == vec[i]){
					if(interval[vec[i]].empty())
						priority = 1000000;
					else
						priority = *(interval[vec[i]].begin())-i;
					BH[d].first = priority;
					break;
				}
		}	
	}

	printf("%d", count);

	return 0;
}