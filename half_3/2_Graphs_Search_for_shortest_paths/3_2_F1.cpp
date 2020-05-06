#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

char s[1000][1000];
int n, m, ans;

int dfs(int x, int y, int px, int py) {
	int max1 = 0, max2 = 0;
	if (x + 1 < n && s[x + 1][y] == '.' && x + 1 != px) {
		int l = dfs(x + 1, y, x, y) + 1;
		if (l > max1) {
			max2 = max1;
			max1 = l;
		}
		else if (l > max2) max2 = l;
	}
	if (x - 1 >= 0 && s[x - 1][y] == '.' && x - 1 != px) {
		int l = dfs(x - 1, y, x, y) + 1;
		if (l > max1) {
			max2 = max1;
			max1 = l;
		}
		else if (l > max2) max2 = l;
	}
	if (y + 1 < m && s[x][y + 1] == '.' && y + 1 != py) {
		int l = dfs(x, y + 1, x, y) + 1;
		if (l > max1) {
			max2 = max1;
			max1 = l;
		}
		else if (l > max2) max2 = l;
	}
	if (y - 1 >= 0 && s[x][y - 1] == '.' && y - 1 != py) {
		int l = dfs(x, y - 1, x, y) + 1;
		if (l > max1) {
			max2 = max1;
			max1 = l;
		}
		else if (l > max2) max2 = l;
	}
	ans = max(ans, max1 + max2);
	return max1;
}

void solve() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	swap(n, m);
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> s[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') {
				dfs(i, j, i, j);
				cout << "Maximum rope length is " << ans << ".\n";
				return;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
