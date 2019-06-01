#include <iostream>

using namespace std;

int a[100][100];

int main()
{
	int n, m;
	cin >> n >> m;

	int val = 1;

	for (int k = 0; k < n + m - 1; k++)
	{
		for (int i = k, j = 0; i >= 0 && j <= k; i--, j++)
		{
			if (i < n && j < m)
			{
				a[i][j] = val;
				val++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << a[i][m - 1] << endl;
	}

	//system("pause");
	return 0;
}