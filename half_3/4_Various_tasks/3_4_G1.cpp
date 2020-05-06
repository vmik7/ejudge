#include <iostream>

using namespace std;

int a[100];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, minv, maxv;
		cin >> n >> a[0];
		maxv = minv = a[0];
		for (int i = 1; i < n; i++) {
			cin >> a[i];
			if (a[i] < minv) minv = a[i];
			else if (a[i] > maxv) maxv = a[i];
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == minv) a[i] = maxv;
			else if (a[i] == maxv) a[i] = minv;
		}
		for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
		cout << a[n - 1] << endl;
	}

	return 0;
}
