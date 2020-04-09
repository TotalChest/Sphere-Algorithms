#include <bits/stdc++.h>
using namespace std;

struct Point {
	int num = 0;
	double x = 0.0, y = 0.0;

	bool operator<(const Point &oth) {
		return x < oth.x || x == oth.x && y < oth.y;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	double R;
	cin >> N >> R;
	vector<Point> vec(N);
	vector<pair<int, int>> count(N);
 	for(int i = 0; i < N; ++i) {
		cin >> vec[i].x >> vec[i].y;
		vec[i].num = i;
		count[i].second = i;
 	}
	sort(vec.begin(), vec.end());
	int l = 0, r = 0;
	for(int i = 0; i < N; ++i) {
		while(vec[i].x - vec[l].x > R)
			++l;
		while(r < N && vec[r].x - vec[i].x <= R)
			++r;
		for(int j = l; j < r; ++j)
			if(abs(vec[i].y - vec[j].y) <= R &&
				(vec[i].x - vec[j].x)*(vec[i].x - vec[j].x) + (vec[i].y - vec[j].y)*(vec[i].y - vec[j].y) <= R*R)
				++count[vec[i].num].first;
	}
	sort(count.begin(), count.end(), [](pair<int, int> a, pair<int, int> b){ 
		return a.first > b.first || a.first == b.first && a.second < b.second;
	});
	int k = 0;
	while(k < 10 && k < N)
		cout << count[k].second << ' ' << count[k++].first - 1 << '\n';
}