#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = INT_MAX;

int g[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, e, t, m;
	cin >> n >> e >> t >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) g[i][j] = INF;
		g[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][k] == INF || g[k][j] == INF) continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (g[i][e] <= t) ans++;
	}
	cout << ans << endl;

	return 0;
}
