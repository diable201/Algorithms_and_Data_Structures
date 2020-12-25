#include <iostream>

using namespace std;

typedef long long ll;

ll f(string s) {
    ll p = 31;
    ll p_pow = 1;
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << f(s) << '\n';
    return 0;
}