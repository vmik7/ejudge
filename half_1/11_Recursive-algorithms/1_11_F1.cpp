#include <iostream>
#include <string>

using namespace std;

long long super_puper(long long num);

int main()
{
	string str;
	int k;
	cin >> str >> k;
	long long sum = 0;
	for (int i = 0; i < str.size(); i++)
		sum += str[i] - '0';
	sum *= k;

	cout << super_puper(sum) << endl;

	//system("pause");
	return 0;
}


long long super_puper(long long num)
{
	if (num < 10) return num;
	long long sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return super_puper(sum);
}