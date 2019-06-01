#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
	int x, y;
};

bool cmp(point a, point b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

vector<point> pts;

int sign(long long val) {
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

long long orient(point a, point b, point c) {
	return sign(1ll * a.x * (b.y - c.y) + 1ll * b.x * (c.y - a.y) + 1ll * c.x * (a.y - b.y));
}

void convex_hull(vector<point> & p) {
	if (p.size() <= 2) return;
	sort(p.begin(), p.end(), cmp);
	point a = p.front(), b = p.back();
	vector<point> up, down;
	up.push_back(a);
	down.push_back(a);
	for (int i = 1; i < p.size(); i++) {
		if (i == p.size() - 1 || orient(a, p[i], b) < 0) {
			while (up.size() >= 2 && orient(up[up.size() - 2], up[up.size() - 1], p[i]) >= 0)
				up.pop_back();
			up.push_back(p[i]);
		}
		if (i == p.size() - 1 || orient(a, p[i], b) > 0) {
			while (down.size() >= 2 && orient(down[down.size() - 2], down[down.size() - 1], p[i]) <= 0)
				down.pop_back();
			down.push_back(p[i]);
		}
	}
	p.clear();
	for (int i = 0; i < up.size(); i++)
		p.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		p.push_back(down[i]);
}

long long calc_s(vector<point> & p) {
	long long sum = 0;
	for (int i = 0; i < p.size(); i++) {
		sum += 1ll * p[i].x * p[(i + 1) % p.size()].y;
	}
	for (int i = 0; i < p.size(); i++) {
		sum -= 1ll * p[i].y * p[(i + 1) % p.size()].x;
	}
	return sum < 0 ? -sum : sum;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		point t;
		cin >> t.x >> t.y;
		pts.push_back(t);
	}
	convex_hull(pts);
	cout << calc_s(pts) << endl;
	return 0;
}
