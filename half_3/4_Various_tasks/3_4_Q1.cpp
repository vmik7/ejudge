#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, ans = 3;
		cin >> n;
		while (n-- > 1) ans *= 2;
		cout << ans << endl;
	}

	return 0;
}
