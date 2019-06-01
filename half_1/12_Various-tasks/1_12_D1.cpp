#include <iostream>

using namespace std;

long long fib[45];

int main()
{
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < 45; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << fib[n] << endl;
	}

	return 0;
}