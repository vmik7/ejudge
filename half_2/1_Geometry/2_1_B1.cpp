#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
	int x, y;
	double ans;
	cin >> x >> y;
	if (x == 0) {
		if (y > 0) ans = M_PI / 2;
		else ans = M_PI * 3 / 2;
	}
	else {
		if (x > 0 && y >= 0) ans = atan(double(y) / x);
		else if (x > 0 && y < 0) ans = M_PI * 2 - atan(double(-y) / x);
		else if (x < 0 && y >= 0) ans = M_PI - atan(double(y) / (-x));
		else if (x < 0 && y < 0) ans = M_PI + atan(double(-y) / (-x));
	}
	ans = round(ans * 1000000) / 1000000;
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
