#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int start = 1;
const int Max_size = 262144;
vector<int> tree[Max_size];

void merge(vector<int> & a, vector<int> & b, vector<int> & res) {
    int a_index = 0;
    int b_index = 0;
    while (a_index < a.size() || b_index < b.size()) {
        if ((a_index < a.size()) && (b_index >= b.size() || a[a_index] < b[b_index])) {
            res.push_back(a[a_index]);
            a_index++;
        }
        else {
            res.push_back(b[b_index]);
            b_index++;
        }
    }
    return;
}

long long f(long long x, long long a) {
    return abs(2 * a * a - x * x);
}

int bin_search(vector<int> & vec, long long a) {
    int l = -1;
    int r = vec.size() - 1;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (1ll * vec[m] * vec[m] <= 2 * a * a) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    if (r == -1) {
        return (2 * a > vec[0]) ? vec[0] : -1;
    }
    else {
        if (r + 1 < vec.size() && 2 * a > vec[r + 1]) {
            return (f(vec[r + 1], a) < f(vec[r], a)) ? vec[r + 1] : vec[r];
        }
        else {
            return vec[r];
        }
        
    } 
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    while (start < n) {
        start <<= 1;
    }
    for (int i = 0; i < n; i++) {
        tree[start + i].resize(1);
        cin >> tree[start + i][0];
    }
    for (int i = start - 1; i > 0; i--) {
        merge(tree[2 * i], tree[2 * i + 1], tree[i]);
    }
    
    while (q--) {
        int l, r, a;
        cin >> l >> r >> a;
        l += start - 1;
        r += start - 1;
        
        int res = 0;
        while (l <= r) {
            if (l % 2) {
                int ans = bin_search(tree[l], a);
                if (ans != -1 && (res == 0 || f(ans, a) < f(res, a))) {
                    res = ans;
                }
                l++;
            }
            if (r % 2 == 0) {
                int ans = bin_search(tree[r], a);
                if (ans != -1 && (res == 0 || f(ans, a) < f(res, a))) {
                    res = ans;
                }
                r--;
            }
            r /= 2;
            l /= 2;
        }
        cout << (res ? res : -1) << endl;
    }
    return 0;
}
