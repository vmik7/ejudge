#include <iostream>

using namespace std;

int main()
{
	int first, second;
	cin >> first >> second;
	if (first % 2 == 0 || second % 2 == 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	//system("pause");
	return 0;
}