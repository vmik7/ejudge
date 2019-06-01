#include <iostream>

using namespace std;

int main()
{
	long a, m;
	int n;
	cin >> a >> n >> m;

	unsigned long long sum = 1;
	while (n)
	{
		sum = ((sum * a) + 1) % m;
		n--;
	}

	cout << sum << endl;
	return 0;
}