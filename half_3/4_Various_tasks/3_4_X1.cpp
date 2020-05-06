#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;

int dp[1024][101];
int a[10][101];

int main() {
    dp[0][0] = 1;
    int t;
    cin >> t;
    while (t--) {
        int n;
        (cin >> n).get();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 100; j++) a[i][j] = 0;
            string s;
            getline(cin, s);
            istringstream is(s);
            int v;
            while (is >> v) a[i][v] = 1;
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 1; i <= 100; i++) dp[mask][i] = 0;
        }
        for (int i = 1; i <= 100; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j) || a[j][i] == 0) continue;
                    dp[mask | (1 << j)][i] = (1ll * dp[mask | (1 << j)][i] + dp[mask][i - 1]) % Mod;
                }
                dp[mask][i] = (1ll * dp[mask][i] + dp[mask][i - 1]) % Mod;
            }
        }
        cout << dp[(1 << n) - 1][100] << endl;
    }
    return 0;
}
