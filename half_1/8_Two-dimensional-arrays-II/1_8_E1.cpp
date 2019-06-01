#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int h, w;
	cin >> w >> h;

	vector<string> map(h);
	for (int i = 0; i < h; i++)
	{
		cin >> map[i];
	}

	int border = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i != h - 1 && map[i][j] != map[i + 1][j]) border++;
			if (j != w - 1 && map[i][j] != map[i][j + 1]) border++;
		}
	}

	cout << border << endl;

	//system("pause");
	return 0;
}