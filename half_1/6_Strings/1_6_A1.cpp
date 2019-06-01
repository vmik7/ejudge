#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int l = 0;
	int r = str.size() - 1;
	int del_index = str.size() / 2;

	bool is_error = false;
	int temp_index = 0;

	while (l < r)
	{
		if (str[l] != str[r])
		{
			if (is_error)
			{
				del_index = temp_index;
				break;
			}
			else
			{
				temp_index = r;
				del_index = l;
				l++;
			}
			is_error = true;
		}
		else
		{
			l++;
			r--;
		}
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (i != del_index)
		{
			cout << str[i];
		}
	}

	//system("pause");
	return 0;
}