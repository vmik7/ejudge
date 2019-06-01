#include <iostream>
#include <set>
#include <iterator>

using namespace std;

set<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	if (s.size() == 1) {
		cout << "NO" << endl;
	}
	else {
		auto it = s.begin();
		cout << *(++it) << endl;
	}
	return 0;
}
