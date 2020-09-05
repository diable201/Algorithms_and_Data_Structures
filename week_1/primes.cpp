#include <iostream>

using namespace std;

int p[10000010];
void primes(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (p[i] == 0) {
            int k = i;
            while (k + i <= n) {
                k += i;
                p[k] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        if (p[i] == 0)
            cout << i << '\t';
}

int main() {
    int n;
    cin >> n;
    primes(n);
    return 0;
}