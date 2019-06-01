#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct pos
{
	int i;
	int j;
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pos> min(1);
	min[0].i = 0;
	min[0].j = 0;

	int min_val;
	cin >> min_val;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 && j == 0) j++;
			int temp;
			cin >> temp;
			if (temp <= min_val)
			{
				if (temp < min_val)
				{
					min.clear();
					min_val = temp;
				}
				pos temp_pos;
				temp_pos.i = i;
				temp_pos.j = j;
				min.push_back(temp_pos);
			}
		}
	}

	int s = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; j++)
		{
			if (s < min.size() && i == min[s].i && j == min[s].j)
			{
				s++;
				if (str[j] == '0') count++;
			}
		}
	}

	cout << count << endl;

	//system("pause");
	return 0;
}