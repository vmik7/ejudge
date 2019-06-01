#include <iostream>
#include <string>
#include <vector>

using namespace std;

int p[2000001];

int main() {
	string a, b;
	cin >> a >> b;

	a = b + '#' + a;

	vector<int> vec;
	for (int i = 1; i < a.size(); i++) {
		int j = p[i - 1];
		while (j > 0 && a[i] != a[j]) {
			j = p[j - 1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		if (j == b.size()) {
			vec.push_back(i - 2 * j + 1);
		}
		p[i] = j;
	}

	cout << vec.size() << endl;
	if (vec.size()) {
		cout << vec[0];
		for (int i = 1; i < vec.size(); i++) {
			cout << " " << vec[i];
		} cout << endl;
	}

	return 0;
}
