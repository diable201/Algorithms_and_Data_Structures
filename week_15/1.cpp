#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define MAXN 1e6

int g[100][100];
int n, m;
int u[100];
int c[100];
vector<int> d(100, MAXN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        x--; y--;
        g[x][y] = l;
        g[y][x] = l;
    }

    d[0] = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!u[j] and (v == -1 or d[v] > d[j]))
                v = j;
        cout << v + 1 << '\n';
        u[v] = true;

        for (int j = 0; j < n; j++)
            if (!u[j] and g[v][j] > 0) {
                if (d[j] > g[v][j]) {
                    d[j] = g[v][j];
                    c[j] = v;
                }
            }
    }
    for (int i = 0; i < n; i++)
        cout << c[i] + 1 << " ";
    cout << '\n';
    return 0;
}