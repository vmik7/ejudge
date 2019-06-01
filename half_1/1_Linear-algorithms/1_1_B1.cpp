#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(3);

	cout << ((a * a) + (b * b)) / 2 << endl;
	cout << (abs(a) + abs(b)) / 2 << endl;

	//system("pause");
	return 0;
}