#include <bits/stdc++.h>
using namespace std;

int dp[31][31];

int main() {
	for (int i = 1; i <= 30; i++) dp[i][1] = 1;
	for (int j = 1; j <= 30; j++) dp[1][j] = j;
	for (int i = 2; i <= 30; i++) {
		for (int j = 2; j <= 30; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
		}
	}
	int n, m;
	while (cin >> n >> m) {
		int ans = -1;
		for (int i = 1; i <= 30; i++) {
			if (dp[n][i] >= m) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
