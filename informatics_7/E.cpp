#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int> > g;
int n;
vector<bool> used;

void dfs(int vertex) {
    used[vertex] = true;
    for (int neigbour = 0; neigbour < n; neigbour++)
        if (g[vertex][neigbour] and !used[neigbour])
                dfs(neigbour);
}

bool is_connected() {
    for (int vertex = 0; vertex < n; vertex++)
        if (!used[vertex])
                return false;
    return true;
}

void solution() {
    dfs(0);
    if (!is_connected()) { 
        cout << "NO\n";
        return;
    }

    int answer = 0;
    for (int v1 = 0; v1 < n; v1++) 
        for (int v2 = 0; v2 < n; v2++) 
            if (g[v1][v2]) 
                    answer++;
    cout << (answer / 2 == n - 1 ? "YES\n" : "NO\n");
}    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    used.resize(n, false);
    g.resize(n, vector<int>(n));
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++) 
            cin >> g[row][column];
    solution();
    return 0;
}