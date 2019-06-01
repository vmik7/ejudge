#include <iostream>

using namespace std;

void oneToN(int n);

int main()
{
	int n;
	cin >> n;
	oneToN(n);
	cout << endl;

	//system("pause");
	return 0;
}

void oneToN(int n) {
	if (n == 1)
		cout << 1;
	else
	{
		oneToN(n - 1);
		cout << " " << n;
	}
}