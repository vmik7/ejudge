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

	bool flag = true;
	for (int i = 0; i < m && flag; i++)
	{
		flag = false;
		for (int j = 0; j < m - 1 - i; j++)
		{
			if (a[n - 1][j] > a[n - 1][j + 1])
			{
				flag = true;
				for (int col = 0; col < n; col++)
				{
					int t = a[col][j];
					a[col][j] = a[col][j + 1];
					a[col][j + 1] = t;
				}
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