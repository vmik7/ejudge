#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int k, n;
		cin >> k >> n;
		int person = 1;
		while (n > k)
		{
			person++;
			n -= k;
		}
		cout << person << " " << n << endl;
	}
	return 0;
}