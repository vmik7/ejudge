#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void toPalindrom(string & value);

int main()
{
	string val;
	cin >> val;
	toPalindrom(val);

	cout << val << endl;
	//system("pause");
	return 0;
}

void toPalindrom(string & value)
{
	bool allow_copy = true;
	bool is_pal = true;
	int l = floor(double(value.size() - 1) / 2);
	int m = l;
	int r = ceil(double(value.size() - 1) / 2);
	while (l >= 0)
	{
		if (value[l] != value[r])
		{
			is_pal = false;
			if (value[l] < value[r])
			{
				allow_copy = false;
				break;
			}
		}
		l--;
		r++;
	}

	if (!allow_copy || is_pal)
	{
		for (int i = m; i >= -1; i--)
		{
			if (i < 0)
			{
				value = "1" + value;
				break;
			}
			else if (value[i] == '9')
			{
				value[i] = '0';
			}
			else
			{
				value[i]++;
				break;
			}
		}
	}

	l = 0;
	r = value.size() - 1;
	while (l < r)
	{
		value[r] = value[l];
		l++;
		r--;
	}
}