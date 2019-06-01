#include <iostream>

using namespace std;

int n = 0;
const int MaxN = 2 * (int)10e5;
int h[MaxN + 1];

template <class T>
void exchange(T & a, T & b) {
	T temp = a;
	a = b;
	b = temp;
}

void upDown(int index) {
	while (2 * index < n) {
		int max_index = (h[2 * index + 1] > h[2 * index]) ? (2 * index + 1) : (2 * index);
		if (h[index] >= h[max_index]) {
			break;
		}
		exchange(h[max_index], h[index]);
		index = max_index;
	}
	if (2 * index == n && h[2 * index] > h[index]) {
		exchange(h[2 * index], h[index]);
	}
	return;
}

void insert(int val) {
	n++;
	int index = n;
	h[n] = val;
	while (index / 2 && h[index / 2] < h[index]) {
		exchange(h[index / 2], h[index]);
		index /= 2;
	}
	return;
}

int delMax() {
	int result = h[1];
	exchange(h[1], h[n]);
	n--;
	upDown(1);
	return result;
}

int main() {
	char command;
	while (cin) {
		command = cin.get();
		if (command == 'I') {
			static int num;
			cin >> num;
			cin.get();
			insert(num);
		}
		else if (command == 'D') {
			cin.get();
			cout << delMax() << endl;
		}
	}
	return 0;
}
