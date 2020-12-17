#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e5;
vector <int> g[MAXN];
int used[MAXN];
int cnt;

void dfs(int v) {
    used[v] = true;
    cnt++;
    for (size_t i = 0; i < g[v].size(); i++) 
        if (used[g[v][i]] == 0) 
            dfs(g[v][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int tmp = n;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cnt = 0;
            dfs(i);
            tmp = min(tmp, cnt);
        }
    }
    cout << tmp << '\n';
    return 0;
}