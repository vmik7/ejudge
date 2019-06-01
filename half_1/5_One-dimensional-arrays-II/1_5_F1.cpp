#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int * n_array = new int[n];
	for (int i = 0; i < n; i++) cin >> n_array[i];

	bool flag = true;
	for (int i = 0; i < k && flag; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (n_array[j] > n_array[j + 1])
			{
				int temp = n_array[j];
				n_array[j] = n_array[j + 1];
				n_array[j + 1] = temp;
				flag = true;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << n_array[i] << ' ';

	return 0;
}