#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int * n_array = new int[n];
	for (int i = 0; i < n; i++) cin >> n_array[i];

	int m;
	cin >> m;
	int * m_array = new int[m];
	for (int i = 0; i < m; i++) cin >> m_array[i];


	int n_index = 0;
	int m_index = 0;

	for (int i = 0; i < (n + m); i++)
	{
		if (n_index < n)
		{
			if (m_index >= m || n_array[n_index] <= m_array[m_index])
			{
				cout << n_array[n_index] << ' ';
				n_index++;
			}
			else
			{
				cout << m_array[m_index] << ' ';
				m_index++;
			}
		}
		else
		{
			cout << m_array[m_index] << ' ';
			m_index++;
		}
	}

	//system("pause");
	return 0;
}