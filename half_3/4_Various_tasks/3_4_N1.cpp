#include <iostream>

using namespace std;

int sum(int n) {
	int s = 0;
	while (n) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		while (n > 0) {
			n -= sum(n);
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
