#include <iostream>

using namespace std;

int main() {
    long long sum = 0;
    long long sumX = 0;
    long long sumY = 0;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        sum += (n - 1) * (x * x + y * y);
        sum -= 2 * (sumX * x + sumY * y);
        sumX += x;
        sumY += y;
    }
    
    cout << sum << endl;
    
    return 0;
}
