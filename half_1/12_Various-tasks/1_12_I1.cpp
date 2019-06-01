#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		long long num;
		cin >> num;

		long long mul = 1;
		int sum = 0;

		while (num > 0)
		{
			mul *= num % 10;
			sum += num % 10;
			num /= 10;
		}
		cout << fixed << setprecision(3) << double(mul) / sum << endl;
	}

	return 0;
}