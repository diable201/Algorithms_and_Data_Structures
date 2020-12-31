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
const int MAXN = (int)1e8;
vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 and s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j; 
    }
    return p;
}


int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s, t;
    while (s.size() < n)
        cin >> s;
    while (t.size() < n)
        cin >> t;
    string s_twice = s + s;
    s = t + '#' + s_twice;
    vector<int> p = prefix_function(s);
    // cout << s << " " << p[s.size() - 1] << " " << p[t.size()];
    // for (int i = 0; i < s.size(); i++)
        // cout << p[i] << " ";
    // cout << '\n';
    if (p[s.size() - 1] == t.size())
        cout << 0 << '\n';
    else if (p[s.size() - 1] != 0)
        cout << p[s.size() - 1] << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
