#include <iostream>

using namespace std;

long long fact(int n)
{
	if (n <= 1) return n;
	else return fact(n - 1) * n;
}

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << fact(n) << endl;
	}
	//system("pause");
	return 0;
}