#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	unsigned long long numbers[3] = { 0, 0, 1 };

	if (n > 2)
	{
		for (int i = 3; i <= n; i++)
		{
			unsigned long long temp = numbers[2] + numbers[1] + numbers[0];
			numbers[0] = numbers[1];
			numbers[1] = numbers[2];
			numbers[2] = temp;
		}
		cout << numbers[2] << endl;
	}
	else
	{
		cout << numbers[n] << endl;
	}


	//system("pause");
	return 0;
}