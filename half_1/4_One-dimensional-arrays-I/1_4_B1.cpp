#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int * n_array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> n_array[i];
	}

	for (int i = 0; i < n; i += 2)
	{
		cout << n_array[i];
		if (i != n - 1 && i != n - 2) cout << ' ';
		else cout << endl;
	}

	for (int i = 1; i < n; i += 2)
	{
		cout << n_array[i] << ' ';
	}

	delete[] n_array;

	//system("pause");
	return 0;
}