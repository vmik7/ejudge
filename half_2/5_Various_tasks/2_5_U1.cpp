#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point {
    int x;
    int y;
};

point arr[4];

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    
    long long d = (arr[1].x - arr[0].x) * (arr[2].y - arr[3].y) - (arr[2].x - arr[3].x) * (arr[1].y - arr[0].y);
    long long dl = (arr[2].x - arr[0].x) * (arr[2].y - arr[3].y) - (arr[2].x - arr[3].x) * (arr[2].y - arr[0].y);
    long long dm = (arr[1].x - arr[0].x) * (arr[2].y - arr[0].y) - (arr[2].x - arr[0].x) * (arr[1].y - arr[0].y);
    
    if (d > 0 && dl >= 0 && dl <= d && dm >= 0 && dm <= d || d < 0 && dl <= 0 && dl >= d && dm <= 0 && dm >= d) {
        cout << fixed << setprecision(10) << (double)(d * arr[0].x + dl * (arr[1].x - arr[0].x)) / d
            << " " << (double)(d * arr[0].y + dl * (arr[1].y - arr[0].y)) / d << endl;
    }
    else if (d == 0 && dl == 0 && dm == 0) {
        if ((arr[0].x < arr[2].x && arr[0].x < arr[3].x && arr[1].x < arr[2].x && arr[1].x < arr[3].x) || (arr[0].x > arr[2].x && arr[0].x > arr[3].x && arr[1].x > arr[2].x && arr[1].x > arr[3].x) ||
            (arr[0].y < arr[2].y && arr[0].y < arr[3].y && arr[1].y < arr[2].y && arr[1].y < arr[3].y) || (arr[0].y > arr[2].y && arr[0].y > arr[3].y && arr[1].y > arr[2].y && arr[1].y > arr[3].y)) {
            cout << "No" << endl;
        }
        else if (arr[1].x == arr[2].x && arr[1].y == arr[2].y &&
               ((arr[0].x <= arr[1].x && arr[0].y <= arr[1].y && arr[2].x <= arr[3].x && arr[2].y <= arr[3].y || arr[0].x >= arr[1].x && arr[0].y >= arr[1].y && arr[2].x >= arr[3].x && arr[2].y >= arr[3].y)) ||
                 arr[1].x == arr[3].x && arr[1].y == arr[3].y &&
               ((arr[0].x <= arr[1].x && arr[0].y <= arr[1].y && arr[3].x <= arr[2].x && arr[3].y <= arr[2].y || arr[0].x >= arr[1].x && arr[0].y >= arr[1].y && arr[3].x >= arr[2].x && arr[3].y >= arr[2].y))) {
            cout << fixed << setprecision(10) << (double)(arr[1].x)
                << " " << (double)(arr[1].y) << endl;
            return 0;
        }
        else if (arr[0].x == arr[2].x && arr[0].y == arr[2].y &&
               ((arr[0].x <= arr[1].x && arr[0].y <= arr[1].y && arr[2].x >= arr[3].x && arr[2].y >= arr[3].y || arr[0].x >= arr[1].x && arr[0].y >= arr[1].y && arr[2].x <= arr[3].x && arr[2].y <= arr[3].y))   ||
                 arr[0].x == arr[3].x && arr[0].y == arr[3].y &&
               ((arr[0].x <= arr[1].x && arr[0].y <= arr[1].y && arr[2].x <= arr[3].x && arr[2].y <= arr[3].y || arr[0].x >= arr[1].x && arr[0].y >= arr[1].y && arr[2].x >= arr[3].x && arr[2].y >= arr[3].y))) {
            cout << fixed << setprecision(10) << (double)(arr[0].x)
                << " " << (double)(arr[0].y) << endl;
            return 0;
        }
        else {
            cout << "Infinity" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
