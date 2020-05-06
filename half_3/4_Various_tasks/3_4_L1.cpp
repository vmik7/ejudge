#include <iostream>

using namespace std;

int gcd(int a, int b) { 
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	int t, a, b, ans;
	cin >> t;

	while (t--) {
		cin >> a >> b;
		if (a == 0 && b == 0) ans = 1;
		else ans = gcd(a, b);
		cout << ans << endl;
	}

	return 0;
}
