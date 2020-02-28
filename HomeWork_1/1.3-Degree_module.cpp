#include <iostream>

long pow(long long X, long long P, long M)
{
	if(P == 0) return (long)1;
	if(P%2) return (long)(pow(X, P - 1, M)*X) % M;
	long y = pow(X, P/2, M);
	return y*y % M;
}

int main()
{
	long long X, P, c = 1;
	long M;
	std::cin >> X;
	std::cin >> P;
	std::cin >> M;

	std::cout << pow(X, P, M);

	return 0;
}