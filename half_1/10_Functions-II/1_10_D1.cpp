#include <iostream>
#include <cstring>

using namespace std;

char str[1001];
int arr[250];

void ReadLong(char *s, int *A);

int main()
{
	cin.getline(str, 1001, '\n');
	ReadLong(str, arr);

	for (int i = 0; i <= arr[0]; i++)
	{
		cout << arr[i] << endl;
	}

	//system("pause");
	return 0;
}


void ReadLong(char *s, int *A)
{
	int index = 0;
	while (strlen(s) > 4)
	{
		int number = 0;
		for (int i = strlen(s) - 4; i < strlen(s); i++)
		{
			number = number * 10 + s[i] - '0';
		}
		s[strlen(s) - 4] = '\0';
		A[0]++;
		A[++index] = number;
	}
	int number = 0;
	for (int i = 0; i < strlen(s); i++)
		number = number * 10 + s[i] - '0';
	A[0]++;
	A[++index] = number;
}