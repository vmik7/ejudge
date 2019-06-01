#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	cin.get();
	while (t--)
	{
		string m, n;
		cin >> m >> n;
		bool is_found = false;
		for (int i = 0; i <= (int)(m.size()) - (int)n.size() && !is_found; i++)
		{
			is_found = true;
			for (int j = 0; j < n.size(); j++)
			{
				if (m[i + j] != n[j])
				{
					is_found = false;
					break;
				}
			}
			if (is_found)
			{
				is_found = false;
				for (int j = 0; j < m.size(); j++)
				{
					if (m[j] == 'T')
					{
						is_found = true;
						cout << "Y" << endl;
						break;
					}
				}
			}
		}
		if (!is_found)
			cout << "N" << endl;
	}

	//system("pause");
	return 0;
}