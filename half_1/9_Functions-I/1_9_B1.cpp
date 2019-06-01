#include <iostream>
#include <algorithm>

using namespace std;

void MinMax(int a, int b, int c, int d, int &maxv, int &minv);

int main()
{
	int a, b, c, d, minValue, maxValue;
	cin >> a >> b >> c >> d;
	MinMax(a, b, c, d, maxValue, minValue);
	cout << minValue << " " << maxValue << endl;

	return 0;
}

void MinMax(int a, int b, int c, int d, int &maxv, int &minv)
{
	int arr[4];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	sort(arr, arr + 4);
	maxv = arr[3];
	minv = arr[0];
}