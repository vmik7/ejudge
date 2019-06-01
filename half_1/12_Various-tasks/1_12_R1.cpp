#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (gcd(n, m) == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}