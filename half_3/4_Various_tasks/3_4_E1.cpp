#include <iostream>
#include <vector>

using namespace std;

const int N = 7919;
int p[N + 1];
vector<int> primes;

int main() {
	for (int i = 2; i <= N; i++) {
		if (p[i]) continue;
		primes.push_back(i);
		for (int j = i * i; j <= N; j += i) {
			p[j] = 1;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << 1ll * primes[n - 1] * primes[m - 1] << endl;
	}

	return 0;
}
