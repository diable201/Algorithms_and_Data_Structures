#include <bits/stdc++.h>

using namespace std;

// bool find(vector<int> &a, int x) {
//     int l = 0;
//     int r = (int)a.size() - 1;
//     while (r >= l) {
//         int m = (l + r) / 2;
//         if (a[m] == x)
//             return true;
//         if (a[m] < x)
//             l = m + 1;
//         if (a[m] > x)
//             r = m - 1;
//     }
//     return false;
// }

int find_lower(vector<int> &v, int x) { // max a[i] <= x
    int l = -1; // a[l] <= x
    int r = (int)v.size(); // a[r] > x
    while (r > l + 1) {
        int m = (l + r) / 2; // l < m < r
        if (v[m] <= x)
            l = m;
        else 
            r = m;
    }
    return l;
}

int find_upper(vector<int> &v, int x) { // min a[i] >= x
    int l = -1; // a[l] < x
    int r = (int)v.size(); // a[r] >= x
    while (r > l + 1) {
        int m = (l + r) / 2; // l < m < r
        if (v[m] < x) 
            l = m;
        else 
            r = m;
    }
    return r;
}

bool find(vector<int> &a, int x) {
    int i = find_lower(a, x);
    return i >= 0 && a[i] == x;
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
        if (find(v, x))
            cout << find_upper(v, x) + 1 << " " << find_lower(v, x) + 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
