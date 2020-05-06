#include <bits/stdc++.h>

using namespace std;

struct item { int id, s, g; };
bool cmp(item a, item b) { return min(a.s, b.g) < min(b.s, a.g); }

int main() {
	int n;
	while (cin >> n) {
		vector<item> v(n);
		for (int i = 0; i < n; i++) cin >> v[i].s;
		for (int i = 0; i < n; i++) cin >> v[i].g;

		sort(v.begin(), v.end(), cmp);

		int a = v[0].s;
		int b = a;
		for (int i = 1; i < n; i++) {
			a += v[i].s;
			b += v[i - 1].g;
			b = max(a, b);
		}
		cout << b + v[n - 1].g << endl;
	}

	return 0;
}
