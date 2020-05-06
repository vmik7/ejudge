#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = INT_MAX;

vector<int> g[201];

int color[201];
bool dfs(int node, int prev) {
	bool ans = false;
	color[node] = 1;
	for (int i = 0; i < g[node].size(); i++) {
		int to = g[node][i];
		if (to == prev) continue;
		if (color[to] == 1 || color[to] == 0 && dfs(to, node)) {
			ans = true;
		}
	}
	color[node] = 2;
	return ans;
}

int solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		color[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool is_connected = true;
	bool is_cyclic = dfs(1, 1);
	for (int i = 2; i <= n; i++) {
		if (color[i]) continue;
		is_connected = false;
		break;
	}
	if (!is_connected) return 0;
	return (is_cyclic ? 1 : 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}

	return 0;
}
