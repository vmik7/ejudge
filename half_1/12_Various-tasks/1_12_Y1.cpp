#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

const int Base = 10000;

struct test
{
	int n;
	int order;
};

vector<test> tests;
vector<vector<int>> results;

bool comp_by_n(test a, test b) { return a.n < b.n; }
vector<int> toVector(long long val)
{
	vector<int> vec;
	while (val)
	{
		int num = val % Base;
		val /= Base;
		vec.push_back(num);
	}
	return vec;
}
vector<int> singleMulLong(vector<int> & num, int factor)
{
	vector<int> result;
	result.resize(num.size());
	int carry = 0;
	for (int i = 0; i < num.size(); i++)
	{
		int next_carry = (num[i] * factor + carry) / Base;
		result[i] = (num[i] * factor + carry) % Base;
		carry = next_carry;
	}
	if (carry) result.push_back(carry);
	return result;
}
void printLong(const vector<int> & val)
{
	int i = val.size() - 1;
	cout << val[i];
	while (--i >= 0)
		cout << setw(4) << setfill('0') << val[i];
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	results.resize(t);
	test temp;
	for (temp.order = 0; temp.order < t; temp.order++)
	{
		cin >> temp.n;
		tests.push_back(temp);
	}
	sort(tests.begin(), tests.end(), comp_by_n);

	vector<int> a = toVector(1);
	int number = 1;
	for (int i = 0; i < t; i++)
	{
		while (number < tests[i].n)
		{
			number++;
			a = singleMulLong(a, number);
		}
		results[tests[i].order] = a;
	}
	for (int i = 0; i < t; i++)
		printLong(results[i]);

	//system("pause");
	return 0;
}