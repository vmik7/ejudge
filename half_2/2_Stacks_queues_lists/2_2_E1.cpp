#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> stk;
	int n, ball, max_ball = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ball;
		if (stk.empty() || ball > max_ball) {
			for (int j = max_ball + 1; j < ball; j++) {
				stk.push(j);
			}
			max_ball = ball;
		}
		else if (stk.top() == ball) {
			stk.pop();
		}
		else {
			cout << "Cheater" << endl;
			return 0;
		}
	}
	if (stk.empty() && max_ball == n) {
		cout << "Not a proof" << endl;
	}
	else {
		cout << "Cheater" << endl;
	}
	return 0;
}
