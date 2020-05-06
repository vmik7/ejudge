#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[1000]; // {val, i}
pair<int, int> dp[1001]; // {cnt, last}, i ~ sum;

int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    if (c == 0) {
        cout << "0\n\n";
        return 0;
    }

    sort(a, a + n);
    dp[c] = { 0, n };
    for (int i = c - 1; i >= 0; i--) dp[i].first = n + 1;
    for (int i = c; i > 0; i--) {
        if (dp[i].first >= n) continue;
        for (int j = dp[i].second - 1; j >= 0; j--) {
            int s = i - a[j].first;
            if (s < 0) continue;
            pair<int, int> val = { dp[i].first + 1, j };
            if (val.first < dp[s].first || val.first == dp[s].first && val.second > dp[s].second) {
                dp[s] = val;
            }
        }
    }

    if (dp[0].first > n) {
        cout << -1 << endl;
    }
    else {
        cout << dp[0].first << endl;
        vector<int> ans;
        int val = 0;
        while (val < c) {
            ans.push_back(a[dp[val].second].second);
            val += a[dp[val].second].first;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " ";
        cout << ans[ans.size() - 1] << endl;
    }

    return 0;
}
