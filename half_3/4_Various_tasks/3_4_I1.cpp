#include <iostream>

using namespace std;

int main() {
	int t;
	(cin >> t).get();

	while (t--) {
		char maxv = '0', c;
		do {
			c = cin.get();
			maxv = c > maxv ? c : maxv;
		} while (c != '\n');
		cout << maxv << endl;
	}

	return 0;
}
