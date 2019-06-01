#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int mat[100][100];

int main()
{
	freopen("Z.inp", "r", stdin);
	freopen("Z.out", "w", stdout);
	long long t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int num = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = num;
				cout << mat[i][j] << (j != m - 1 ? " " : "\n");
				num++;
			}
		}
	}
	//system("pause");
	return 0;
}