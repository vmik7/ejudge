#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(6);

	long d = (b * b) - (4 * a * c);

	if (d < 0)
	{
		cout << "No roots" << endl;
	}
	else if (d == 0)
	{
		double x = double(-b) / (2 * a);
		cout << x << endl;
	}
	else if (d > 0)
	{
		double sd = sqrt(d);
		double x1 = double(-b - sd) / (2 * a);
		double x2 = double(-b + sd) / (2 * a);
		if (x1 < x2)		cout << x1 << ' ' << x2 << endl;
		else if (x2 < x1)	cout << x2 << ' ' << x1 << endl;
	}

	//system("pause");
	return 0;
}