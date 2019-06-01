#include <iostream>

using namespace std;

void rWrite(int n, bool is_first = true)
{
	int val;
	cin >> val;
	if (n != 1) rWrite(n - 1, false);
	cout << val << (is_first ? "\n" : " ");
}

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		rWrite(n);
	}
	return 0;
}