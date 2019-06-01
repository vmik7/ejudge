#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int num[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 3; i++)
	{
		if (num[i] < 0) num[i] = pow(num[i], 2);
		else if (num[i] > 0) num[i] = pow(num[i], 3);
	}

	for (int i = 0; i < 3; i++)
	{
		cout << num[i] << ' ';
	}


	//system("pause");
	return 0;
}