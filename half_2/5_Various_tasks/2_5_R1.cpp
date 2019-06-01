#include <iostream>
#include <string>

using namespace std;

int p[2000001];

int main() {
	string a, b;
	cin >> a >> b;

	a = b + '#' + a;

	for (int i = 1; i < a.size(); i++) {
		int j = p[i - 1];
		while (j > 0 && a[i] != a[j]) {
			j = p[j - 1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		if (j == b.size()) {
			cout << "YES" << endl;
			return 0;
		}
		p[i] = j;
	}

	cout << "NO" << endl;
	return 0;
}
