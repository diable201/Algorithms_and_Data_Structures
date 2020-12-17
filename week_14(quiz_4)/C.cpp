#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 10000;
int mario[MAXN][MAXN];
int a[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;


bool check_border(int x, int y) {
	return (x >= 0 and x < n and y >= 0 and y < m);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;
	queue <pair<int,int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			mario[i][j] = 1000000;
			if (a[i][j] == 2) {
				q.push(make_pair(i, j));
				mario[i][j] = 0;
			}			
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_x = x + dx[i];
			int y_y = y + dy[i];
			if (check_border(x_x, y_y) and a[x_x][y_y] == 1) {
				mario[x_x][y_y] = mario[x][y]+1;
				a[x_x][y_y] = 2;
				q.push(make_pair(x_x, y_y));	
			}
		}	
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				cout << -1;
				return 0;
			} else if (!a[i][j])
				continue;
			answer = max(answer, mario[i][j]);	
		}	
	}
	cout << answer << '\n';	
    return 0;
}