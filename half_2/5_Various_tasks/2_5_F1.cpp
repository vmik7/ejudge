#include <iostream>

using namespace std;

int nums[1001];

int main() {
	freopen("numb.dat", "r", stdin);
	freopen("numb.sol", "w", stdout);
	int n, max_num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		nums[val]++;
		if (nums[val] > nums[max_num] || nums[val] == nums[max_num] && val < max_num) {
			max_num = val;
		}
	}
	cout << max_num << endl;
	return 0;
}
