#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++) {
        int x, r;
        cin >> x;
        int l = 1; r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] > x)
                r = mid - 1;
            else 
                l = mid;
        }
        if (a[r] == x || a[l] == x)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}