#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x[3], y[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}

	double len_B = sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2));
	unsigned long long temp_B = (unsigned long long)(len_B * pow(10, 9));

	double len_C = sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2));
	unsigned long long temp_C = (unsigned long long)(len_C * pow(10, 9));
	//len_C = trunc(len_C * pow(10, 9)) / pow(10, 9);

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(9);

	if (temp_B == temp_C)
	{
		cout << "equal" << endl;
		cout << len_C << endl;
	}
	else if (temp_B < temp_C)
	{
		cout << "B" << endl;
		cout << len_B << endl;
	}
	else if (temp_C < temp_B)
	{
		cout << "C" << endl;
		cout << len_C << endl;
	}

	//system("pause");
	return 0;
}