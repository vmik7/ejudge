#include <bits/stdc++.h>

using namespace std;

int a[200001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) scanf("%d", a + i);
    stack<int> st;
    int k = n;
    while (k > 0) {
        st.push(k);
        k = a[k];
    }
    while (st.size() >= 2) {
        printf("%d ", st.top());
        st.pop();
    }
    printf("%d\n", st.top());
    return 0;
}
