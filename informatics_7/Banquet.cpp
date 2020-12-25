#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 1e6;
vector<int> g[MAXN];
int n, m;
vector<bool> used;
vector<int> color, first_component;
bool is_ok = true;


void fill() {
    for (int vertex = 0; vertex < n; vertex++) 
        if (color[vertex] == 0) 
                first_component.push_back(vertex + 1);
}

void solution() {
    for (int vertex = 0; vertex < n; vertex++) {
        if (!used[vertex]) {
            queue<int> q;
            int start = vertex;
            q.push(start);
            used[start] = true;
            color[start] = 0;
            while(!q.empty()) {
                int v = q.front(); q.pop();
                for (int neighbour : g[v]) {
                    if (used[neighbour]) 
                            continue;
                    used[neighbour] = true;
                    color[neighbour] = 1 - color[v];
                    q.push(neighbour);
                }
            }
        }
    }
    for (int vertex = 0; vertex < n; vertex++) {
        for (int neighbour : g[vertex]) {
            if (color[vertex] == color[neighbour]) {
                    is_ok = false;
                    break;
            }
        }
    }
    if (is_ok) {
        cout << "YES\n";
        fill();
        for (int guest : first_component) {
            cout << guest << " ";
        }
    } else 
        cout << "NO\n";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    used.resize(n, false);
    color.resize(n, 0);
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
