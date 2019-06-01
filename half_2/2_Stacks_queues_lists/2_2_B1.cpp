#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	(cin >> n).get();
	while (n--) {
		stack<char> s;
		bool correct = true;
		char c = cin.get();
		while (c != '\n') {
			if (c == ')') {
				if (s.empty() || s.top() != '(') {
					while (cin.get() != '\n');
					correct = false;
					break;
				}
				else {
					s.pop();
				}
			}
			else if (c == ']') {
				if (s.empty() || s.top() != '[') {
					while (cin.get() != '\n');
					correct = false;
					break;
				}
				else {
					s.pop();
				}
			}
			else {
				s.push(c);
			}
			c = cin.get();
		}
		if (correct && s.empty())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
