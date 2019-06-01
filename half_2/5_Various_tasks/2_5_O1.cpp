#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main() {
	int n;
	cin >> n;
	
	do {
		dq.push_front(n);
		for (int i = 0; i < n; i++) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	} while (--n);

	cout << dq.front();
	dq.pop_front();
	while (!dq.empty()) {
		cout << " " << dq.front();
		dq.pop_front();
	}
	cout << endl;

	return 0;
}
