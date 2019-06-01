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

	int temp = n_array[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		n_array[i] = n_array[i - 1];
	}
	n_array[0] = temp;


	for (int i = 0; i < n; i++)
	{
		cout << n_array[i] << ' ';
	}

	delete[] n_array;

	//system("pause");
	return 0;
}