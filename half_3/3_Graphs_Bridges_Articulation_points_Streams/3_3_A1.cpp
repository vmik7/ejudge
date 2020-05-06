#include <bits/stdc++.h>
using namespace std;

const int N = 10001;

vector<int> g[N];
bool used[N], used2[N];
int tin[N], fup[N], w[N];
int timer, n, m, ans;

int bfs(int v) {
	queue<int> q;
	q.push(v);
	used2[v] = true;
	int sum = w[v];
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (auto to : g[v]) {
			if (!used2[to]) {
				used2[to] = true;
				sum += w[to];
				q.push(to);
			}
		}
	}
	return sum;
}

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (auto to : g[v]) {
		if (to == p)  continue;
		if (used[to]) fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				for (int i = 1; i <= n; i++) used2[i] = false;
        used2[v] = true;
				ans = max(ans, bfs(to));
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n >> m) {
  if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; i++) {
			g[i].clear();
			used[i] = 0;
		}
		while (m--) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) cin >> w[i];
    ans = INT_MIN, timer = 0;
    dfs(1);
		if (ans == INT_MIN) cout << "No apple\n";
		else cout << ans << endl;
	}

	return 0;
}
