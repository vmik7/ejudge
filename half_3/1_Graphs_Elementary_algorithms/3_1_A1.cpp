#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];

int lbs(vector<int> & v, int x) {
    int l = 0, r = v.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] >= x) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    int n, m, q, a, b;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
    
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &a, &b);
        int i = lbs(g[a], b);
        printf("%d\n", i < g[a].size() && g[a][i] == b ? i + 1 : 0);
    }
    
    return 0;
}
