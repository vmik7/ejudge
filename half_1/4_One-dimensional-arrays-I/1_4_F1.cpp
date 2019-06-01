#include <iostream>
#include <cmath>

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

	int d = abs(n_array[1] - n_array[0]);
	int x = 0, y = 1;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int d1 = abs(n_array[j] - n_array[i]);
			if (d1 < d)
			{
				d = d1;
				x = i;
				y = j;
			}
		}
	}

	cout << x << ' ' << y << endl;

	delete[] n_array;

	return 0;
}