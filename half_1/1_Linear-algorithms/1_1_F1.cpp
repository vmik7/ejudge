#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	double c = sqrt((a*a) + (b*b));

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(6);
	cout << c << endl;

	//system("pause");
	return 0;
}