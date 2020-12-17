#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e7;
int n, m;
int used[MAXN];
vector<int> g[MAXN];
stack<int> answer;


void dfs(int v) {
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); i++) 
        if (used[g[v][i]] == 0)
            dfs(g[v][i]);
    answer.push(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    for (int i = 0; i < n; i++) 
        if (used[i] == 0)
            dfs(i);
    while (!answer.empty()) {
            cout << answer.top() + 1 << " ";
            answer.pop();
    }
    cout << '\n';
    return 0;
}