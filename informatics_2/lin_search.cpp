#include <iostream>

using namespace std;

int main() {
    uint32_t n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    uint32_t l;
    cin >> l;
    for (int i = 0; i < n; i++) {
        if (a[i] == l)
            cout << i + 1 << '\n';
    }
    return 0;
}