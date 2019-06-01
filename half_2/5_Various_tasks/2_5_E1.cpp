#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string dp[300][300];

int main() {
	freopen("palin.dat", "r", stdin);
	freopen("palin.sol", "w", stdout);
	string val;
	cin >> val;

	char t[2];
	t[1] = '\0';
	for (int i = 0; i < val.size(); i++) {
		t[0] = val[i];
		string temp(t);
		dp[i][i] = temp;
	}
	
	for (int len = 2; len <= val.size(); len++) {
		for (int i = 0; i <= val.size() - len; i++) {
			if (val[i] == val[i + len - 1]) {
				t[0] = val[i];
				string t1 = t;
				t[0] = val[i + len - 1];
				string t2 = t;
				dp[i][i + len - 1] = len >= 3 ? val[i] + dp[i + 1][i + len - 2] + val[i + len - 1] : t1 + t2;
			}
			else {
				dp[i][i + len - 1] = dp[i][i + len - 2].size() > dp[i + 1][i + len - 1].size() ? dp[i][i + len - 2] : dp[i + 1][i + len - 1];
			}
		}
	}
	cout << val.size() - dp[0][val.size() - 1].size() << endl;
	cout << dp[0][val.size() - 1] << endl;
	return 0;
}
