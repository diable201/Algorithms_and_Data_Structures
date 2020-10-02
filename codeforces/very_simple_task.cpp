#include <iostream>
 
using namespace std;
 
int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    long long m;
    if (n == 1)
        cout << min(x, y);
    else {
        long long l = 0;
        long long r = n * (x + y  - min(x, y) + 1);
        while (r - l > + 1) {
            m = (l + r) / 2;
            if (n - 1 <= m / x + m / y)
                r = m;
            else
                l = m;
        }
        cout << min(x, y) + l + 1 << '\n';
    }
    return 0;
}