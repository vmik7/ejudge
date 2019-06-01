#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string str;
int arr[1000000];

bool cmp(int a, int b) {
	for (int i = 0; i < n; i++) {
		if (str[a + i] == str[b + i]) continue;
		return str[a + i] < str[b + i];
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> str;
	for (int i = 0; i <= str.size() - n; i++) {
		arr[i] = i;
	}
	sort(arr, arr + str.size() - n + 1, cmp);

	int max_cnt = 0, ans = arr[0], cnt = 1, index = 1, cur = 0;
	while (index <= str.size() - n) {
		if (str.substr(arr[cur], n) == str.substr(arr[index], n)) {
			cnt++;
			if (cnt > max_cnt) {
				max_cnt = cnt;
				ans = arr[cur];
			}
		}
		else {
			cnt = 1;
			cur = index;
		}
		index++;
	}

	cout << str.substr(ans, n) << endl;

	return 0;
}
