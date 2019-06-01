#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[1000001];
int p[1000001];


int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", &a);

	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && a[i] != a[j]) {
			j = p[j - 1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		p[i] = j;
	}

	bool find = false;
	int j = 0;
	char c;
	for (int i = 0; scanf("%c", &c) != EOF; i++) {
		while (j > 0 && a[j] != c) {
			j = p[j - 1];
		}
		if (a[j] == c) {
			j++;
		}
		if (j == n) {
			printf("%d\n", i - n);
			find = true;
		}
	}

	if (!find) {
		printf("-1");
	}

	return 0;
}
