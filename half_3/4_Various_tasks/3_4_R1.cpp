#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int a[101];
int dp[101][101]; // dp[i][j] - number of ways for first i cooks and j dishes

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		n -= x;
		a[i] = y - x;
	}

	for (int i = 0; i <= m; i++) dp[i][0] = 1;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			for (int cnt = 0; cnt <= a[i] && j - cnt >= 0; cnt++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - cnt]) % MOD;
			}
		}
	}

	cout << (n < 0 ? 0 : dp[m][n]) << endl;

	return 0;
}
