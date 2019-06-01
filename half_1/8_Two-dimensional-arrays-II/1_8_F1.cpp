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

	cout << m << " " << n << endl;

	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1; i > 0; i--)
		{
			cout << a[i][j] << " ";
		}
		cout << a[0][j] << endl;
	}

	//system("pause");
	return 0;
}