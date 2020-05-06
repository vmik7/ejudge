#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][101];

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				cin >> dp[i][j];
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			cin >> dp[i][i];
			dp[i][i] += dp[i - 1][i - 1];
		}

		int maxv = dp[n][1];
		for (int i = 2; i <= n; i++) maxv = max(maxv, dp[n][i]);
		cout << maxv << endl;
	}
	
	return 0;
}
