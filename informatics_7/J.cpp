#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Vertex {
    int row, column;
    Vertex(int row, int column) : row(row), column(column) {}
    bool operator != (const Vertex & op) const {
        return row != op.row or column != op.column;
    }
};

int n, m;
const int num_of_steps = 8;
vector<vector<int> > matrix;
int st_row, st_col, fin_row, fin_col;
vector<vector<bool> > visited;
vector<vector<Vertex> > previous;
vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
vector<int> dy = {1,-1, 2, -2, 2, -2, 1, -1};


bool is_in_board(const Vertex &p) {
    return (p.row >= 0) and (p.row < n) and
            (p.column >= 0) and (p.column < m);
}
    
void solution() {
    queue<Vertex> q;
    Vertex start(st_row, st_col);
    q.push(start);
    visited[start.row][start.column] = true;
    while (!q.empty()) {
        Vertex v = q.front(); q.pop();
        for (int step = 0; step < num_of_steps; ++step) {
            Vertex neighbour(v.row + dy[step], v.column + dx[step]);
            if (is_in_board(neighbour) and 
                !visited[neighbour.row][neighbour.column]) {
                visited[neighbour.row][neighbour.column] = true;
                q.push(neighbour);
                previous[neighbour.row][neighbour.column] = v;
            }
        }
    }
    Vertex last_vertex(fin_row, fin_col);
    vector<Vertex> path;
    Vertex fake_vertex(-1, -1);
    while (last_vertex != fake_vertex) {
            path.push_back(last_vertex);
            last_vertex = previous[last_vertex.row][last_vertex.column];
    }
    reverse(path.begin(), path.end());
    cout << (int)path.size() - 1 << '\n';
    for (const auto & p : path)
        cout << p.column + 1 << " " << p.row + 1 << '\n';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    m = n;
    visited.resize(n, vector<bool> (m, false));
    previous.resize(n, vector<Vertex> (m, Vertex(-1, -1)));
    cin >> st_col >> st_row;
    cin >> fin_col >> fin_row;
    st_row--; st_col--;
    fin_row--; fin_col--;
    solution();
    return 0;
}