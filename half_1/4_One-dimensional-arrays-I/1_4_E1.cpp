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

	int d = n_array[1] - n_array[0];

	for (int i = 2; i < n; i++)
	{
		if (n_array[i] - n_array[i - 1] != d)
		{
			cout << 0 << endl;
			delete[] n_array;
			return 0;
		}
	}

	cout << d << endl;

	delete[] n_array;

	return 0;
}