#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[750][750];
    int minimum[750], maximum[750];
    int answer = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];   

    for (int i = 0; i < n; i++) {
        minimum[i] = 1000;
        for (int j = 0; j < m; j++)
            if (a[i][j] < minimum[i]) 
                minimum[i] = a[i][j];
    }

    for (int j = 0; j < m; j++) {
        maximum[j] = -1000;
        for (int i = 0; i < n; i++)
            if (a[i][j] > maximum[j]) 
                maximum[j] = a[i][j];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((a[i][j] == minimum[i]) && (a[i][j] == maximum[j])) 
                answer++;
    cout << answer << '\n';
    return 0;
}
