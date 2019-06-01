#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long x, y, z;
	cin >> x >> y >> z;

	if (x > y && y > z)
	{
		x *= 2;
		y *= 2;
		z *= 2;
	}
	else
	{
		x *= -1;
		y *= -1;
		z *= -1;
	}

	cout << x << ' ' << y << ' ' << z << endl;

	//system("pause");
	return 0;
}