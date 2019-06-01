#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int Kramer(int A[][2], int *B, double &x, double &y);

int main()
{
	int factor[2][2], fre[2];
	double x, y;
	for (int i = 0; i < 2; i++) cin >> factor[0][i];
	cin >> fre[0];
	for (int i = 0; i < 2; i++) cin >> factor[1][i];
	cin >> fre[1];
	int result = Kramer(factor, fre, x, y);

	if (result == 0) cout << "No solution!" << endl;
	else if (result == 1) cout << "Infinity!" << endl;
	else cout << fixed << setprecision(6) << x << " " << y << endl;

	//system("pause");
	return 0;
}


int Kramer(int A[][2], int *B, double &x, double &y)
{
	int d = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	int dx = B[0] * A[1][1] - A[0][1] * B[1];
	int dy = A[0][0] * B[1] - B[0] * A[1][0];
	if (d != 0)
	{
		x = (double)dx / d;
		y = (double)dy / d;
		return 2;
	}
	else
	{
		if (B[0] != 0 && B[1] != 0)
		{
			double k = 1.0;
			if (A[1][0] != 0) k = (double)A[0][0] / A[1][0];
			else if (A[1][1] != 0) k = (double)A[0][1] / A[1][1];
			double eps = 1e-9;
			if (abs((double)B[0] / B[1] - k) < eps) return 1;
		}
		else if (B[0] == 0 && B[1] == 0) return 1;
	}
	return 0;
}