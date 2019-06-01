#include <iostream>

using namespace std;

int a[100][100];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	long long max = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		max += a[i][index];
	}

	for (int j = 1; j < m; j++)
	{
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += a[i][j];
		}
		if (sum > max)
		{
			index = j;
			max = sum;
		}
	}

	cout << index << " " << max << endl;

	//system("pause");
	return 0;
}