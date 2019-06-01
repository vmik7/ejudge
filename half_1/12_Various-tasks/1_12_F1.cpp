#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int a;
		cin >> a;
		int b = a % 10;
		a /= 100;
		if (a > b) cout << a << endl;
		else if (a < b) cout << b << endl;
		else cout << "=" << endl;
	}

	return 0;
}