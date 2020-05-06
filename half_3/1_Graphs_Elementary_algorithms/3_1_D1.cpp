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

const int N = 100001;
vector<int> g[N];

int color[N];
bool is_cyclic;

int ind = 1;
int ans[N];

void dfs(int v) {
	color[v] = 1;
	for (auto to : g[v]) {
		if (color[to] == 0)
			dfs(to);
		if (color[to] == 1)
			is_cyclic = true;
	}
	ans[ind++] = v;
	color[v] = 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

#ifdef LOCAL_DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}

	for (int i = 1; i <= n; i++) {
		if (color[i] == 0)
			dfs(i);
	}

	if (is_cyclic)
		cout << -1 << endl;
	else {
		reverse(ans + 1, ans + 1 + n);
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " \n"[i == n];
	}

	return 0;
}
