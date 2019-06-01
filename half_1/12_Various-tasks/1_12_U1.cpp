#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int a[1000];

void shift(int * arr, int n, string nav, int val);

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		shift(a, n, "right", k);
		for (int i = 0; i < n; i++) cout << a[i] << (i == n - 1 ? "\n" : " ");
	}
	return 0;
}


void shift(int * arr, int n, string nav, int val)
{
	if (nav == "left") val *= -1;
	else if (nav != "right") val = n;
	int count = 0;
	for (int i = 0; i < abs(val) && count != n; i++)
	{
		int carry = arr[i];
		int index = abs((n + i + val) % n);
		while (index != i)
		{
			int temp = arr[index];
			arr[index] = carry;
			carry = temp;
			index = abs((n + index + val) % n);
			count++;
		}
		arr[i] = carry;
		count++;
	}
}