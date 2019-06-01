#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int a[100];

void shift(int * arr, int n, string nav, int val);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int val;
	string nav;
	cin >> val >> nav;

	shift(a, n, nav, val);

	for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
	cout << a[n - 1] << endl;

	//system("pause");
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