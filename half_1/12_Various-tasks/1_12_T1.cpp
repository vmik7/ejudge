#include <iostream>

using namespace std;

int arr[100];

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cin >> arr[0];
		int max_i = 0;
		int min_i = 0;
		for (int i = 1; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] > arr[max_i]) max_i = i;
			else if (arr[i] < arr[min_i]) min_i = i;
		}
		int temp = arr[max_i];
		arr[max_i] = arr[min_i];
		arr[min_i] = temp;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << (i == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}