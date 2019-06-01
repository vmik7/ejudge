#include <iostream>

using namespace std;

int main()
{
	long min;
	int n = 3;

	cin >> min;
	n--;
	while (n)
	{
		long val;
		cin >> val;
		if (val < min) min = val;
		n--;
	}

	cout << min << endl;

	//system("pause");
	return 0;
}