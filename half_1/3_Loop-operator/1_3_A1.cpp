#include <iostream>

using namespace std;

int main()
{
	unsigned long long n;
	cin >> n;

	unsigned long long num = n;
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}

	if ((n % sum) == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

	//system("pause");
	return 0;
}