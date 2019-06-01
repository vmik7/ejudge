#include <iostream>

using namespace std;

int main()
{
	int n;
	long m, k;
	cin >> n >> m >> k;

	unsigned long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		long temp;
		cin >> temp;

		if ((temp % m) == k)
		{
			sum += temp;
			cout << temp << endl;
		}
	}
	cout << sum << endl;

	//system("pause");
	return 0;
}