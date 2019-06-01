#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int arr[20][2000];

int main() {
	freopen("kare.dat", "r", stdin);
	freopen("kare.sol", "w", stdout);
	set<int> s;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			s.insert(arr[i][j]);
		}
	}
	for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
		int val = *i;
		int count = 0;
		for (int i = 0; i < n; i++) {
			int l = -1;
			int r = m - 1;
			while (l < r) {
				int middle = (l + r + 1) / 2;
				if (arr[i][middle] <= val) {
					l = middle;
				}
				else {
					r = middle - 1;
				}
			}
			if (l != -1 && arr[i][l] == val) {
				count++;
			}
		}
		cout << val << " " << count << endl;
	}
	return 0;
}
