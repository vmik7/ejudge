#include <iostream>

using namespace std;

int n, p;

bool fill(char ** arr, int col = 1);

int main()
{
	cin >> n >> p;
	char ** result = new char *[n];
	for (int i = 0; i < n; i++)
	{
		result[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
			result[i][j] = '.';
		}
	}

	result[p - 1][0] = 'Q';

	fill(result);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}


bool fill(char ** arr, int col)
{
	for (int a = 0; a < n; a++)
	{
		bool is_possible = true;
		for (int j = 1; j <= col; j++)
		{
			if (arr[a][col - j] == 'Q' || a - j >= 0 && arr[a - j][col - j] == 'Q' || a + j < n && arr[a + j][col - j] == 'Q')
			{
				is_possible = false;
				break;
			}
		}
		if (is_possible)
		{
			arr[a][col] = 'Q';
			if (col == n - 1) return true;
			else if (fill(arr, col + 1)) return true;
			else arr[a][col] = '.';
		}
	}
	return false;
}