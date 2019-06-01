#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	long d = (b * b) - (4 * a * c);
	long x1 = (-b - sqrt(d)) / (2 * a);
	long x2 = (-b + sqrt(d)) / (2 * a);

	cout << x1 << ' ' << x2 << endl;

	//system("pause");
	return 0;
}