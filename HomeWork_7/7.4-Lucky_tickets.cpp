#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct BigInt {
	vector<unsigned short> number;

	BigInt(unsigned int n = 0) {
		number.resize(1);
		number[0] = n;
	}

	void operator += (BigInt oth) {
		unsigned int shift = 0, i = 0, tmp = 0;
		int len = oth.number.size();
		while(i < len) {
			if(i >= number.size())
				tmp = oth.number[i] + shift;
			else
				tmp = number[i] + oth.number[i] + shift;
			if(tmp > 9) {
				if(i >= number.size())
					number.push_back(tmp - 10);
				else
					number[i] = tmp - 10;
				shift = 1;
			}
			else {
				if(i >= number.size())
					number.push_back(tmp);
				else
					number[i] = tmp;
				shift = 0;
			}
			++i;
		}
		while(i < number.size()) {
			tmp = number[i] + shift;
			if(tmp > 9) {
				shift = 1;
				number[i] = tmp - 10;
			}
			else {
				number[i] = tmp;
				shift = 0;
			}
			++i;
		}
		if(shift)
			number.push_back(1);
	}

	friend ostream& operator<<(ostream &out, BigInt &A) {
		for(int i = A.number.size()-1; i >= 0; --i)
			out << A.number[i];
		out << endl;
		return out;
	}
};

BigInt F(int N, int SUM, int M, map<pair<int, int>, BigInt> &MAP) {
	if (N == 1 && (SUM >= M || SUM < 0))
		return BigInt(0);
	if (N == 1 && (SUM >= 0 || SUM < M))
		return BigInt(1);
	if(MAP.find(make_pair(N, SUM)) != MAP.end())
		return MAP[make_pair(N, SUM)];
	BigInt acc(0);
	for(int i = 0; i < M; ++i)
		acc += F(N-1, SUM - i, M, MAP);
	MAP[make_pair(N, SUM)] = acc;
	return acc;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	map<pair<int, int>, BigInt> MAP;
	BigInt res = F(N, (M-1)*N/2, M, MAP); 
	cout << res;

	return 0;
}