#include <bits/stdc++.h>
using namespace std;

int r[101];
int dp[101][101];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++) cin >> r[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                dp[i][i + l - 1] = INT_MAX;
            }
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + r[i - 1] * r[k] * r[j] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[1][n] << endl;
    }
    return 0;
}
