#include <iostream>

using namespace std;

void primes(int n) {
    for (int i = 2; i <= n; i++) {
        bool isPrime = true;
        for (int j = 2; j*j <= i; j++) 
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        if (isPrime)
            cout << i << '\t';
    }
}

int main() {
    int n;
    cin >> n;
    primes(n);
    return 0;
}