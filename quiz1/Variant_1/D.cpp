#include <iostream>

using namespace std;

int x[2 * 100010], y [2 * 100010];
int n, k;
int xx, yy;

int f(int w) {
    int t = 0;
    for (int i = 0; i < n; i++) 
        if (w >= x[i] and w >= y[i])
            t++;
    if (t >= k)
        return true;
    return false; 
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> xx >> yy;
        cin >> x[i] >> y[i];
    }
    int l = 0;
    int r = 1e9;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m) == 0) 
            l = m;
        else 
            r = m;
    }
    cout << r << '\n';
    return 0;
}