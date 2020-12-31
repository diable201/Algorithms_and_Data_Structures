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
const int MAXN = (int)1e7;
const int MINN = (int)250000;
const int check = 1e5;

int start, finish;
int d[MINN]; 
int p[MINN];
queue<int> q;

void rec(int x) {
    if (x == start)
        return;
    rec(p[x]);
    cout << x << " ";
}

void solution() {
    d[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v * 2 < check) {
            if (d[v * 2] > d[v] + 1) {
                d[v * 2] = d[v] + 1;
                p[v * 2] = v;
                q.push(v * 2);
            }
        }
        if (v > 0) {
            if (d[v - 1] > d[v] + 1) {
                d[v - 1] = d[v] + 1;
                p[v - 1] = v;
                q.push(v - 1);
            }
        }
    }
    cout << d[finish] << '\n';
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> start >> finish;
    fill(d + 1, d + MINN, MAXN);
    solution();
    rec(finish);
    cout << '\n';
    return 0;
}
