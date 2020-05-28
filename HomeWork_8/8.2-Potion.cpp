#include <iostream>
#include <tuple>
#include <queue>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	short N, M, K, L, answer = -1;
	cin >> N >> M >> K >> L;

	queue<pair<tuple<short, short, short>,short>> Q;
	set<tuple<short, short, short>> S;

	Q.push(make_pair(make_tuple(N, 0, 0),0));

	while(!Q.empty()) {
		pair<tuple<short, short, short>,short> tmp = Q.front();
		Q.pop();

		short currN = get<0>(tmp.first);
		short currM = get<1>(tmp.first);
		short currK = get<2>(tmp.first);
		if (currN == L) {
			answer = tmp.second;
			break;
		}
		if (S.find(tmp.first) != S.end())
			continue;
		else
			S.insert(tmp.first);

		if (M - currM >= currN)
			Q.push(make_pair(make_tuple(0 , currM + currN, currK),tmp.second+1));
		else
			Q.push(make_pair(make_tuple(currN - (M-currM), M, currK),tmp.second+1));			

		if (K - currK >= currN)
			Q.push(make_pair(make_tuple(0 , currM, currK + currN),tmp.second+1));
		else
			Q.push(make_pair(make_tuple(currN - (K-currK), currM, K),tmp.second+1));

		if (N - currN >= currM)
			Q.push(make_pair(make_tuple(currN + currM , 0, currK),tmp.second+1));
		else
			Q.push(make_pair(make_tuple(N, currM - (N-currN), currK),tmp.second+1));

		if (K - currK >= currM)
			Q.push(make_pair(make_tuple(currN, 0, currK + currM),tmp.second+1));
		else
			Q.push(make_pair(make_tuple(currN, currM - (K-currK), K),tmp.second+1));

		if (N - currN >= currK)
			Q.push(make_pair(make_tuple(currN + currK , currM, 0),tmp.second+1));
		else
			Q.push(make_pair(make_tuple(N + currK , currM, currK - (N-currN)),tmp.second+1));

		if (M - currM >= currK)
			Q.push(make_pair(make_tuple(currN, currM + currK, 0),tmp.second+1));
		else
			Q.push(make_pair(make_tuple(currN, M, currK - (M-currM)),tmp.second+1));

	}

	if(Q.empty())
		cout << "OOPS\n";
	else
		cout << answer;

	return 0;
}