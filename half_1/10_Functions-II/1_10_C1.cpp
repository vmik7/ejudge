#include <iostream>

using namespace std;

long long Combin(int N, int M);

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		long long result = Combin(n, m);
		if (result > 0) cout << result << endl;
		else cout << "Too big!" << endl;

	}
	return 0;
}


long long Combin(int N, int M)
{
	int n_number = M + 1;
	int nm_number = 1;
	long long result = 1;
	while (n_number <= N || nm_number <= N - M)
	{
		if (n_number <= N)
		{
			result *= n_number;
			n_number++;
		}
		if (nm_number <= N - M)
		{
			result /= nm_number;
			nm_number++;
		}
	}
	if (result > 1000000000) return -1;
	else return result;
}