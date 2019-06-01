#include <iostream>
#include <vector>

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


	int max_c = a[0][0];
	for (int j = 1; j < m; j++)
	{
		if (a[0][j] > max_c) max_c = a[0][j];
	}
	int min = max_c;

	for (int i = 1; i < n; i++)
	{
		max_c = a[i][0];
		for (int j = 1; j < m; j++)
		{
			if (a[i][j] > max_c) max_c = a[i][j];
		}
		if (max_c < min) min = max_c;
	}

	cout << min << endl;

	//system("pause");
	return 0;
}