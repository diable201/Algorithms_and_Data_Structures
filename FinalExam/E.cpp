#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define xx first
#define yy second

const int MAX_V = 2001;
const double EPS = (double)1e-10;
const double INF = (double)1e10;
const int MAXN = (int)1e8;

queue<int> q;
vector<int> x(MAX_V);
vector<int> y(MAX_V);
vector<int> dist(MAX_V);


int find_difference(int v, int i) {
    return abs(x[v] - x[i]) + abs(y[v] - y[i]);
}

void bfs(int v, int n) {
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (dist[i] > max(dist[v], find_difference(v, i))) {
                dist[i] = max(dist[v], find_difference(v, i));
                q.push(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        dist[i] = 1000000;
        cin >> x[i] >> y[i];
    }
    bfs(0, n);
    n--;
    cout << dist[n];
    cout << '\n';
    return 0;
}
