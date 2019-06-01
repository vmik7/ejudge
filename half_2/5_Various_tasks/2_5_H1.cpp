#include <iostream>
#include <algorithm>

using namespace std;

int arr[50];

int main() {
	freopen("sum.dat", "r", stdin);
	freopen("sum.sol", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	long long sum = 0;
	for (int i = 0; i < n && arr[i] - sum <= 1; i++) {
		sum += arr[i];
	}
	cout << sum + 1 << endl;
	return 0;
}
