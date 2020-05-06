#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int> > g[501]; // { to, len }
set<pair<int, int> > st;         // { len, i }
int d[501];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, e;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({ b, w });
            g[b].push_back({ a, w });
        }
        cin >> s >> e;
        
        for (int i = 1; i <= n; i++) d[i] = INF;
        d[s] = 0;
        st.insert({ 0, s });
        while (!st.empty()) {
            int w = st.begin()->second;
            st.erase(st.begin());
            for (int i = 0; i < g[w].size(); i++) {
                int to = g[w][i].first;
                int l = g[w][i].second;
                if (d[w] + l < d[to]) {
                    st.erase({ d[to], to });
                    d[to] = d[w] + l;
                    st.insert({ d[to], to });
                }
            }
        }
        if (d[e] == INF) cout << "infinity" << endl;
        else cout << d[e] << endl;
    }
    
    return 0;
}
