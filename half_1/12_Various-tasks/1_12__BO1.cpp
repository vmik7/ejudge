#include <iostream>
#include <string>

using namespace std;

int left_val[26];
int right_val[26];

int main()
{
	long long t;
	cin >> t;
	cin.get();
	while (t--)
	{
		string val;
		cin >> val;
		for (int i = 0; i < int(val.size() / 2); i++)
		{
			left_val[val[i] - 'a']++;
			right_val[val[val.size() - 1 - i] - 'a']++;
		}
		bool is_lap = true;
		for (int i = 0; i < 26; i++)
		{
			if (right_val[i] != left_val[i]) is_lap = false;
			right_val[i] = 0;
			left_val[i] = 0;
		}
		if (is_lap) cout << "YES" << endl;
		else		cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}