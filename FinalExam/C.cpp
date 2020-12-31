#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define xx first
#define yy second

const double EPS = (double)1e-10;
const double INF = (double)1e10;
const int MAXN = (int)1e6;

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
    cout << (int)components.size() - 1 << '\n';
    // for (auto & component : components) {
    //     cout << (int)component.size() << '\n';
    //     for (int vertex : component) {
    //         cout << vertex << " ";
    //     }
    //     cout << '\n';
    // }
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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    used.resize(n);
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
