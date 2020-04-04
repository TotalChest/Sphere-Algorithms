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
	set<pair<int, unsigned long long>> BH;

	for(int i = 0; i < M; ++i) {
		unsigned long long tmp; 
		scanf("%llu", &tmp);
		interval[tmp].insert(i);
		vec[i] = tmp;
	}

	int priority;
	unsigned long long val = 0;

	for(int i = 0; i < M; ++i) {
		for(auto it = BH.begin(); it != BH.end(); ++it) {
			priority = (*it).first;
			val = (*it).second;
			BH.erase(it);
			BH.insert({priority-1, val});
		}
		interval[vec[i]].erase(interval[vec[i]].begin());
		if(cache.find(vec[i]) == cache.end()) {
			++count;
			if(cache.size() < N) {
				cache.insert(vec[i]);
				if(interval[vec[i]].empty())
					priority = 1000000;
				else
					priority = *(interval[vec[i]].begin())-i;
				BH.insert({priority, vec[i]});
			}
			else {
				unsigned long long k = (*(--BH.end())).second;
				BH.erase(--BH.end());
				cache.erase(k);
				cache.insert(vec[i]);	
				if(interval[vec[i]].empty())
					priority = 1000000;
				else
					priority = *(interval[vec[i]].begin())-i;
				BH.insert({priority, vec[i]});
			}
		}
		else{
			for(auto it = BH.begin(); it != BH.end(); ++it)
				if((*it).second == vec[i]){
					BH.erase(it);
					if(interval[vec[i]].empty())
						priority = 1000000;
					else
						priority = *(interval[vec[i]].begin())-i;
					BH.insert({priority, vec[i]});
				}
		}	
	}


	printf("%d", count);

	return 0;
}