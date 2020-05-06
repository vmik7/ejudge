#include <iostream>

using namespace std;

int gcd(int a, int b) { 
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		cin >> n >> a;
		do {
			cin >> b;
			a = gcd(a, b);
			n--;
		} while (n > 1);
		cout << a << endl;
	}

	return 0;
}
