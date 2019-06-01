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

	for (int i = 0; i < n; i++)
	{
		if (n_array[i] % 2)
		{
			cout << n_array[i];
			for (int j = i + 1; j < n; j++)
				if (n_array[j] % 2)
					cout << ' ' << n_array[j];
			break;
		}
	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		if (n_array[i] % 2 == 0)
		{
			cout << n_array[i];
			for (int j = i + 1; j < n; j++)
				if (n_array[j] % 2 == 0)
					cout << ' ' << n_array[j];
			break;
		}
	}

	cout << endl;

	delete[] n_array;

	//system("pause");
	return 0;
}