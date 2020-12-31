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
const int MAXN = (int)1e5;

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
    int a[MAXN];
    vector<string> v;
    int e_tmp = 0;
    for (size_t i = 0; i < n; i++) {
        char c;
        string s;
        cin >> c >> s;
        if (c == '+')
            v.pb(s);
        if (c == '-')
            v.erase(remove(v.begin(), v.end(), s), v.end());
        if (c == '?') {
            int tmp = 0;
            for (size_t j = 0; j < v.size(); j++)
                if (v[j].rfind(s, 0) == 0)
                    tmp++;
            a[e_tmp] = tmp;
            e_tmp++;
        }
    }
    for (size_t i = 0; i < e_tmp; i++)
        cout << a[i] << '\n';
    return 0;
}
