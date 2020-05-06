#include <iostream>

using namespace std;

const int N = 6;
int a[N] = { 500, 200, 100, 50, 20, 10 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < N && n; i++) {
			ans += n / a[i];
			n %= a[i];
		}
		cout << (n ? -1 : ans) << endl;
	}

	return 0;
}
