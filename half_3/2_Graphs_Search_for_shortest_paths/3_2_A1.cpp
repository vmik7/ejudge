#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int> > g[200]; // { to, len }
set<pair<int, int> > s;         // { len, i }
int d[200];

int main() {
    while (1) {
        int n, m, k;
        cin >> n;
        if (n == 0) break;
        
        cin >> m;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({ b, c });
            g[b].push_back({ a, c });
        }
        cin >> k;
        
        d[0] = 0;
        for (int i = 1; i < n; i++) d[i] = INF;
        s.insert({ 0, 0 });
        while (!s.empty()) {
            int w = s.begin()->second;
            s.erase(s.begin());
            for (int i = 0; i < g[w].size(); i++) {
                int to = g[w][i].first;
                int l = g[w][i].second;
                if (d[w] + l < d[to]) {
                    s.erase({ d[to], to });
                    d[to] = d[w] + l;
                    s.insert({ d[to], to });
                }
            }
        }
        vector<pair<int, int> > ans;
        for (int i = 0; i < n; i++) ans.push_back({ d[i], i });
        sort(ans.begin(), ans.end());
        
        cout << ans[k].second << endl;
    }
    
    return 0;
}
