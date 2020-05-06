#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define sp(n) fixed << setprecision(n)
#define pb push_back
#define ff first
#define ss second

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    string tmp, chk;
    getline(cin, tmp);

    regex rx(tmp);
    while (getline(cin, chk))
        cout << (regex_match(chk, rx) ? "YES" : "NO") << endl;

    return 0;
}
