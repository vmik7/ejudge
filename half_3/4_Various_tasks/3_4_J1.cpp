#include <iostream>
#include <set>

using namespace std;

char digits[10];

int main() {
	for (int i = 0; i < 10; i++) digits[i] = i + '0';

	int t;
	(cin >> t).get();

	while (t--) {
		set<char> s(digits, digits + 10);
		char c = cin.get();
		while (c != '\n') {
			s.erase(c);
			c = cin.get();
		}
		cout << s.size() << endl;
		if (s.size()) {
			auto it = s.begin();
			cout << *(it++);
			while (it != s.end()) {
				cout << " " << *(it++);
			}
		}
		cout << endl;
	}

	return 0;
}
