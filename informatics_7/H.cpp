#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e6;

vector<int> g[MAXN];
vector<bool> visited;
vector<int> color, result;
int n, m;


bool dfs(int vertex) {
    color[vertex] = 1;
    for (int neighbour : g[vertex]) {
        if (color[neighbour] == 0) {
                if (dfs(neighbour))  
                    return true;
        }             
        else if (color[neighbour] == 1) 
            return true;
    }
    color[vertex] = 2;
    return false;
}

bool has_cycle() {
    bool found_cycle = false;
    for (int vertex = 0; vertex < n; vertex++) {
        if (!visited[vertex]) {
            if (dfs(vertex)) {
                found_cycle = true;
                break;
            }
        }
    }
    return found_cycle;
}

void dfs_2(int vertex) {
    visited[vertex] = true;
    for (int neighbour : g[vertex])
        if (!visited[neighbour]) 
                dfs_2(neighbour);
    result.push_back(vertex + 1);
}

void top_sort() {
    if (has_cycle()) 
            cout << "No\n";
    else {
        for (int vertex = 0; vertex < n; vertex++) 
            if (!visited[vertex]) 
                    dfs_2(vertex);
        reverse(result.begin(), result.end());
        cout << "Yes\n";
        for (int vertex : result)
            cout << vertex << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    visited.resize(n, false);
    color.resize(n, 0);
    int a, b;
    for (int edge = 0; edge < m; ++edge) {
        cin >> a >> b;
        a--; b--;
        // a is bigger than b
        g[a].push_back(b);
    }
    top_sort();
    return 0;
}