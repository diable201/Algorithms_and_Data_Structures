#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e6;

vector<int> g[MAXN];
int n, m;
vector<bool> used;
vector<int> component;
vector<vector<int> > components;


void dfs(int vertex) {
    used[vertex] = 1;
    component.push_back(vertex + 1);
    for (auto & neighbor : g[vertex])
        if (!used[neighbor])
                dfs(neighbor);
}

void print() {
    cout << (int)components.size() << '\n';
    for (auto & component : components) {
        cout << (int)component.size() << '\n';
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << '\n';
    }
}

void solution() {
    int answer = 0;
    for (int vertex = 0; vertex < n; vertex++) {
        if (!used[vertex]) {
            dfs(vertex);
            answer++;
            components.push_back(component);
            component.clear();
        }
    }
    print();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    used.resize(n, false);
    int a, b;
    for (int edge = 0; edge < m; edge++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solution();
    return 0;
}
