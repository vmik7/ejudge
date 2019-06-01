#include <iostream>

using namespace std;

int a[100][100];

int main()
{
	int n, m;
	cin >> n >> m;

	int val = 1;
	int i = 0;
	int j = 0;

	int i_l = (double)n / 2 + 0.7;
	int j_l = (double)m / 2 + 0.7;

	for (int loops = 0; loops < (i_l < j_l ? i_l : j_l); loops++)
	{
		for (j = loops; j <= m - 1 - loops; j++)
		{
			a[i][j] = val;
			val++;
		}
		j--;

		bool flag = false;
		for (i = loops + 1; i <= n - 1 - loops; i++)
		{
			flag = true;
			a[i][j] = val;
			val++;
		}
		i--;
		if (!flag) break;
		else flag = false;

		for (j = m - 2 - loops; j >= loops; j--)
		{
			flag = true;
			a[i][j] = val;
			val++;
		}
		j++;
		if (!flag) break;
		else flag = false;

		for (i = n - 2 - loops; i >= loops + 1; i--)
		{
			a[i][j] = val;
			val++;
		}
		i++;
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