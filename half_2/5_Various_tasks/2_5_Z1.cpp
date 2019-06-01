#include <iostream>
#include <algorithm>

using namespace std;

int arr[4][4] = {
	{1, 3, 14 ,16},
	{5, 12, 7, 10},
	{13, 11, 4, 6},
	{15, 8 , 9, 2}
};

int main() {
	int i, j, k;
	cin >> i >> j >> k;
	i--;
	j--;

	int k_i = 0;
	int k_j = 0;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (arr[y][x] == k) {
				k_i = y;
				k_j = x;
				break;
			}
		}
	}

	for (int e = 0; e < 4; e++) {
		swap(arr[k_i][e], arr[i][e]);
	}

	for (int e = 0; e < 4; e++) {
		swap(arr[e][j], arr[e][k_j]);
	}

	for (int i = 0; i < 4; i++) {
		cout << arr[i][0];
		for (int j = 1; j < 4; j++) {
			cout << " " << arr[i][j];
		} cout << endl;
	}

	return 0;
}
