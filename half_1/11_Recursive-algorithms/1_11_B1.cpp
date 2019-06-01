#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

int n;
bool temp[3][3];
bool result[243][243];

void fillFractal(int k, int i = 0, int j = 0);

int main()
{
	//freopen("outp.txt", "w", stdout);
	int k;
	cin >> n >> k;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cin.get() == '.')
				temp[i][j] = true;
		}
		cin.get();
	}

	fillFractal(k);

	for (int i = 0; i < (int)pow(n, k); i++)
	{
		for (int j = 0; j < (int)pow(n, k); j++)
		{
			if (result[i][j])
				cout << ".";
			else
				cout << "*";
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}


void fillFractal(int k, int i, int j)
{
	if (k == 1)
	{
		for (int i1 = 0; i1 < n; i1++)
		{
			for (int j1 = 0; j1 < n; j1++)
			{
				if (temp[i1][j1])
				{
					result[i * n + i1][j * n + j1] = true;
				}
			}
		}
	}
	else
	{
		for (int i1 = 0; i1 < n; i1++)
		{
			for (int j1 = 0; j1 < n; j1++)
			{
				if (temp[i1][j1])
				{
					fillFractal(k - 1, i * n + i1, j * n + j1);
				}
			}
		}
	}
}