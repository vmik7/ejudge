#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	string first, second;
	cin >> first >> second;

	if (first.size() != second.size())
	{
		cout << -1 << endl;
		//system("pause");
		return 0;
	}
	else
	{
		int changes = 0;
		for (int i = 0; i < first.size(); i++)
		{
			if (first[i] != second[i])
			{
				bool is_found = false;
				for (int j = i + 1; j < first.size() && !is_found; j++)
				{
					if (first[j] == second[i])
					{
						for (int x = j; x > i; x--)
							first[x] = first[x - 1];
						first[i] = second[i];
						changes += j - i;
						is_found = true;
					}
				}
				if (!is_found)
				{
					cout << -1 << endl;
					//system("pause");
					return 0;
				}
			}
		}
		cout << changes << endl;
	}

	//system("pause");
	return 0;
}