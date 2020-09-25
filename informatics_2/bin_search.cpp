#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int> &a, int x) {
    int l = 0;
    int r = (int)a.size() - 1;
    while (r >= l) {
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        if (a[m] < x)
            l = m + 1;
        if (a[m] > x)
            r = m - 1;
    }
    return false;
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
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}