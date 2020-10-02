#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    double l = 0; // can cut
    double r = 1e8; // can't cut

    for (int t = 0; t < 100; t++) {
        double m = (l + r) * .5;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += (int)(v[i] / m);
        }
        if (s >= k)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
    return 0;
}