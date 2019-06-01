#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int n_a = c / a;
	int n_b = 0;
	while (n_a > 0 && c - (n_a - 1)* a - n_b * b >= b) {
		n_b++;
		n_a--;
	}
	cout << n_a * a + n_b * b << endl;
	return 0;
}
