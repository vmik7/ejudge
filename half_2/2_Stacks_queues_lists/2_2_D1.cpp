#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

map<char, int> op = { {'+', 1}, {'-', 2}, {'*', 3}, {'/', 4}, {'^', 5}, {'#', 6} };

bool is_less(char c1, char c2) {
	return op[c1] < op[c2];
}

int main() {
	string val;
	cin >> val;

	stack<char> st_op;
	string pol = "";

	if (val.size() && val[0] == '-') val[0] = '#';
	for (int i = 0; i < (int)val.size() - 3; i++) {
		if (val[i] == '(' && val[i + 1] == '-') {
			val[i + 1] = '#';
		}
	}

	for (int i = 0; i < val.size(); i++) {
		if (val[i] == 'x' || val[i] == 'y') {
			pol += val[i];
		}
		else if (val[i] >= '0' && val[i] <= '9') {
			int num = 0;
			while (i < val.size() && val[i] >= '0' && val[i] <= '9') {
				pol += val[i];
				i++;
			}
			pol += 'n';
			i--;
		}
		else if (st_op.empty() || val[i] == '(') {
			st_op.push(val[i]);
		}
		else if (val[i] == ')') {
			while (!st_op.empty() && st_op.top() != '(') {
				pol += st_op.top();
				st_op.pop();
			}
			if (!st_op.empty())
				st_op.pop();
		}
		else {
			while (!st_op.empty() && st_op.top() != '(' && !is_less(st_op.top(), val[i])) {
				pol += st_op.top();
				st_op.pop();
			}
			st_op.push(val[i]);
		}
	}
	while (!st_op.empty()) {
		pol += st_op.top();
		st_op.pop();
	}

	int n;
	cin >> n;
	while (n--) {
		long long x, y;
		cin >> x >> y;
		stack<long long> calc;
		for (int i = 0; i < pol.size(); i++) {
			if (pol[i] == 'x')
				calc.push(x);
			else if (pol[i] == 'y')
				calc.push(y);
			else if (pol[i] >= '0' && pol[i] <= '9') {
				long long num = 0;
				while (i < pol.size() && pol[i] >= '0' && pol[i] <= '9') {
					num = num * 10 + (int)(pol[i] - '0');
					i++;
				}
				calc.push(num);
			}
			else if (pol[i] == '+') {
				long long b = calc.top();
				calc.pop();
				long long a = calc.top();
				calc.pop();
				calc.push(a + b);
			}
			else if (pol[i] == '-') {
				long long b = calc.top();
				calc.pop();
				long long a = calc.top();
				calc.pop();
				calc.push(a - b);
			}
			else if (pol[i] == '*') {
				long long b = calc.top();
				calc.pop();
				long long a = calc.top();
				calc.pop();
				calc.push(a * b);
			}
			else if (pol[i] == '/') {
				long long b = calc.top();
				calc.pop();
				long long a = calc.top();
				calc.pop();
				calc.push(a / b);
			}
			else if (pol[i] == '^') {
				long long b = calc.top();
				calc.pop();
				long long a = calc.top();
				calc.pop();
				long long ans = 1;
				if (b < 0) ans = 0;
				while (b > 0) {
					if (b % 2) ans *= a;
					a *= a;
					b /= 2;
				}
				calc.push(ans);
			}
			else if (pol[i] == '#') {
				long long a = calc.top();
				calc.pop();
				calc.push(-a);
			}
		}
		cout << calc.top() << endl;
		calc.pop();
	}
	return 0;
}
