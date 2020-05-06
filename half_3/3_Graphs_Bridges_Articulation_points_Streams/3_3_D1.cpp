#include <bits/stdc++.h>

#define all(v) v.begin(), v.end();
#define pb push_back
#define ff first
#define ss second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, k;
ll g[250][250];
pii a[250], b[250];
int mt[250], used[250];

inline ll dist(pii a, pii b) { return 1ll * (a.ff - b.ff) * (a.ff - b.ff) + 1ll * (a.ss - b.ss) * (a.ss - b.ss); }

bool try_kuhn(int v, ll d) {
    if (used[v]) return false;
    used[v] = 1;
    for (int i = 0; i < m; i++) {
        if (g[v][i] > d) continue;
        if (mt[i] == -1 || try_kuhn(mt[i], d)) {
            mt[i] = v;
            return true;
        }
    }
    return false;
}

bool solve(ll d) {
    for (int i = 0; i < m; i++) mt[i] = -1;
    for (int v = 0; v < n; v++) {
        for (int i = 0; i < n; i++) used[i] = 0;
        try_kuhn(v, d);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) cnt += (mt[i] != -1);
    return cnt >= k;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i].ff >> a[i].ss;
    for (int i = 0; i < m; i++) cin >> b[i].ff >> b[i].ss;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) g[i][j] = dist(a[i], b[j]);
    }
    
    ll l = 0, r = LLONG_MAX;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (solve(mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << endl;
    
    return 0;
}
