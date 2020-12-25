#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;

vector<vector<int> > matrix;
int n;
int answer = 0;
int startVertex;
vector<bool> used;

void dfs(int vertex) {
    used[vertex] = true;
    answer++;
    for (int i = 0; i < n; i++)
        if (matrix[vertex][i] and !used[i]) 
            dfs(i);
}            


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> startVertex;
    matrix.resize(n, vector<int> (n, 0));
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++) 
            cin >> matrix[row][column];
    used.resize(n, false);
    startVertex--;
    dfs(startVertex);
    cout << answer << '\n';
    return 0;
}