#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Matrix
{
	short N;
	short M;
	vector< vector<size_t> > mat;

public:

	Matrix(short N, short M): N(N), M(M)
	{
		for(size_t i = 0; i < N; ++i)
		{
			mat.push_back(vector<size_t> (M));
			for(size_t j = 0; j < M; ++j)
				cin >> mat[i][j];
		}
	}

	void msort()
	{
		size_t min = (1u<<31) -1;
		short min_i = 0, min_j = 0;

		for(size_t i = 0; i < N; ++i)
		{
			for(size_t j = 0; j < M; ++j)
				if(mat[i][j] < min)
				{
					min = mat[i][j];
					min_i = i;
					min_j = j;
				}
		}

		vector<pair<size_t, short>> seq_i(N);
		vector<pair<size_t, short>> seq_j(M);

		for(short i = 0; i < N; ++i)
			seq_i[i] = {mat[i][min_j], i};

		for(short j = 0; j < M; ++j)
			seq_j[j] = {mat[min_i][j], j};

		sort(seq_j.begin(), seq_j.end());
		sort(seq_i.begin(), seq_i.end());

		for(size_t i = 0; i < N; ++i)
		{
			for(size_t j = 0; j < M; ++j)
				cout << mat[seq_i[i].second][seq_j[j].second] << ' ';
			cout << '\n';
		}

	}


};

int main()
{
	short N, M;
	cin >> N >> M;

	Matrix A(N, M);

	A.msort();

	return 0;
}