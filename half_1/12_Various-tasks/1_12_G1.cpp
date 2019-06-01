#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c) cout << 1 << endl;
		else if (a == b || b == c || c == a) cout << 2 << endl;
		else cout << 3 << endl;
	}

	return 0;
}