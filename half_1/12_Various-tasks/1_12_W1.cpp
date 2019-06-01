#include <iostream>

using namespace std;

int a[1000];

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		bool flag = true;
		for (int i = 0; i < n - 1 && flag; i++)
		{
			flag = false;
			for (int j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
					flag = true;
				}
			}
		}
		for (int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? "\n" : " ");
	}
	return 0;
}