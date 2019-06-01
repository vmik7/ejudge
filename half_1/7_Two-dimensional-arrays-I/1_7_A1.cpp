#include <iostream>
#include <vector>

using namespace std;

int a[1000][1000];
int ok[1000][1000];

struct cor
{
	int n, m;
};

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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ok[i][j] == 0)
			{
				vector<cor> points(0);
				for (int s = i; s < n; s++)
				{
					for (int b = 0; b < m; b++)
					{
						if (a[s][b] == a[i][j])
						{
							cor temp;
							temp.n = s;
							temp.m = b;
							points.push_back(temp);
						}
					}
				}
				for (int x = 0; x < points.size(); x++)
				{
					ok[points[x].n][points[x].m] = points.size();
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ok[i][j];
			if (j != m - 1)
			{
				cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}