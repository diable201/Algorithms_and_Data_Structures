#include <bits/stdc++.h>

using namespace std;

vector <int> g[200001];
int u[200001];
queue <int> q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y + n].push_back(x + n);
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back(i + n);
        g[i + n].push_back(i);
    }
    u[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : g[v]) {
            if (!u[to]) {
                u[to] = u[v] + 1;
                q.push(to);
            }
        }
    }
    cout << min(u[n], u[n + n]) - 1 << '\n';
    return 0;
}