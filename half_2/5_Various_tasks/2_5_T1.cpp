#include <iostream>

using namespace std;

int fib[32];

int main() {
	int n, count = 0;
	cin >> n;
	count = n / 5;
	int val = n % 5;
	while (val % 2 && val <= n && count) {
		val += 5;
		count -= 1;
	}
	count += val / 2;
	cout << count << endl;
	return 0;
}
