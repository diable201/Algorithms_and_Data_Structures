#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define xx first
#define yy second

const double EPS = (double)1e-10;
const double INF = (double)1e10;
const int MAXN = (int)1e6;


int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<ll> balanced_string;
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        if (balanced_string.size() and s[i] == s[balanced_string.top()])
            balanced_string.pop();
        else
            balanced_string.push(i);
    }
    balanced_string.size() ? cout << "NO\n" : cout << "YES\n";
    return 0;
} 
