#include <iostream>

using namespace std;

class Mat
{

	size_t a00;
	size_t a01;
	size_t a10;
	size_t a11;
	static size_t m;

public:

	Mat(size_t a00 = 0, size_t a01 = 1, size_t a10 = 1, size_t a11 = 1): a00(a00), a01(a01), a10(a10), a11(a11) {};

	size_t get_a00()
	{
		return a00;  
	}

	static void set_m(size_t m_)
	{
		m = m_; 
		return;  
	}

	Mat operator*(Mat & B)
	{
		Mat tmp(0, 0, 0, 0);
		tmp.a00 = ((a00 * B.a00) % m + (a01 * B.a10) % m) % m;
		tmp.a01 = ((a00 * B.a01) % m + (a01 * B.a11) % m) % m;
		tmp.a10 = ((a10 * B.a00) % m + (a11 * B.a10) % m) % m;
		tmp.a11 = ((a10 * B.a01) % m + (a11 * B.a11) % m) % m;

		return tmp;
	}

	Mat pow(size_t n)
	{

		Mat tmp = *(this);

		if(n == 1)
			return tmp;

		if(n & 1)
		{
			Mat tmp2 = tmp.pow(n - 1);
			return tmp * tmp2;
		}

		tmp = tmp.pow(n / 2);
		return tmp * tmp;
	}

};

size_t Mat::m = 1000;

int main()
{

	size_t a0 ,a1, n, m;

	cin >> a0 >> a1 >> n >> m;

	Mat::set_m(m);

	if(n == 0){
		cout << a0 << endl;
		return 0;
	}

	Mat mat1, mat2(a0, 0, a1, 0), mat3 = mat1.pow(n);

	mat1 = mat3 * mat2;

	cout << mat1.get_a00() << endl;  

	return 0;
}