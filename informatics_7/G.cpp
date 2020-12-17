#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> g;
vector<bool> used;
int n, m;


void dfs(int row, int column) {
    if (row < 0 or column < 0 or row >= n or column >= m) 
        return;
    if (g[row][column] == '.')
        return;
    if (used[row * m + column])
        return;
    used[row * m + column] = true;
    dfs(row + 1, column);
    dfs(row - 1, column);
    dfs(row, column + 1);
    dfs(row, column - 1);
}

int solution() {
    int answer = 0;
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            if (!used[row * m + column] and g[row][column] == '#') {
                dfs(row, column);
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    used.resize(n * m, false);
    g.resize(n);
    for (int line = 0; line < n; line++)
        cin >> g[line];
    cout << solution() << '\n';
    return 0;
}