#include <iostream>
#include <string>

using namespace std;

long long fib_num[46];

void fib(int n);

char getFibChar(int n, long long k);

int main()
{
	fib(45);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long k;
		cin >> n >> k;
		cout << getFibChar(n, k) << endl;
	}

	//system("pause");
	return 0;
}


void fib(int n)
{
	fib_num[0] = 1;
	fib_num[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fib_num[i] = fib_num[i - 1] + fib_num[i - 2];
	}
}


char getFibChar(int n, long long k)
{
	if (n == 0) return 'a';
	if (n == 1) return 'b';
	if (n == 2)
	{
		if (k == 1) return 'a';
		else return 'b';
	}
	if (n == 3)
	{
		if (k == 1 || k == 3) return 'b';
		else return 'a';
	}
	if (k > fib_num[n - 2]) k -= fib_num[n - 3];
	if (k > fib_num[n - 2]) k -= fib_num[n - 2];
	return getFibChar(n - 2, k);
}