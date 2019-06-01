#include <iostream>

using namespace std;

int nums[1001];

int main()
{
	for (int number = 1; number <= 1000; number++)
	{
		int sum = 0;
		for (int factor = 1; factor <= number; factor++)
		{
			if (number % factor == 0)
				sum += factor;
		}
		if (sum <= 1000)
			nums[sum] = number;
	}

	long long test = 1;
	while (true)
	{
		int s;
		cin >> s;
		if (s != 0)
		{
			cout << "Case " << test << ": " << (nums[s] ? nums[s] : -1) << endl;
			test++;
		}
		else break;
	}

	//system("pause");
	return 0;
}