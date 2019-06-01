#include <iostream>

using namespace std;

long long Euler(long long N);

int main()
{
	long long val;
	cin >> val;
	cout << Euler(val) << endl;

	//system("pause");
	return 0;
}

long long Euler(long long N)
{
	long long result = N;
	for (long long i = 2; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			while (N % i == 0)
				N /= i;
			result -= result / i;
		}
	}
	if (N > 1)
		result -= result / N;
	return result;
}