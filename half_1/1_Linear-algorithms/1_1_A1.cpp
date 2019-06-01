#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	cout << (a + b) << endl;

	cout << (a - b) << endl;

	unsigned long long mul = (unsigned long long)a * (unsigned long long)b;
	cout << mul << endl;

	double div = (double)a / b;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(3);
	cout << div << endl;

	//system("pause");
	return 0;
}