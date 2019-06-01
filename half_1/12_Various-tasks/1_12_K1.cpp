#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		double a, b;
		cin >> a >> b;
		double s = a * b / 2;
		double p = a + b + sqrt(a * a + b * b);
		cout << fixed << setprecision(3) << p << " " << s << endl;
	}

	//system("pause");
	return 0;
}