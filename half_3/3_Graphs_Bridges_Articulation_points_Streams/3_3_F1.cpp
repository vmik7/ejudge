#include <bits/stdc++.h>
using namespace std;

int p[20001];
int get(int v) {
	if (p[v] == v) return v;
	return p[v] = get(p[v]);
}
struct TEdge {
	int u, v, w;
	bool operator< (TEdge t) {
		return this->w < t.w;
	}
} e[100000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e, e + m);

	long long ans = 0;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int u = get(e[i].u), v = get(e[i].v);
		if (u == v) continue;
		if (rand() % 2) swap(u, v);
		p[u] = v;
		ans += e[i].w;
	}
	cout << ans << endl;

	return 0;
}
