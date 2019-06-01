#include <iostream>

using namespace std;

int fib[32];

int main() {
	int n;
	cin >> n;
	if (n >= 1) cout << 1 << endl;
	if (n >= 2) cout << 1 << endl;
	fib[1] = 1;
	fib[2] = 1;
	for (int i = 3; i <= 31 && i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		cout << fib[i] << endl;
	}
	return 0;
}
