#include <iostream>

using namespace std;

long long power_mod(int a, int n, int m);

int main()
{
	int a, n, m;
	while (cin >> a >> n >> m) cout << power_mod(a, n, m) << endl;

	//system("pause");
	return 0;
}


long long power_mod(int a, int n, int m)
{
	long long p = 1;
	while (n)
	{
		if (n % 2) p = (p * a) % m;
		a = ((long long)a * a) % m;
		n /= 2;
	}
	return p;
}