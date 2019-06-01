#include <iostream>
#include <algorithm>

using namespace std;

int a[100][100];

int main()
{
	int n, m, min, min_j, max, max_j;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (i == 0 && j == 0)
			{
				min = a[i][j];
				min_j = j;
				max = a[i][j];
				max_j = j;
			}
			else if (a[i][j] < min)
			{
				min = a[i][j];
				min_j = j;
			}
			else if (a[i][j] > max)
			{
				max = a[i][j];
				max_j = j;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		swap(a[i][min_j], a[i][max_j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j];
			if (j != m - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}