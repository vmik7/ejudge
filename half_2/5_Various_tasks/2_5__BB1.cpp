#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct st_el {
	int val;
	int min_val;
};

int st_count = 0;
st_el st[1000000];

int add(int val) {
	st[st_count] = { val, val };
	st_count++;
	if (st_count > 1 && st[st_count - 2].min_val < st[st_count - 1].min_val) {
		st[st_count - 1].min_val = st[st_count - 2].min_val;
	}
	return st[st_count - 1].min_val;
}

int del() {
	if (st_count == 0) return 0;
	st_count--;
	if (st_count == 0) return 0;
	return st[st_count - 1].min_val;
}

int main() {
	long long sum = 0;
	int n;
	long long a, b, c, x;
	scanf("%d %lld %lld %lld %lld", &n, &a, &b, &c, &x);
	while (n--) {
		x = (a * x * x + b * x + c) / 100 % 1000000;
		if (x % 5 >= 2) {
			sum += add(x);
		}
		else {
			sum += del();
		}
	}
	printf("%lld\n", sum);
	return 0;
}
