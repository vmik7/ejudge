#include <iostream>
#include <iterator>
#include <map>

using namespace std;

map<int, int> m;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		while (n--) {
			int t;
			cin >> t;
			m[t]++;
		}
		pair<int, int> ans = *m.begin();
		for (auto i : m) {
			if (i.first > ans.first) ans = i;
		}
		cout << ans.second << endl;
		m.clear();
	}

	return 0;
}
