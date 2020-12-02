#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> g[100];
int color[100]; // u[i] = 0
int n, m, x, y;
bool ok = true;

void dfs(int v, int c) {
    color[v] = c;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (color[y] == 0) {
            dfs(y, 3 - c);
        } else {
            if (color[y] == c)
                ok = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y; // x - y, y - x
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            dfs(i, 1);
    ok ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
/*
7 6
1 2
1 7
3 5
2 4
4 5
4 6
YES
*/