#include <iostream>

using namespace std;

const int MaxVal = 100;
int value[MaxVal + 1];

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n, val;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> val;
			value[val]++;
		}
		int max = 0;
		for (int i = 0; i < MaxVal + 1; i++)
		{
			if (value[i] > max) max = value[i];
			value[i] = 0;
		}
		cout << max << endl;
	}
	//system("pause");
	return 0;
}