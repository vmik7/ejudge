#include <iostream>
#include <string>

using namespace std;

int main()
{
	string parent, child;

	cin >> parent >> child;

	int count = 0;

	if (child.size() > parent.size())
	{
		cout << count << endl;
		//system("pause");
		return 0;
	}

	for (int i = 0; i <= parent.size() - child.size(); i++)
	{
		int difference = 0;
		for (int j = 0; j < child.size(); j++)
		{
			if (parent[i + j] != child[j])
			{
				difference++;
			}
		}
		if (difference <= 1)
		{
			count++;
		}
	}

	cout << count << endl;

	//system("pause");
	return 0;
}