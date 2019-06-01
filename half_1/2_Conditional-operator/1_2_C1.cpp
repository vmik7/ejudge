#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;

	if (y < x && y < z) swap(y, x);
	else if (z < x && z < y) swap(z, x);
	if (y > z) swap(y, z);

	double result = double(z*z - x * x) / (y*y - x * x);

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(6);

	cout << result << endl;

	//system("pause");
	return 0;
}