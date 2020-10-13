#include <iostream>
#include <algorithm>

using namespace std;

int a[100010];
int n, m;

int f(int x) {
    // a[l] <= x
    // a[r] > x
    int l = -1;
    int r = n;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l + 1;
}

int query(int l, int r) {
    return f(r) - f(l -1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l1, r1, l2, r2;
    for (int i = 0; i < m; i++) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 or r2 < l1) {
            cout << query(l1, r1) + query(l2, r2) << '\n';
        } else {
            int min_l = min(l1, l2);
            int max_r = max(r1, r2);
            cout << query(min_l, max_r) << '\n';
        }
    }
    return 0;
}