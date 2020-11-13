#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll f(string s) {
    ll p = 31;
    ll p_pow = 1;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] * p_pow;
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (f(s1) == f(s2))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}