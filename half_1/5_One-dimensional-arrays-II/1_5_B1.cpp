#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int * count = new int[n];
	for (int i = 0; i < n; i++) count[i] = 0;


	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		count[temp - 1]++;
		if (count[temp - 1] > 1 || temp > n)
		{
			cout << "NO\n" << temp << endl;
			delete[] count;
			return 0;
		}
	}

	cout << "YES" << endl;

	delete[] count;

	//system("pause");
	return 0;
}