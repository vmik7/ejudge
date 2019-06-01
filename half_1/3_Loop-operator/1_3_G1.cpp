#include <iostream>

using namespace std;

int main()
{
	long double x;
	cin >> x;

	int n = 1;
	long double to_add = 1;
	long double result = 1;

	while (to_add > 0)
	{
		to_add = to_add * x / n;
		result += to_add;
		n++;
	}

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(9);
	cout << result << endl;

	//system("pause");
	return 0;
}