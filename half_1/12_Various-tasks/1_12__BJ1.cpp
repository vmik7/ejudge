#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, y;
	cin >> n >> x >> y;

	int count_king = 8;
	if (n == 1) count_king = 0;
	else if (x == 1 || x == n)
	{
		count_king -= 3;
		if (y == 1 || y == n)
			count_king -= 2;
	}
	else if (y == 1 || y == n)
		count_king -= 3;

	cout << "King: " << count_king << endl;

	int knight_pos[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
	int count_knight = 0;
	for (int i = 0; i < 8; i++)
	{
		if (x + knight_pos[i][0] >= 1 && x + knight_pos[i][0] <= n && y + knight_pos[i][1] >= 1 && y + knight_pos[i][1] <= n)
			count_knight++;
	}
	cout << "Knight: " << count_knight << endl;

	int count_bishop = min(n - x, y - 1) + min(x - 1, n - y) + min(n - x, n - y) + min(x - 1, y - 1);
	cout << "Bishop: " << count_bishop << endl;

	int count_rook = n + n - 2;
	cout << "Rook: " << count_rook << endl;

	int count_queen = count_bishop + count_rook;
	cout << "Queen: " << count_queen << endl;

	//system("pause");
	return 0;
}