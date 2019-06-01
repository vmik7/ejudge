#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string, greater<string>> s;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int n = str.size();
		for (int i = 0; i < n; i++) {
			s.insert(str);
			str = str.substr(1, n - 1) + str[0];
		}
		cout << *s.begin() << endl;
		s.clear();
	}
	return 0;
}
