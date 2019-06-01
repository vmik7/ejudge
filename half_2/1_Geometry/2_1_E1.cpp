#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	long long num = (x1 * y2 - y1 * x2) * (x4 - x3) - (x3 * y4 - y3 * x4) * (x2 - x1);
	long long denom = (y2 - y1) * (x4 - x3) - (y4 - y3) * (x2 - x1);
	if (denom == 0) {
		if (num == 0) cout << 2 << endl;
		else cout << 0 << endl;
	}
	else {
		double x = (double)(num) / denom;
		double y = (x * (y2 - y1) - x1 * y2 + y1 * x2) / (x2 - x1);
		cout << "1 " << fixed << setprecision(6) << x << " " << y << endl;
	}
	return 0;
}
