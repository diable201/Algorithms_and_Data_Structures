#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int n;
vector<vector<int> > matrix;
int start, finish;
vector<bool> visited;
vector<int> previous;

void solution() {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    previous[start] = -1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int neighbour = 0; neighbour < n; neighbour++) {
            if (matrix[v][neighbour]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    previous[neighbour] = v;
                    q.push(neighbour);
                }
            }
        }
    }
    if (!visited[finish]) 
            cout << -1;
    else {
        vector<int> path;
        int last_vertex = finish;
        while (last_vertex != -1) {
            path.push_back(last_vertex);
            last_vertex = previous[last_vertex];
        }
        cout << (int)path.size() - 1 << '\n';
        if ((int)path.size() - 1) {
            reverse(path.begin(), path.end());
            for (int v : path) 
                cout << v + 1 << " ";
        }
    }
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    matrix.resize(n, vector<int> (n));
    visited.resize(n, false);
    previous.resize(n);
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++) 
            cin >> matrix[row][column];
    cin >> start >> finish;
    start--; finish--;
    solution();
    return 0;
}