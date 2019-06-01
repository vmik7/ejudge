#include <iostream>
#include <cstring>

using namespace std;

char first[10001], second[10001];

int main()
{
	cin >> first >> second;

	int n = (strlen(first) < strlen(second) ? strlen(first) : strlen(second));

	for (int i = 0; i < n; i++)
	{
		if (first[i] < second[i])
		{
			cout << first << endl;
			//system("pause");
			return 0;
		}
		else if (first[i] > second[i])
		{
			cout << second << endl;
			//system("pause");
			return 0;
		}
	}

	if (strlen(first) == n)
	{
		cout << first << endl;
	}
	else
	{
		cout << second << endl;
	}

	//system("pause");
	return 0;
}