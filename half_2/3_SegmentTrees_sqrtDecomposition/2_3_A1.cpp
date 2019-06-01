#include <iostream>

using namespace std;

//ceil(log(10e6)) = 20; 2^21 = 2097152
const int N = 2097152;
long long arr[N];
int start = 1;

void update(int index, long long val) {
	index += start;
	arr[index] = val;
	while (index / 2) {
		index /= 2;
		arr[index] = arr[2 * index] + arr[2 * index + 1];
	}
	return;
}

long long getSum(int l, int r) {
	l += start;
	r += start;
	long long sum = 0;
	while (l <= r) {
		if (l % 2) {
			sum += arr[l];
			l++;
		}
		if (r % 2 == 0) {
			sum += arr[r];
			r--;
		}
		l /= 2;
		r /= 2;
	}
	return sum;
}


int main() {
	int n, k;
	cin >> n >> k;

	while (start < n) {
		start <<= 1;
	}
	start -= 1;

	while (k--) {
		static int op;
		cin >> op;
		if (op == 1) {
			static int i, val;
			cin >> i >> val;
			update(i, val);
		}
		else {
			static int l, r;
			cin >> l >> r;
			cout << getSum(l, r) << endl;
		}
	}

	return 0;
}
