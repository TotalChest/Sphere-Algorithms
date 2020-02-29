#include <iostream>

unsigned long long pow(unsigned long long X, unsigned long long P, unsigned long long M)
{
	if(P == 0) return (unsigned long long)1;
	if(P%2) return (unsigned long long)((pow(X, P - 1, M) * (X % M)) % M);
	unsigned long long y = pow(X, P/2, M);
	return (unsigned long long)((y*y) % M);
}

int main()
{
	unsigned long long X, P, M;
	std::cin >> X;
	std::cin >> P;
	std::cin >> M;

	std::cout << pow(X, P, M);

	return 0;
}
