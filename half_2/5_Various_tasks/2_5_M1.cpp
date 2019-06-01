#include <iostream>
#include <string>

using namespace std;

string arr[101];

int main() {
	arr[0] = "trololo";

	int n, m;
	cin >> n >> m;
	cin.get();
	for (int i = 1; i <= n; i++) {
		getline(cin, arr[i]);
		if (arr[i] == arr[i - 1]) {
			cout << "NO" << endl;
			return 0;
		}
		char init = arr[i][0];
		for (int j = 1; j < m; j++) {
			if (arr[i][j] != init) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
