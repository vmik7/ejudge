#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

struct t_cell {
	int min;
	int inc;
};

const int N = 262144;
t_cell t[N];
int start = 1;
int sum = 0;

void increase(int v, int tl, int tr, int x) {
	t[v].inc += x;
	t[v].min += x;
	return;
}

void push(int v, int tl, int tr) {
	if (t[v].inc == 0) return;
	int m = (tl + tr) / 2;
	increase(2 * v, tl, m, t[v].inc);
	increase(2 * v + 1, m + 1, tr, t[v].inc);
	t[v].inc = 0;
	return;
}

void update(int v, int tl, int tr, int l, int r, int x) {
	if (tr < l || r < tl) return;
	if (l <= tl && tr <= r) increase(v, tl, tr, x);
	else {
		push(v, tl, tr);
		int m = (tl + tr) / 2;
		update(2 * v, tl, m, l, r, x);
		update(2 * v + 1, m + 1, tr, l, r, x);
		t[v].min = min(t[2 * v].min, t[2 * v + 1].min);
	}
	return;
}

long long get_min(int v, int tl, int tr, int l, int r) {
	if (tr < l || r < tl) return 0;
	if (l <= tl && tr <= r) return t[v].min;
	push(v, tl, tr);
	int m = (tl + tr) / 2;
	return get_min(2 * v, tl, m, l, r) + get_min(2 * v + 1, m + 1, tr, l, r);
}

int main() {
	string str;
	cin >> str;

	int n = str.size();
	while (start < n) {
		start <<= 1;
	}
	for (int i = 0; i < n; i++) {
		t[start + i].min = t[start + i - 1].min + (str[i] == '(' ? 1 : -1);
	}
	sum = t[start + n - 1].min;
	for (int i = start + n; i < 2 * start; i++) {
		t[i].min = INT_MAX;
	}
	for (int i = start - 1; i > 0; i--) {
		t[i].min = min(t[2 * i].min, t[2 * i + 1].min);
	}

	int k;
	cin >> k;
	while (k--) {
		int p, inc;
		cin >> p;
		if (str[p] == '(') {
			str[p] = ')';
			inc = -2;
		}
		else {
			str[p] = '(';
			inc = 2;
		}
		sum += inc;
		update(1, 0, start - 1, p, n - 1, inc);
		if (t[1].min >= 0 && sum == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
