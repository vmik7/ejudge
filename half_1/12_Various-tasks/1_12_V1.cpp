#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		long long l1 = l, r1;

		if (l1 % 4) l1 += 4 - l % 4;
		r1 = r - r % 4;
		int four = r1 < l1 ? 0 : (r1 - l1) / 4 + 1;

		l1 = l;
		if (l1 % 7) l1 += 7 - l % 7;
		r1 = r - r % 7;
		int seven = r1 < l1 ? 0 : (r1 - l1) / 7 + 1;

		l1 = l;
		if (l1 % 28) l1 += 28 - l % 28;
		r1 = r - r % 28;
		int fs = r1 < l1 ? 0 : (r1 - l1) / 28 + 1;

		cout << four + seven - fs << endl;
	}
	return 0;
}