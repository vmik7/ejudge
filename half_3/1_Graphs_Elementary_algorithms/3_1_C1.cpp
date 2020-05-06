#include <bits/stdc++.h>
using namespace std;

int n = 0;
int g[30][30], p[30][30], t[30][30], a[30][30];

void mul() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			t[i][j] = 0;
			for (int k = 0; k <= n; k++) {
				t[i][j] += p[i][k] * g[k][j];
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			p[i][j] = t[i][j];
		}
	}
	return;
}

int main() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = p[x][y] = g[x][y] = 1;
		n = max(n, max(x, y));
	}

	for (int k = 2; k <= n; k++) {
		mul();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				a[i][j] += p[i][j];
			}
		}
	}
	for (int k = 0; k <= 2 * n; k++) {
		mul();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (p[i][j]) a[i][j] = -1;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << a[i][n] << endl;
	}

	return 0;
}
