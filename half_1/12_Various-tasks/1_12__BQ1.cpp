#include <iostream>
#include <vector>

using namespace std;

int a[1000][1000];

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
		vector<int> mins(0);
		int min = a[i][0];
		mins.push_back(0);

		for (int j = 1; j < m; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				mins.clear();
				mins.push_back(j);
			}
			else if (a[i][j] == min)
			{
				mins.push_back(j);
			}
		}
		for (int c = 0; c < mins.size(); c++)
		{
			bool flag = true;
			for (int i1 = 0; i1 < n && flag; i1++)
			{
				if (a[i1][mins[c]] > a[i][mins[c]] && i1 != i)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << a[i][mins[c]] << endl;
				cout << i << " " << mins[c] << endl;
				//system("pause");
				return 0;
			}
		}
	}

	cout << 0 << endl;
	//system("pause");
	return 0;
}