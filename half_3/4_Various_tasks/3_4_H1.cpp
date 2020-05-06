#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		while (n--) {
			int t;
			cin >> t;
			if (t % 4 == 0 && t % 7) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}
