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

const int N = 200000;

int l, timer;
int tin[N], tout[N];
vector<int> g[N], up[N];

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != p) dfs(to, v);
	}
	tout[v] = ++timer;
}

inline bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

inline bool upper_strong(int a, int b) {
	return tin[a] < tin[b] && tout[a] > tout[b];
}

int lca(int a, int b) {
	if (upper(a, b))  return a;
	if (upper(b, a))  return b;
	for (int i = l; i >= 0; i--) {
		if (!upper(up[a][i], b)) {
			a = up[a][i];
		}
	}
	return up[a][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
		
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[v].pb(u);
		g[u].pb(v);
	}

	l = 1;
	while ((1 << l) <= n) l++;
	for (int i = 0; i < n; ++i)  up[i].resize(l + 1);
	dfs(0);

	int q;
	cin >> q;
	while (q--) {
		int r, u, v;
		cin >> r >> u >> v;
		u--; v--; r--;
		int res = lca(u, v);
		if (!upper_strong(lca(res, r), res)) {
			u = lca(u, r); v = lca(v, r);
			res = (upper(u, v) ? v : u);
		}
		cout << res + 1 << endl;
	}

	return 0;
}
