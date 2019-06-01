#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int * n_array = new int[n];
	int * index_array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> n_array[i];
		index_array[i] = i;
	}

	bool flag = true;
	for (int i = 0; i < n - 1 && flag; i++)
	{
		flag = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (n_array[j] > n_array[j + 1])
			{
				swap(n_array[j], n_array[j + 1]);
				swap(index_array[j], index_array[j + 1]);
				flag = true;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << index_array[i] << ' ';

	return 0;
}