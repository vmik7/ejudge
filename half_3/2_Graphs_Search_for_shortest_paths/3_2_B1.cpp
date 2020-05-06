#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = INT_MAX;

struct edge { int u, v, w; };

void solve() {
	vector<edge> e;
	int n, m, w;
	cin >> n >> m >> w;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ a - 1, b - 1, c });
		e.push_back({ b - 1, a - 1, c });
	}
	for (int i = 0; i < w; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ a - 1, b - 1, -c });
	}
	vector<int> d(n, INF);
	d[0] = 0;
	bool chk = false;
	for (int i = 0; i < n; i++) {
		chk = false;
		for (int j = 0; j < e.size(); j++) {
			int a = e[j].u, b = e[j].v, c = e[j].w;
			if (d[a] < INF && d[a] + c < d[b]) {
				d[b] = d[a] + c;
				chk = true;
			}
		}
	}
	puts(chk ? "YES" : "NO");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int f;
	cin >> f;
	while (f--) solve();

	return 0;
}
