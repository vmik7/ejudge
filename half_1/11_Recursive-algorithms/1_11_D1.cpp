#include <iostream>
#include <string>

using namespace std;

string result = "";
void getCantor(long long n, int k, int begin = 0);

int main()
{
	long long n;
	int k, p = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) result += '#';

	getCantor(n, k);

	cout << result << endl;

	//system("pause");
	return 0;
}


void getCantor(long long n, int k, int begin)
{
	for (int i = begin + n / 3; i < begin + 2 * n / 3; i++)
		result[i] = ' ';
	if (k > 1)
	{
		getCantor(n / 3, k - 1, begin);
		getCantor(n / 3, k - 1, begin + 2 * n / 3);
	}
}