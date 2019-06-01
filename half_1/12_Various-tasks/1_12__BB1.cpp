#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n, temp, sumA = 0, sumB = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> temp;
				if (j == i)			sumA += temp;
				if (j == n - 1 - i)	sumB += temp;
			}
		}
		cout << sumA << " " << sumB << endl;
	}
	//system("pause");
	return 0;
}