#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define sp(n) fixed << setprecision(n)
#define pb push_back
#define ff first
#define ss second

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1e9 + 7;
const double EPS = DBL_EPSILON;

vector<pii> g[1001]; // { to, len }
set<pii> s; // { len, i }
int d[1001], dp[1001];

int dfs(int v) {
	if (dp[v]) return dp[v];
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].ff;
		if (d[to] < d[v]) dp[v] += dfs(to);
	}
	return dp[v];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	while ((cin >> n) && n) {
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) dp[i] = (i == 2 ? 1 : 0);
		for (int i = 1; i <= n; i++) d[i] = (i == 2 ? 0 : INT_MAX);

		cin >> m;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb({ v, w });
			g[v].pb({ u, w });
		}

		s.insert({ 0, 2 });
		while (!s.empty()) {
			int v = s.begin()->ss;
			s.erase(s.begin());
			for (int i = 0; i < g[v].size(); i++) {
				int to = g[v][i].ff;
				int l = g[v][i].ss;
				if (d[v] + l < d[to]) {
					s.erase({ d[to], to });
					d[to] = d[v] + l;
					s.insert({ d[to], to });
				}
			}
		}

		cout << dfs(1) << endl;
	}

	return 0;
}
