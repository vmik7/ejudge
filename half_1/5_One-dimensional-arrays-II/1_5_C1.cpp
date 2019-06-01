#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int last;
	cin >> last;

	int last_count = 1;
	int max_count = 1;

	for (int i = 1; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == last)
		{
			last_count++;
			if (last_count > max_count) max_count = last_count;
		}
		else
		{
			last = temp;
			last_count = 1;
		}
	}

	cout << max_count << endl;

	//system("pause");
	return 0;
}