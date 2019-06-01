#include <iostream>

using namespace std;

const int A = 0;
const int B = 1;

int main()
{
	int baskets[3][2], a, b;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			cin >> baskets[i][j];

	if (baskets[1][B] <= baskets[0][B] && baskets[2][A] <= baskets[0][A])
	{
		a = baskets[0][A] - baskets[2][A];
		b = baskets[0][B] - baskets[1][B];
	}
	else
	{
		a = baskets[0][A] - baskets[1][A];
		b = baskets[0][B] - baskets[2][B];
	}

	cout << a << " " << b << endl;

	//system("pause");
	return 0;
}