#include <bits/stdc++.h>
using namespace std;

struct point {
	long long x;
	long long y;
	long long z;
	point(long long x = 0, long long y = 0, long long z = 0): x(x), y(y), z(z) {}

	bool operator<(const point &oth) const{
		if(x<oth.x || (x == oth.x && (y < oth.y || (y == oth.y && z < oth.z))))
			return true;
		else
			return false;
	}

	point operator+(const point &A) {
		return point(x + A.x, y + A.y, z + A.z);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<point> vec(N);
	set<point> S;
	point min, max;
	cin >> vec[0].x >> vec[0].y >> vec[0].z;
	min = max = vec[0];
	S.insert(vec[0]);
	for(int i = 1; i < N; ++i) {
		cin >> vec[i].x >> vec[i].y >> vec[i].z;
		S.insert(vec[i]);
		if(vec[i] < min)
			min = vec[i];
		if(max < vec[i])
			max = vec[i];
	}
	point c = max + min;
	for(int i = 0; i < N; ++i) {
		point temp(c.x-vec[i].x, c.y-vec[i].y, c.z-vec[i].z);
		if(S.find(temp) == S.end()){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}