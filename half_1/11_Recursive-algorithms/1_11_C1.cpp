#include <iostream>

using namespace std;

long long c[40][40];
long long func(long long m, long long n);

int main()
{
	int n, m;
	cin >> n >> m;
	cout << func(m, n) << endl;

	//system("pause");
	return 0;
}


long long func(long long m, long long n)
{
	if (c[m][n] > 0)
		return c[m][n];
	if (m == 0 || m == n)
		return 1;
	c[m][n] = func(m - 1, n - 1) + func(m, n - 1);
	return c[m][n];
}