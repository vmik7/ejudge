#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int * n_array = new int[n];
	for (int i = 0; i < n; i++) cin >> n_array[i];

	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (n_array[j] < n_array[i])
			{
				int temp = n_array[i];
				n_array[i] = n_array[j];
				n_array[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << n_array[i] << ' ';

	return 0;
}