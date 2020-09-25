#include <bits/stdc++.h>

using namespace std;

int find_upper(vector<int> &v, int x) { // min a[i] >= x
    int l = -1; // a[l] < x
    int r = (int)v.size(); // a[r] >= x
    while (r > l + 1) {
        int m = (l + r) / 2; // l < m < r
        if (v[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (k--) {
        int x;
        cin >> x;
        cout << find_upper(v, x) + 1 << '\n';
    }
    return 0;
}