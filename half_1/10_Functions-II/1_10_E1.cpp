#include <iostream>
#include <cstring>

using namespace std;

const int Digits = 1000;
char a_str[Digits + 1];
char b_str[Digits + 1];

void ReadLong(char *s, int *A);
void SumLong(int *A, int *B, int *C);

int main()
{
	cin.getline(a_str, Digits + 1, '\n');
	int a[Digits / 4];
	ReadLong(a_str, a);

	cin.getline(b_str, Digits + 1, '\n');
	int b[Digits / 4];
	ReadLong(b_str, b);

	int c[Digits / 4 + 1];
	SumLong(a, b, c);

	printf("%d", c[c[0]]);
	for (int i = c[0] - 1; i >= 1; i--)
	{
		printf("%04d", c[i]);
	}
	printf("%c", '\n');

	//system("pause");
	return 0;
}


void ReadLong(char *s, int *A)
{
	A[0] = 0;
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


void SumLong(int *A, int *B, int *C)
{
	C[0] = 0;
	int carry = 0;
	for (int i = 1; i <= (A[0] > B[0] ? A[0] : B[0]); i++)
	{
		C[0]++;
		C[i] = carry;
		if (i <= A[0]) C[i] += A[i];
		if (i <= B[0]) C[i] += B[i];
		carry = C[i] / 10000;
		C[i] %= 10000;
	}
	if (carry)
	{
		C[0]++;
		C[C[0]] = carry;
	}
}