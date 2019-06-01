#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(3);
	long long t;
	cin >> t;
	while (t--)
	{
		double a, b;
		int n;
		cin >> n >> a >> b;
		double d = (b - a) / (n - 1);
		for (int i = 0; i < n; i++)
		{
			double result = 1 - sin(a);
			cout << "X=" << a << " F(X)=" << result << endl;
			a += d;
		}
	}
	//system("pause");
	return 0;
}