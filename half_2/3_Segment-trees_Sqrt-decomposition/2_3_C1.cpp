#include <iostream>

using namespace std;

const int Start = 1048576;
long long t[Start + 1000001];

void increase(int i) {
	int index = i + Start;
	while (index > 0) {
		t[index] += i;
		index /= 2;
	}
	return;
}

long long getSum(int l, int r) {
	l += Start;
	r += Start;
	long long sum = 0;
	while (l <= r) {
		if (l % 2) {
			sum += t[l];
			l++;
		}
		if (r % 2 == 0) {
			sum += t[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		increase(val);
		sum += getSum(0, val - 1);
	}
	cout << sum << endl;
	return 0;
}
