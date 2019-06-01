#include <iostream>
#include <string>
#include <vector>

const int Add_to_num = 48;
const int Add_to_Alpha = 55;

using namespace std;

int main()
{
	int base;
	string num_str;
	cin >> base >> num_str;

	unsigned long long result = 0;
	for (int i = 0; i < num_str.size(); i++)
	{
		int digit = num_str[i];
		if (digit <= 57) digit -= Add_to_num;
		else if (digit <= 90) digit -= Add_to_Alpha;
		result *= base;
		result += digit;
		result %= 1000000007;
		result %= 1000000007;
	}

	cout << result % 1000000007 << endl;

	return 0;
}