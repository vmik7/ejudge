#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = INT_MAX;

vector<int> g[51];

int used[51];
int dfs(int node, int b, int t) {
	if (node == b) return 1;
	if (t == 0) return 0;
	used[node] = 1;
	int cnt = 0;
	for (int i = 0; i < g[node].size(); i++) {
		int to = g[node][i];
		if (used[to]) continue;
		cnt += dfs(to, b, t - 1);
	}
	used[node] = 0;
	return cnt;
}

int solve() {
	int n, k, a, b, d;
	cin >> n >> k >> a >> b >> d;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	return dfs(a, b, d);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) cout << solve() << endl;

	return 0;
}
