#include <iostream>

using namespace std;

struct command {
    int type;
    int first;
    int second;
};
command coms[100000];

const int MOD = 1e9 + 7;
const int MAX_N = 400000;
int start_c = 1;
int start_a = 1;
int t_c[MAX_N];
int t_a[MAX_N];

void increase(int * t, int start, int l, int r, int x) {
    l += start; r += start;
    while (l <= r) {
		if (l % 2 == 1) {
			t[l] = ((long long)(t[l] + x)) % MOD;
			l++;
		}
		if (r % 2 == 0) {
			t[r] = ((long long)(t[r] + x)) % MOD;
			r--;
		}
		l /= 2; r /= 2;
    }
    return;
}

int get(int * t, int start, int x) {
    x += start;
    int sum = 0;
    while (x >= 1) {
		sum = ((long long)(t[x] + sum)) % MOD;
		x /= 2;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
		cin >> coms[i].type >> coms[i].first >> coms[i].second;
		coms[i].first--;
		coms[i].second--;
    }
    while (start_c < m) {
		start_c <<= 1;
    }
    for (int i = 0; i < m; i++) {
		t_c[i + start_c] = 1;
    }
    while (start_a < n) {
		start_a <<= 1;
    }
    
    for (int i = m - 1; i >= 0; i--) {
		if (coms[i].type == 2) {
			int count = get(t_c, start_c, i);
			increase(t_c, start_c, coms[i].first, coms[i].second, count);
		}
		else {
			int count = get(t_c, start_c, i);
			increase(t_a, start_a, coms[i].first, coms[i].second, count);
		}
    }
    
    cout << get(t_a, start_a, 0);
    for (int i = 1; i < n; i++) {
		cout << " " << get(t_a, start_a, i);
    } cout << endl;
	
    return 0;
}
