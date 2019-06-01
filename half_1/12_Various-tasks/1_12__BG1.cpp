#include <iostream>

using namespace std;

int main()
{
	int r, n, c = 1;
	cin >> r >> n;
	while (r != 0 || n != 0)
	{
		cout << "Case " << c << ": ";
		int count = r / n;
		if (r % n == 0) count--;
		if (count <= 26)	cout << count << endl;
		else				cout << "impossible" << endl;
		cin >> r >> n;
		c++;
	}
	//system("pause");
	return 0;
}