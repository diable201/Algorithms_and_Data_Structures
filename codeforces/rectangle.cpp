#include <bits/stdc++.h>

using namespace std;

bool good(long long w, long long h, long long n, long long m) {
    return (m / w) * (m / h) >= n;
}

int main() {
    long long w, h, n;
    cin >> w >> h >> n;

    long long l = 0; 
    long long r = 1;

    while (!good (w, h, n, r)) {
        r *= 2;
    }

    while (r > l + 1) {
        long long m = (l + r) / 2;
        long long s = (m / w) * (m / h);
        if (good(w, h, n, m)) 
            r = m;
        else 
            l = m;
    }
    cout << r << '\n';
    return 0;
}

// 2 3 6
// Answer: 6
// a, b, n
// Answer: number of squares