#include <iostream>
#include <vector>

using namespace std;

struct point {
	int x;
	int y;
};

bool operator==(point p1, point p2) {
	if (p1.x == p2.x && p1.y == p2.y) return true;
	return false;
}

int sign(point p1, point p2, point p3) {
	int s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if (s > 0) return 1;
	if (s < 0) return -1;
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<point> p(n);
	vector<int> signs(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	point c;
	cin >> c.x >> c.y;

	for (int i = 0; i < n; i++) {
		signs[i] = sign(p[i], p[(i + 1) % n], c);
	}
	
	for (int i = 0; i < n; i++) {
		if (signs[i] == 0) {
			int li = i, ri = (i + 1) % n;
			if (c.x < p[li].x && c.x < p[ri].x || c.x > p[li].x && c.x > p[ri].x
		     || c.y < p[li].y && c.y < p[ri].y || c.y > p[li].y && c.y > p[ri].y) {
				cout << "OUTSIDE" << endl;
				return 0;
			}
			else {
				cout << "ON BORDER" << endl;
				return 0;
			}
		}
		else if (signs[i] != signs[0]) {
			cout << "OUTSIDE" << endl;
			return 0;
		}
	}
	cout << "INSIDE" << endl;
	return 0;
}
