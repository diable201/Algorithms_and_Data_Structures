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
const ll MAXN = (int)1e8;
const ll MINN = 1e5;
const ll DIFFERENCE = 0;

int min_absolute_sum(vector<ll> &vec) {
    vector<ll> sum_vector;
    ll MINN;
    ll DIFFERENCE;
    sum_vector.resize(vec.size() + 1);
    sum_vector[0] = 0;
    for (int i = 1; i < sum_vector.size(); i++)
        sum_vector[i] = sum_vector[i - 1] + vec[i - 1];
    sort(sum_vector.begin(),sum_vector.end());
    for (int i = 1; i < sum_vector.size(); i++) {
        DIFFERENCE = sum_vector[i] - sum_vector[i - 1];
        if (DIFFERENCE < MINN)
            MINN = DIFFERENCE;
    }
    return MINN;
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> v;
    ll n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    cout << min_absolute_sum(v) << '\n';
    return 0;
}
