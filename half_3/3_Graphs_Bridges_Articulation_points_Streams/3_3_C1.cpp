#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 100;

int g[N + 1][N + 1];
int used[N + 1], p[N + 1];

bool bfs(int n) {
	for (int i = 1; i <= n; i++) used[i] = 0;
	queue<int> q;
	q.push(1); used[1] = 1; p[1] = -1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (used[i] || g[u][i] <= 0) continue;
			q.push(i); used[i] = 1; p[i] = u;
		}
	}
	return used[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] += c;
		g[v][u] = g[u][v];
	}

	int max_flow = 0;
	while (bfs(n)) {
		int minv = INF;
		for (int v = n; v != 1; v = p[v]) {
			int u = p[v];
			minv = min(minv, g[u][v]);
		}
		for (int v = n; v != 1; v = p[v]) {
			int u = p[v];
			g[u][v] -= minv;
			g[v][u] += minv;
		}
		max_flow += minv;
	}

	cout << max_flow << endl;

	return 0;
}
