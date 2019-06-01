#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x);

int main()
{
	double x;
	while (cin >> x) cout << fixed << setprecision(6) << func(x) << endl;
	return 0;
}

double func(double x)
{
	return sin(x) + sqrt(log(3 * x) / log(4)) + ceil(3 * exp(x));
}