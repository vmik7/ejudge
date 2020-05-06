#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];
int used[100001];

int main() {
    int n, m, a, b, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 0) continue;
        bool l = 1;
        for (int j = 0; j < g[i].size(); j++) {
            if (g[g[i][j]].size() > 1 || used[g[i][j]]) {
                l = 0;
                break;
            }
        }
        if (l) {
            used[i] = 1;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}
