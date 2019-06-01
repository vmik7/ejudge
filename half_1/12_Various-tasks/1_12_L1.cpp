#include <iostream>

using namespace std;

int main()
{
	int a[5];
	long long t;
	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= 4; i++) cin >> a[i];
		int num = 0;
		if (a[1] == a[2])
		{
			if (a[2] == a[3]) num = 4;
			else num = 3;
		}
		else
		{
			if (a[1] == a[3]) num = 2;
			else num = 1;
		}
		cout << num << endl;
	}
	//system("pause");
	return 0;
}