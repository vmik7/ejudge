#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int count[1001] = { 0 };

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		count[temp]++;
	}

	int max = 0;

	for (int i = 0; i < 1001; i++)
	{
		if (count[i] > max) max = count[i];
	}

	cout << max << endl;

	//system("pause");
	return 0;
}