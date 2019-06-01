#include <iostream>

using namespace std;

bool NextPermutation(int *p, int n);

int main()
{
	int n;
	cin >> n;
	int * arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (NextPermutation(arr, n))
	{
		for (int i = 1; i <= n; i++)
		{
			cout << arr[i - 1] << (i % n ? " " : "\n");
		}
	}
	else
	{
		cout << "Not exist" << endl;
	}

	//system("pause");
	return 0;
}


bool NextPermutation(int *p, int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		int index = i;
		int min = n + 1;
		for (int j = i + 1; j < n; j++)
		{
			if (p[j] > p[i] && p[j] < min)
			{
				min = p[j];
				index = j;
			}
		}
		if (min != n + 1)
		{
			int temp = p[i];
			p[i] = p[index];
			p[index] = temp;

			bool flag = true;
			for (int s = 0; s < n - i - 2 && flag; s++)
			{
				flag = false;
				for (int j = i + 1; j < n - s - 1; j++)
				{
					if (p[j] > p[j + 1])
					{
						flag = true;
						temp = p[j];
						p[j] = p[j + 1];
						p[j + 1] = temp;
					}
				}
			}

			return true;
		}
	}
	return false;
}