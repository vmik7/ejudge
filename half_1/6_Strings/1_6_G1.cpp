#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string child, parent;

	cin >> child >> parent;

	int count = 0;

	if (child.size() > parent.size())
	{
		cout << count << endl;
		//system("pause");
		return 0;
	}

	for (int i = 0; i <= parent.size() - child.size(); i++)
	{
		string temp = "";
		for (int j = 0; j < child.size(); j++)
		{
			temp += parent[i + j];
		}

		for (int j = 0; j < child.size(); j++)
		{
			for (int h = j; h < child.size(); h++)
			{
				if (temp[h] == child[j])
				{
					swap(temp[j], temp[h]);
					break;
				}
			}
		}

		if (temp == child)
		{
			count++;
		}
	}

	cout << count << endl;

	//system("pause");
	return 0;
}