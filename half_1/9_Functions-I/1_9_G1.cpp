#include <iostream>
#include <iomanip>

using namespace std;

long double func(int n);

int main()
{
	int n;
	cin >> n;
	cout << fixed << setprecision(4) << func(n) << endl;

	//system("pause");
	return 0;
}


long double func(int n)
{
	double result = 1;
	n -= 2;
	while (n)
	{
		result /= (n--);
		result *= (n--);
	}
	return result;
}