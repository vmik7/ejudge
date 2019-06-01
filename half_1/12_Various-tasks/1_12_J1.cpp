//S(n) = sqrt(n + 1) - 1;

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a = sqrt(n + 1);
		a = a * a - 1;
		int b = ceil(sqrt(n + 1));
		b = b * b - 1;
		cout << a << " " << b << endl;
	}

	//system("pause");
	return 0;
}