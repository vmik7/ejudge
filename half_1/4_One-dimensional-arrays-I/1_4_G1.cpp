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

	int min = n_array[0], max = n_array[0];
	int min_i = 0, max_i = 0;

	for (int i = 1; i < n; i++)
	{
		if (n_array[i] < min)
		{
			min = n_array[i];
			min_i = i;
		}
		else if (n_array[i] > max)
		{
			max = n_array[i];
			max_i = i;
		}
	}

	if (max_i < min_i)
	{
		int temp = max_i;
		max_i = min_i;
		min_i = temp;
	}

	for (int i = min_i + 1, j = 1; i <= (min_i + max_i) / 2; i++, j++)
	{
		int temp = n_array[i];
		n_array[i] = n_array[max_i - j];
		n_array[max_i - j] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << n_array[i] << ' ';
	}

	delete[] n_array;

	return 0;
}