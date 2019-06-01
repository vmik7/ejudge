#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
};

int sign(int x){
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

point arr[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    int s1, s2, s = 0, i = 0;
    while (i < n && s == 0) {
       s1 = arr[i].x * arr[(i + 1) % n].y + arr[(i + 1) % n].x * arr[(i + 2) % n].y + arr[(i + 2) % n].x * arr[i].y;
       s2 = arr[i].y * arr[(i + 1) % n].x + arr[(i + 1) % n].y * arr[(i + 2) % n].x + arr[(i + 2) % n].y * arr[i].x;
       s = sign(s1 - s2);
       i++;
    }
    
    while (i < n) {
        s1 = arr[i].x * arr[(i + 1) % n].y + arr[(i + 1) % n].x * arr[(i + 2) % n].y + arr[(i + 2) % n].x * arr[i].y;
        s2 = arr[i].y * arr[(i + 1) % n].x + arr[(i + 1) % n].y * arr[(i + 2) % n].x + arr[(i + 2) % n].y * arr[i].x;
        int ss = sign(s1 - s2);
        if (ss != s && ss != 0) {
            cout << "NO" << endl;
            return 0;
        }
        i++;
    }
    cout << "YES" << endl;  
    return 0;
}
