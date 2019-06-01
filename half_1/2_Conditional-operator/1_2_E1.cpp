#include <iostream>

using namespace std;

int main()
{
	long x, y;
	cin >> x >> y;

	if (x && y)			cout << 0 << endl;
	else if (!x && !y)	cout << 1 << endl;
	else if (!y)		cout << 2 << endl;
	else if (!x)		cout << 3 << endl;

	//system("pause");
	return 0;
}