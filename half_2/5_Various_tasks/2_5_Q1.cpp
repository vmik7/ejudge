#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char a[101];
int pa[100];
char b[101];
int pb[100];
char c[100001];
int n = 0;

void prefix(char * s, int * p) {
	for (int i = 1; i < strlen(s); i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		p[i] = j;
	}
	return;
}

void reverse(char * s) {
	int l = 0, r = strlen(s) - 1;
	while (l < r) {
		char t = s[l];
		s[l] = s[r];
		s[r] = t;
		l++;
		r--;
	}
}

bool check(char * c) {
	int j = 0;
	char * s = a;
	int * p = pa;
	bool find_a = false;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[j] != c[i]) {
			j = p[j - 1];
		}
		if (s[j] == c[i]) {
			j++;
		}
		if (j == strlen(s)) {
			if (!find_a) {
				find_a = true;
				j = 0;
				s = b;
				p = pb;
			}
			else {
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%s", &c);
	scanf("%s", &a);
	scanf("%s", &b);
	n = strlen(c);

	int ans = 0;
	prefix(a, pa);
	prefix(b, pb);

	if (check(c)) ans |= 1;
	reverse(c);
	if (check(c)) ans |= 2;

	switch (ans) {
	case 3: printf("both\n");
		break;
	case 2: printf("backward\n");
		break;
	case 1:	printf("forward\n");
		break;
	default: printf("fantasy\n");
	}

	return 0;
}
