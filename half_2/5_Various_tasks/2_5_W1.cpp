#include <iostream>

using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 == x2) {
		cout << x1 - 1 << " " << y1 << " " << x1 + 1 << " " << y1 << endl;
	}
	else {
		cout << x1 << " " << y1 - 1 << " " << x1 << " " << y1 + 1 << endl;
	}
	
	return 0;
}
