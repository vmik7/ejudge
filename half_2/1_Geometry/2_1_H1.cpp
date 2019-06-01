#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
};
struct vec {
    int x;
    int y;
};
double len2(vec v) { return v.x * v.x + v.y * v.y; }

int main() {
    point c, a, b;
    vec ab, bc, ba, ac;
    cin >> c.x >> c.y >> a.x >> a.y >> b.x >> b.y;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    bc.x = c.x - b.x;
    bc.y = c.y - b.y;
    ac.x = c.x - a.x;
    ac.y = c.y - a.y;
    ba.x = a.x - b.x;
    ba.y = a.y - b.y;
    cout << fixed << setprecision(4);
    if (len2(ac) == 0 || len2(bc) == 0) cout << double(0) << endl;
    else if (ba.x * ac.x + ba.y * ac.y >= 0 || ab.x * bc.x + ab.y * bc.y >= 0)
        cout << sqrt(min(len2(ac), len2(bc))) << endl;
    else
        cout << fabs((a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x)) / sqrt(len2(ab)) << endl;
    return 0;
}
        
