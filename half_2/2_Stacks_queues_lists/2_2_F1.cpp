#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

struct book {
	int num;
	book * prev;
	book * next;
} *start, *last;

void push(int num, char nav = 'r') {
	book * val = new book;
	val->num = num;
	val->prev = NULL;
	val->next = NULL;
	if (start == NULL, last == NULL) {
		start = val;
		last = val;
	}
	else if (nav == 'r') {
		val->prev = last;
		last->next = val;
		last = val;
	}
	else if (nav == 'l') {
		val->next = start;
		start->prev = val;
		start = val;
	}
	return;
}

void pop(char nav) {
	int num;
	if (nav == 'r') {
		num = last->num;
		book * temp = last->prev;
		delete last;
		last = temp;
		if (last != NULL) last->next = NULL;
	}
	else if (nav == 'l') {
		num = start->num;
		book * temp = start->next;
		delete start;
		start = temp;
		if (start != NULL) start->prev = NULL;
	}
	printf("%d\n", num);
	return;
}

int main() {
	char nav, temp;
	while (scanf("%c", &nav) != EOF) {
		if (nav == '1' || nav == '2') {
			int num;
			scanf("%d", &num);
			if (nav == '1') push(num, 'l');
			if (nav == '2') push(num, 'r');
		}
		else if (nav == '3') pop('l');
		else if (nav == '4') pop('r');
	}
	while (start != NULL) {
		book * temp = start->next;
		delete start;
		start = temp;
	}
	return 0;
}
