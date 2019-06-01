#include <iostream>

using namespace std;

int a[100][100];

int main()
{
	int n, m;
	cin >> n >> m;

	int val = 1;

	for (int k = n + m - 2; k >= 0; k--)
	{
		for (int i = n - 1, j = k; i >= 0 && j >= 0; i--, j--)
		{
			if (j < m)
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