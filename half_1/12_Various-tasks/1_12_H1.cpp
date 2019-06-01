#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int c;
		cin >> c;
		int sum = 0;
		int count = 0;
		while (c--)
		{
			int num;
			cin >> num;
			if (num > 0 && num % 6 == 0)
			{
				count++;
				sum += num;
			}
		}
		cout << count << " " << sum << endl;
	}

	return 0;
}