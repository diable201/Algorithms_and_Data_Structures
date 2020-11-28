#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxi = 1e6 + 5;
const int b_prime = 137;
 
char s[maxi];
uint32_t h[maxi], h_pow[maxi];
uint32_t N;

void buildHash() {
    h_pow[0] = 1;
    for (int i = 1; i <= N; i++)
        h_pow[i] = h_pow[i - 1] * b_prime;
    for (int i = 1; i <= N; i++)
        h[i] = h[i - 1] * b_prime + s[i];
}

int getHash(int i, int j) {
    return h[j] - h[i - 1] * h_pow[j - i + 1];
}

int bin_search(int pos) {
    ll l = 1; 
    ll r = N - pos; 
    ll ans = 0;
    while (l <= r) {
        ll m = (l + r ) / 2;
        if (getHash(1, m) == getHash(pos, pos + m - 1)) {
            ans = m;
            l = m + 1;
        }
        else 
            r = m - 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> (s + 1);
    N = strlen(s + 1);
    buildHash();
    int a = 0;
    for (int i = 2; i <= N; i++)
        a = max(a, bin_search(i));
    for (int i = a; i >= 1; i--) {
        if (getHash(1, i) == getHash(N - i + 1, N)) {
            for (int j = 1; j <= i; j++)
                    cout << s[j];
            cout << '\n';        
            return 0;
        }
    }
    cout << "Just a legend" << '\n';
    return 0;
}