#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point {
	int x, y;
};

double getDist(point a, point b, point c) {
	if ((b.x - a.x) * (c.x - b.x) + (b.y - a.y) * (c.y - b.y) > 0) {
		return sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));
	}
	if ((a.x - b.x) * (c.x - a.x) + (a.y - b.y) * (c.y - a.y) > 0) {
		return sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y));
	}
	return fabs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) / sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << fixed << setprecision(10) << getDist(a, b, c) << endl;
	return 0;
}
