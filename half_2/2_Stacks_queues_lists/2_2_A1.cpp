#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> s;
	int count = 0;
	char c = cin.get();
	while (c != '\n') {
		if (c == '(')
			s.push(c);
		else if (c == ')' && s.empty())
			count++;
		else
			s.pop();
		c = cin.get();
	}
	count += s.size();
	cout << count << endl;
	return 0;
}
