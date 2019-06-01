#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int a, n;
		long long sum = 1;
		int sign = 1;
		cin >> a >> n;
		if (n % 2) sign = -1;
		while (n > 0)
		{
			sum += sign * a * n;
			sign *= -1;
			n--;
		}
		cout << sum << endl;
	}
	//system("pause");
	return 0;
}