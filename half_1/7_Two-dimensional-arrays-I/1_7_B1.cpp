#include <iostream>
#include <vector>

using namespace std;

struct cor
{
	int n, m;
};

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int min = 1000000001;
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			if (temp < min)
			{
				min = temp;
			}
		}
		cout << min << endl;
	}

	//system("pause");
	return 0;
}