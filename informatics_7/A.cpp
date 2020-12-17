#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > matrix;
vector<int> colors;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int answer = 0;
    cin >> n;
    matrix.resize(n, vector<int> (n, 0));
    for (int row = 0; row < n; row++) 
        for (int column = 0; column < n; column++)
            cin >> matrix[row][column];

    colors.resize(n);
    for (int vertex = 0; vertex < n; vertex++) 
        cin >> colors[vertex];
                                                                                        
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++) 
            if (matrix[row][column] and colors[row] != colors[column])
                answer++;

    cout << answer / 2 << '\n';
    return 0;
}
