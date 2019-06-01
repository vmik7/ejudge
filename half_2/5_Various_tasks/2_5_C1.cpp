#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct point {
	long long x;
	long long y;
};

int sign(point p1, point p2, point p3) {
	long long s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if (s > 0) return 1;
	if (s < 0) return -1;
	return 0;
}

int main() {
	freopen("trian.dat", "r", stdin);
	freopen("trian.sol", "w", stdout);
	vector<point> p(3);
	vector<int> signs(3);
	for (int i = 0; i < 3; i++) {
		cin >> p[i].x >> p[i].y;
	}
	point c;
	cin >> c.x >> c.y;

	for (int i = 0; i < 3; i++) {
		signs[i] = sign(p[i], p[(i + 1) % 3], c);
	}

	for (int i = 0; i < 3; i++) {
		if (signs[i] == 0) {
			int li = i, ri = (i + 1) % 3;
			if (c.x < p[li].x && c.x < p[ri].x || c.x > p[li].x && c.x > p[ri].x
				|| c.y < p[li].y && c.y < p[ri].y || c.y > p[li].y && c.y > p[ri].y) {
				cout << "NO" << endl;
				return 0;
			}
			else {
				cout << "YES" << endl;
				return 0;
			}
		}
		else if (signs[i] != signs[0]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
