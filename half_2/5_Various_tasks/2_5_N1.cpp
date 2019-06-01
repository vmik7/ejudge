#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

const int N = 100;

char s[2 * N + 1];
int p[2 * N];


bool check(char * s, int * p, int len) {
	p[0] = 0;
	int cnt = 0;
	for (int i = 1; i < strlen(s); i++) {
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i]) {
			j = p[j - 1];
		}
		if (s[j] == s[i]) {
			j++;
		}
		if (j == len) {
			cnt++;
			if (cnt == 2) return true;
		}
		p[i] = j;
	}
	return false;
}

int main() {
	scanf("%s", s + N);
	int n = strlen(s + N);
	s[N - 1] = '#';

	for (int l = n - 1; l > 0; l--) {
		for (int i = 0; i < n - l + 1; i++) {
			for (int j = 0; j < l; j++) {
				s[N - 1 - l + j] = s[N + i + j];
			}
			char * ps = s + N - 1 - l;
			if (check(ps, p + N - 1 - l, l)) {
				printf("%d\n", l);
				return 0;
			}
		}
	}

	printf("0\n");
	return 0;
}
