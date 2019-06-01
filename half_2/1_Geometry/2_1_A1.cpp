#include <iostream>

using namespace std;
//cell coordinates - coordinates of left lower corner
bool map[2000][2000];
int r;

void fillCell(int x, int y, bool val = true) {
	if (x >= -r && x < r && y >= -r && y < r) map[x + r][y + r] = val;
}

bool checkCell(int x, int y) {
	if (x >= -r && x < r && y >= -r && y < r) return map[x + r][y + r];
}

bool innerCell(int x, int y, bool fill = false) {
	bool is_inner = ((x + 1) * (x + 1) + y * y <= r * r) &&
		     ((x + 1) * (x + 1) + (y + 1) * (y + 1) <= r * r) &&
		     (x * x + (y + 1) * (y + 1) <= r * r) &&
		     (x * x + y * y <= r * r);
	if (is_inner && fill) map[x + r][y + r] = true;
	return is_inner;
}

int main()
{
	cin >> r;
	int x, y = 0, count = 0;
	for (x = -r; x < 0 && !checkCell(x,y); x++) {
		while (innerCell(x, y)) {
			fillCell(x, y);
			fillCell(y, x);
			fillCell(x, -y - 1);
			fillCell(-y - 1, x);
			fillCell(-x - 1, y);
			fillCell(y, -x - 1);
			fillCell(-x - 1, -y - 1);
			fillCell(-y - 1, -x - 1);
			y++;
		}
	}
	for (int i = 1; i < r; i++)	{
		for (int j = 1; j < r; j++) {
			if (map[i][j] == false) continue;
			count += 2 * (r - j);
			break;
		}
	}
	count *= 2;

	cout << count << endl;
	return 0;
}
