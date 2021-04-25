#include <iostream>

#define ll long long

using namespace std;

int main() {
    uint16_t n;
    ll maxMark = -1e10;
    ll minMark = 1e10;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] > maxMark)
            maxMark = a[i];
        if (a[i] < minMark)
            minMark = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == maxMark)
            a[i] = minMark;
        cout << a[i] << " ";
    }
    cout << '\n';
    // cout << maxMark << " " << minMark;
    return 0;
}