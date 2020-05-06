#include <bits/stdc++.h>
using namespace std;

int g[101][101];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u][v] = 1;
            g[v][u] = 1;
        }
        for (int i = 1; i <= n; i++) g[i][i] = 1;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
                }
            }
        }
        
        int q;
        cin >> q;
        while (q--) {
            int i, j;
            cin >> i >> j;
            cout << g[i][j] << endl;
        }
    }
    
    return 0;
}
