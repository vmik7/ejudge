#include <iostream>

using namespace std;

const int N = 2097152;
long long t[N];
long long inc[N];
int start = 1;

/*
void update(int index, long long val) {
    index += start;
    t[index] = val;
    while (index / 2) {
        index /= 2;
        t[index] = t[2 * index] + t[2 * index + 1];
    }
    return;
}
*/
/*
long long getSum(int l, int r) {
    l += start;
    r += start;
    long long sum = 0;
    while (l <= r) {
        if (l % 2) {
            sum += t[l];
            l++;
        }
        if (r % 2 == 0) {
            sum += t[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}
*/
/*
void increase(int v, int tl, int tr, int x) {
    inc[v] += x;
    t[v] += (tr - tl + 1) * x;
    return;
}
*/
/*
void push(int v, int tl, int tr) {
    int m = (tl + tr) / 2;
    increase(2 * v, tl, m, inc[v]);
    increase(2 * v + 1, m + 1, tr, inc[v]);
    inc[v] = 0;
    return;
}
*/

void update(int v, int tl, int tr, int pos, int x) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        t[v] = x;
        return;
    }
    int m = (tl + tr) / 2;
    update(2 * v, tl, m, pos, x);
    update(2 * v + 1, m + 1, tr, pos, x);
    t[v] = t[2 * v] + t[v * 2 + 1];
    return;
}

long long getSum(int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l) return 0;
    if (l <= tl && tr <= r) return t[v];
    int m = (tl + tr) / 2;
    return getSum(2 * v, tl, m, l, r) + getSum(2 * v + 1, m + 1, tr, l, r);
}

int main() {
    int n, k;
    cin >> n >> k;

    while (start < n) {
        start <<= 1;
    }

    while (k--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, val;
            cin >> i >> val;
            update(1, 0, start - 1, i - 1, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << getSum(1, 0, start - 1, l - 1, r - 1) << endl;
        }
    }

    return 0;
}
