#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v(1);
int g[16][16];
int dp[(1 << 16)][16];

int main() {
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			char c;
			cin >> c;
			if (c == 'L') v[0] = { i, j };
			else if (c == '#') v.push_back({ i, j });
		}
	}

	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			g[i][j] = g[j][i] = max(abs(v[i].first - v[j].first), abs(v[i].second - v[j].second));
		}
	}

	for (int mask = 1; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) dp[mask][i] = INT_MAX;
	}
	dp[1][0] = 0;

	for (int mask = 1; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (dp[mask][i] == INT_MAX) continue;
			for (int j = 0; j < n; j++) {
				if (mask & (1 << j)) continue;
				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + g[i][j]);
			}
		}
	}
	int* a = dp[(1 << n) - 1];
	for (int i = 0; i < n; i++) {
		a[i] += g[i][0];
	}
	cout << *min_element(a, a + n) << endl;

	return 0;
}
