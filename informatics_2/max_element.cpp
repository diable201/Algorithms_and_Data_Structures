#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    uint32_t n;
    cin >> n;
    ll maxi = -1e10;
    int a[n];
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        if (a[i] > maxi)
            maxi = a[i];
    cout << maxi << '\n';
    return 0;
}
