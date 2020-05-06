#include <bits/stdc++.h>
using namespace std;

vector<int> g[10001];
set<int> s;
int p[10001];

void init(int v) {
	p[v] = v;
}

int get(int v) {
	if (p[v] == v) return v;
	return p[v] = get(p[v]);
}

void unite(int u, int v) {
	u = get(u);
	v = get(v);
	if (u == v) return;
	if (rand() % 2) swap(u, v);
	p[u] = v;
}

int  main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) init(i);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				unite(i, g[i][j]);
			}
		}

		s.clear();
		for (int i = 1; i <= n; i++) s.insert(get(i));

		cout << s.size() - 1 << endl;
	}
	return 0;
}
