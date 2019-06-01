#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
};

bool operator==(point a, point b) {
	return a.x == b.x && a.y == b.y;
}

double getDist(point a, point b, point c) {
	if ((b.x - a.x) * (c.x - b.x) + (b.y - a.y) * (c.y - b.y) > 0) {
		return sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));
	}
	if ((a.x - b.x) * (c.x - a.x) + (a.y - b.y) * (c.y - a.y) > 0) {
		return sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y));
	}
	return fabs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) / sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

const double EPS = 10e-11;
bool isLess(double a, double b) {
	return a < b - EPS;
}

int main() {
	point arr[4];
	for (int i = 0; i < 4; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	if (arr[0].y > arr[1].y || arr[0].y == arr[1].y && arr[0].x > arr[1].x) {
		swap(arr[0], arr[1]);
	}
	if (arr[2].y > arr[3].y || arr[2].y == arr[3].y && arr[2].x > arr[3].x) {
		swap(arr[2], arr[3]);
	}

	long long d = (arr[1].x - arr[0].x) * (arr[2].y - arr[3].y) - (arr[2].x - arr[3].x) * (arr[1].y - arr[0].y);
	long long dl = (arr[2].x - arr[0].x) * (arr[2].y - arr[3].y) - (arr[2].x - arr[3].x) * (arr[2].y - arr[0].y);
	long long dm = (arr[1].x - arr[0].x) * (arr[2].y - arr[0].y) - (arr[2].x - arr[0].x) * (arr[1].y - arr[0].y);

	if ((d > 0 && dl >= 0 && dl <= d && dm >= 0 && dm <= d || d < 0 && dl <= 0 && dl >= d && dm <= 0 && dm >= d) || dl == 0 && dm == 0 && !((arr[2].x > arr[1].x || arr[2].x == arr[1].x && arr[2].y > arr[1].y) || (arr[0].x > arr[3].x || arr[0].x == arr[3].x && arr[0].y > arr[3].y))) {
		cout << fixed << setprecision(10) << (double)(0) << endl;
		return 0;
	}

	double ans[4];
	ans[0] = getDist(arr[0], arr[1], arr[2]);
	ans[1] = getDist(arr[0], arr[1], arr[3]);
	ans[2] = getDist(arr[2], arr[3], arr[0]);
	ans[3] = getDist(arr[2], arr[3], arr[1]);

	sort(ans, ans + 4, isLess);
	cout << fixed << setprecision(10) << ans[0] << endl;
	return 0;
}
