#include <bits/stdc++.h>
using namespace std;

const int N = 3000;
vector<int> g[N];

int cutpoints, timer;
int used[N], tin[N], fup[N];

void dfs(int v, int p = -1) {
	used[v] = 1;
	fup[v] = tin[v] = timer++;
	int children = 0;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to == p) continue;
		if (used[to]) fup[v] = min(fup[v], tin[to]);
		else {
			children++;
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (used[v] != 2 && fup[to] >= tin[v] && p != -1) {
				used[v] = 2;
				cutpoints++;
			}
		}
	}
	if (p == -1 && children > 1) {
		used[v] = 2;
		cutpoints++;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);

	cout << cutpoints << endl;

	return 0;
}
