#include <iostream>
#include <vector>

using namespace std;

struct position {
	int x, y, w, prev;
} que[10000];

struct point {
	int x, y;
};

bool board[101][101];

int main() {
	int m, n, p, q, x1, y1, x2, y2;
	cin >> m >> n >> p >> q >> x1 >> y1 >> x2 >> y2;
	
	if (x1 == x2 && y1 == y2) {
		cout << 0 << endl;
		cout << x1 << " " << x2 << endl;
		return 0;
	}

	int dx[8] = { -q, -p, p, q, q, p, -p, -q };
	int dy[8] = { -p, -q, -q, -p, p, q, q, p };
	que[0] = { x1, y1, 0, -1 };
	board[x1][y1] = 1;
	int start = 0, last = 1;

	while (start != last) {
		for (int i = 0; i < 8; i++) {
			int x = que[start].x + dx[i];
			int y = que[start].y + dy[i];
			if (x > 0 && x <= m && y > 0 && y <= n && !board[x][y]) {
				if (x == x2 && y == y2) {
					cout << que[start].w + 1 << endl;
					vector<point> v;
					point p = { x, y };
					v.push_back(p);
					while (start >= 0) {
						p = { que[start].x, que[start].y };
						v.push_back(p);
						start = que[start].prev;
					}
					for (int j = v.size() - 1; j >= 0; j--) {
						cout << v[j].x << " " << v[j].y << endl;
					}
					return 0;
				}
				board[x][y] = 1;
				que[last] = { x, y, que[start].w + 1, start };
				last++;
			}
		}
		start++;
	}
	cout << -1 << endl;
	return 0;
}
