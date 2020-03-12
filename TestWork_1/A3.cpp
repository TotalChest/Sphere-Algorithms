#include <iostream>
#include <vector>

using namespace std;


auto mult(vector<vector<unsigned long long>> & mat1, vector<vector<unsigned long long>> & mat2, size_t m)
{
	auto dot = mat1;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			dot[i][j] = ((mat1[i][0] * mat2[0][j]) % m + (mat1[i][1] * mat2[1][j]) % m) % m;

	return dot;
}

auto pow_mat(vector<vector<unsigned long long>> & mat, size_t n, size_t m)
{
	if(n == 1)
		return mat;

	if(n & 1) {

		auto b = pow_mat(mat, n - 1, m);
		return mult(mat, b, m);
	}

	auto b = pow_mat(mat, n/2, m);
	return mult(b, b, m);
}


int main()
{

	size_t a0 ,a1, n, m;

	cin >> a0 >> a1 >> n >> m;

	vector<vector<unsigned long long>> mat;

	mat.push_back(vector<unsigned long long>() = {0, 1});
	mat.push_back(vector<unsigned long long>() = {1, 1});

	if(n == 0)
		cout << a0 << endl;

	auto mat2 = pow_mat(mat, n, m);

	cout << ((mat2[0][0] * a0) % m + (mat2[0][1] * a1) % m) % m << endl;  

	return 0;
}