#include <iostream>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << b - a + 1 << endl;
		for (int num = a; num <= b; num++) cout << num << (num == b ? "\n" : " ");
	}
	//system("pause");
	return 0;
}