#include <iostream>
#include <algorithm>

using namespace std;

int a[1002], dp[1002];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cin >> k;
		n++;
		a[n] = 0;
		for (int i = 1; i <= n; i++) {
			int maxv = dp[i - 1];
			for (int j = i - 1; j >= max(0, i - k); j--) maxv = max(maxv, dp[j]);
			dp[i] = a[i] + maxv;
		}
		cout << dp[n] << endl;
	}

	return 0;
}
