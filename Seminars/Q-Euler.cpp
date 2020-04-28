#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

bool connected(map<int, set<int>> &G, int N) {

	vector<int> mas(N, 0);
	queue<int> Q;
	Q.push(0);
	mas[0] = 1;
	
	while(!(Q.empty())) {
		set<int> tmp = G[Q.front()];
		for(auto elem: tmp) {
			if(mas[elem] == 0)
				Q.push(elem);
		}
		mas[Q.front()] = 1;
		Q.pop();
	}

	for(auto elem: mas)
		if(elem == 0)
			return false;

	return true;

}

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> V(N, 0);
	map<int, set<int>> G;
	for (int i = 0; i < M; ++i) {
		int s, d;
		cin >> s >> d;
		++V[s-1];
		++V[d-1];
		G[s-1].insert(d-1);
		G[d-1].insert(s-1);
	}

	for (int i = 0; i < N; ++i)
		if(V[i]%2) {
			cout << "NO";
			return 0;
		}

	if(connected(G, N))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}