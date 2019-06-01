#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		long long a, k;
		cin >> a >> k;

		long long result = 1;

		while (k > 0)
		{
			if (k % 2 == 0)
			{
				k /= 2;
				a *= a;
			}
			result *= a;
			k--;
		}
		cout << result << endl;
	}

	return 0;
}