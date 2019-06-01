#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x[3], y[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}

	double a = sqrt(pow((y[0] - y[1]), 2) + pow((x[0] - x[1]), 2));
	double b = sqrt(pow((y[1] - y[2]), 2) + pow((x[1] - x[2]), 2));
	double c = sqrt(pow((y[2] - y[0]), 2) + pow((x[2] - x[0]), 2));

	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(6);

	cout << s << endl;

	//system("pause");
	return 0;
}