#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const int Base = 10000;

void toVector(string & str, vector<int> & vec)
{
	vec.clear();
	for (int i = str.size() - 4; i > -4; i -= 4)
	{
		int num = 0;
		for (int j = 0; j < 4; j++)
		{
			if (i + j < 0)
				j = -i;
			num = num * 10 + str[i + j] - '0';
		}
		vec.push_back(num);
	}
}

void sumLong(vector<int> & num1, vector<int> & num2, vector<int> & result)
{
	vector<int> & long_vec = (num1.size() >= num2.size() ? num1 : num2);
	vector<int> & short_vec = (num1.size() < num2.size() ? num1 : num2);
	result.resize(long_vec.size());
	int carry = 0;
	for (int i = 0; i < short_vec.size(); i++)
	{
		int next_carry = (long_vec[i] + short_vec[i] + carry) / Base;
		result[i] = (long_vec[i] + short_vec[i] + carry) % Base;
		carry = next_carry;
	}
	for (int i = short_vec.size(); i < long_vec.size(); i++)
	{
		int next_carry = (long_vec[i] + carry) / Base;
		result[i] = (long_vec[i] + carry) % Base;
		carry = next_carry;
	}
	if (carry) result.push_back(carry);
}

void printLong(vector<int> & val)
{
	int i = val.size() - 1;
	cout << val[i];
	while (--i >= 0)
		cout << setw(4) << setfill('0') << val[i];
	cout << endl;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	vector<int> num1, num2;
	toVector(str1, num1);
	toVector(str2, num2);
	sumLong(num1, num2, num1);
	printLong(num1);

	//system("pause");
	return 0;
}