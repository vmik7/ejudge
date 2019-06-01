#include <iostream>
#include <vector>

using namespace std;

bool not_primes[1000001];
vector<long long> primes;

void calcPrimes();
bool isPrime(long long N);

int main()
{
	calcPrimes();

	int t;
	cin >> t;
	while (t--)
	{
		long long val;
		cin >> val;
		if (isPrime(val)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}


bool isPrime(long long N)
{
	for (int i = 0; i < primes.size() && primes[i] < N; i++)
		if (N % primes[i] == 0) return false;
	return true;
}

void calcPrimes()
{
	for (int i = 2; i <= 1000; i++)
	{
		if (not_primes[i])
			continue;
		for (int j = i * i; j <= 1000000; j += i)
			not_primes[j] = true;
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if (!not_primes[i])
			primes.push_back(i);
	}
}