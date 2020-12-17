#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 1e12;
int n;
vector<vector<int>> matrix;


void solution() {
    ll best_distance = INF;
    vector<int> result;
    for (int v1 = 0; v1 < n; v1++) {
        for (int v2 = 0; v2 < n; v2++) {
            for (int v3 = 0; v3 < n; v3++) {
                if (v1 == v2 or v2 == v3 or v1 == v3) 
                    continue;
                if (matrix[v1][v2] + matrix[v2][v3] + matrix[v3][v1] < best_distance) {
                    best_distance = matrix[v1][v2] + matrix[v2][v3] + matrix[v3][v1];
                    result = {v1, v2, v3};
                }
            }
        }
    }
    for (int vertex : result)
        cout << vertex + 1 << " ";
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    matrix.resize(n, vector<int> (n, 0));
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++)
            cin >> matrix[row][column];
    solution();
    return 0;
}