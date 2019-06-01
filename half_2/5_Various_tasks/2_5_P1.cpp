#include <iostream>

using namespace std;

int arr[100];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) continue;
				if (arr[i] == arr[j] + arr[k]) {
					cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
