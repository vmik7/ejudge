#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_less(string str1, string str2);

int main()
{
	int n;
	cin >> n;

	vector<string> strs(n);

	for (int i = 0; i < n; i++)
	{
		cin >> strs[i];
	}

	bool flag = true;
	for (int i = 0; i < n && flag; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (is_less(strs[j + 1], strs[j]))
			{
				swap(strs[j + 1], strs[j]);
				flag = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << strs[i] << endl;
	}

	//system("pause");
	return 0;
}


bool is_less(string str1, string str2)
{
	int n = (str1.size() < str2.size() ? str1.size() : str2.size());
	for (int i = 0; i < n; i++)
	{
		if (str1[i] < str2[i])
		{
			return true;
		}
		else if (str1[i] > str2[i])
		{
			return false;
		}
	}
	if (str1.size() == n)
	{
		return true;
	}
	return false;
}