#include <iostream>

using namespace std;

int findLen(int x1, int y1, int x2, int y2) { return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1); }

int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4, a, b, c, d, l1, l2;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	a = findLen(x1, y1, x2, y2);
	b = findLen(x2, y2, x3, y3);
	c = findLen(x3, y3, x4, y4);
	d = findLen(x4, y4, x1, y1);
	l1 = findLen(x1, y1, x3, y3);
	l2 = findLen(x2, y2, x4, y4);
	if (a == b && b == c & c == d && d == a) {
		if (l1 == l2) cout << 4 << endl;
		else cout << 2 << endl;
	}
	else if (b == d && a == c) {
		if (l1 == l2) cout << 2 << endl;
		else cout << 0 << endl;
	}
	else if ((b == d || a == c) && l1 == l2) cout << 1 << endl;           
        else if((a == d && b == c) || (c == d && a == b)) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
