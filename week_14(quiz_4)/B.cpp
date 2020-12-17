#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uint32_t n, m;
    cin >> n >> m;
    uint32_t a[MAXN][MAXN];
    string elements[m];
    for (int i = 0 ; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < m; i++) {
        uint32_t x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;
        uint32_t index_1, index_2, index_3;
        index_1 = a[x][y];
        index_2 = a[y][z];
        index_3 = a[x][z];
        // cout << index_1 << " " << index_2 << " " << index_3;
        // cout << '\n';
        if (index_1 == 1 and index_2 == 1 and index_3 == 1) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}