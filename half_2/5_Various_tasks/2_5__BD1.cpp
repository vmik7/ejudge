#include <iostream>

using namespace std;

struct point {
	int x, y;
	bool operator == (point p) {
		return this->x == p.x && this->y == p.y;
	}
};

int n;
point m;
point p[100000];

int main() {
	cin >> n >> m.x >> m.y;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		if (p[i] == m) {
			cout << "YES" << endl;
			return 0;
		}
	}

	int inter_cnt = 0;

	for (int i = 0; i < n; i++) {
		point a = p[i];
		point b = p[(i + 1) % n];
		if (a.y == m.y && b.y == m.y && (a.x < m.x && m.x < b.x || a.x > m.x && m.x > b.x)) {
			cout << "YES" << endl;
			return 0;
		}
		if (a.x == m.x && b.x == m.x && (a.y < m.y && m.y < b.y || a.y > m.y && m.y > b.y)) {
			cout << "YES" << endl;
			return 0;
		}
		if (a.y == m.y && a.x > m.x && b.y < m.y || b.y == m.y && b.x > m.x && a.y < m.y) {
			inter_cnt++;
		}
		if ((b.y < m.y && m.y < a.y || b.y > m.y && m.y > a.y) && (b.x > m.x || a.x > m.x)) {
			int s = 1ll * (a.y - b.y) * ((a.x - m.x) * (a.y - b.y) - (a.x - b.x) * (a.y - m.y));
			if (s == 0) {
				cout << "YES" << endl;
				return 0;
			}
			else if (s > 0) {
				inter_cnt++;
			}
		}

	}
	cout << (inter_cnt % 2 ? "YES" : "NO") << endl;
	return 0;
}
