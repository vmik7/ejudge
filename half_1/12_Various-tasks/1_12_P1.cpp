#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

bool checkLevel(int sum, int i, int level)
{
	if (sum > vec[vec.size() - 1])
		return true;
	if (level > 0) {
		for (int j = i + 1; j < vec.size() - 1; j++)
		{
			if (!checkLevel(sum + vec[j], j, level - 1))
				return false;
		}
		return true;
	}
	else if (sum == vec[vec.size() - 1])
		return false;
	return true;
}

bool checkLastElement()
{
	for (int i = 1; i < vec.size(); i++)
	{
		if (!checkLevel(0, -1, i))
			return false;
	}
	return true;
}

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool is_super = true;
		while (n--)
		{
			int new_element;
			cin >> new_element;
			if (is_super)
			{
				if (!vec.empty() && new_element <= vec[vec.size() - 1])
					is_super = false;
				else
				{
					vec.push_back(new_element);
					is_super = checkLastElement();
				}
			}
		}
		if (is_super)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		vec.clear();
	}
	//system("pause");
	return 0;
}