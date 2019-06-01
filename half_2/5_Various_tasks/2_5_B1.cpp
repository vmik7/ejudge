#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main() {
	freopen("merge.dat", "r", stdin);
	freopen("merge.sol", "w", stdout);
	priority_queue <int> q;
	int n, m, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		q.push(t);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t;
		q.push(t);
	}
	for (int i = 0; i < n + m; i++) {
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}
