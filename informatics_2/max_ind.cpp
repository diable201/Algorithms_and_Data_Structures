#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    uint32_t n;
    uint32_t max_index;
    ll maxi = -1e10;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] > maxi) {
            maxi = a[i];
            max_index = i;
        }
    }
    cout << max_index + 1 << '\n';
    return 0;
}