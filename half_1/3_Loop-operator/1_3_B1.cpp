#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	long * out_array = new long[t];

	for (int i = 0; i < t; i++)
	{
		long a, b;
		cin >> a >> b;

		if (b > a) swap(a, b);

		if (b == 0)	out_array[i] = a;
		else
		{
			long r = a % b;
			while (r)
			{
				a = b;
				b = r;
				r = a % b;
			}
			out_array[i] = b;
		}

	}

	for (int i = 0; i < t; i++)
	{
		cout << out_array[i] << endl;
	}

	delete[] out_array;

	//system("pause");
	return 0;
}