#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
int coor[50001][2];

int main()
{
	int n;
	cin >> n;
	cin >> coor[0][0] >> coor[0][1];
	coor[n][0] = coor[0][0];
	coor[n][1] = coor[0][1];
	for (int i = 1; i < n; i++) {
		cin >> coor[i][0] >> coor[i][1];
	}
	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += coor[i][0] * coor[i + 1][1];
		sum2 += coor[i][1] * coor[i + 1][0];
	}
	double ans = round(((double)abs(sum1 - sum2) / 2) * 10) / 10;
	cout << fixed << setprecision(1) << ans << endl;
	return 0;
}
