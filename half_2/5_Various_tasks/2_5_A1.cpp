#include <iostream>
#include <fstream>

using namespace std;

bool arr[1000][1000];

int main() {
	int n, m;
	ifstream fin;
	fin.open("rect.dat");
	fin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fin >> arr[i][j];
		}
	}
	fin.close();

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j]) continue;
			count++;
			int x = i;
			int y = j;
			while (x < n && arr[x][y]) {
				while (y < m && arr[x][y]) {
					arr[x][y] = 0;
					y++;
				}
				y = j;
				x++;
			}
		}
	}

	ofstream fout;
	fout.open("rect.sol");
	fout << count << endl;
	fout.close();

	return 0;
}
