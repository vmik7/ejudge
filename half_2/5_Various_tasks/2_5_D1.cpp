#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

const int N = 10000;

vector<int> convert(long long val) {
	vector<int> res;
	while (val) {
		res.push_back(val % N);
		val /= N;
	}
	return res;
}

void mul(vector<int> & val, long long num) {
	int carry = 0;
	for (int i = 0; i < val.size(); i++) {
		int ans = (val[i] * num + carry) % N;
		carry = (val[i] * num + carry) / N;
		val[i] = ans;
	}
	if (carry) val.push_back(carry);
	return;
}

void display(vector<int> val) {
	cout << val[val.size() - 1];
	for (int i = val.size() - 2; i >= 0; i--) {
		for (int j = 1000; j >= 10; j /= 10) {
			if (val[i] / j == 0)
				cout << "0";
		}
		cout << val[i];
	}
}

int main() {
	freopen("paint.dat", "r", stdin);
	freopen("paint.sol", "w", stdout);
	int n, k;
	cin >> k >> n;
	long long a = 1;
	for (int i = k - 4 + 1; i <= k; i++) a *= i;
	vector<int> ans = convert(a);
	a--;
	n--;
	while (n--) mul(ans, a);
	display(ans);
	return 0;
}
