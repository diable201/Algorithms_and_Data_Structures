#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
int used[1000];
// int c[1000];
// a && b > 0
int f(int a, int b) {
    q.push(make_pair(a, 0));
    // used[a] = 1;
    used[a] = a;
    // c[a] = a; // c[2] = 2
    while (!q.empty()) {
        int x = q.front().first;
        int d = q.front().second;
        
        if (x == b)
            return d;

        if (used[x + 1] == 0) {
            q.push(make_pair(x + 1, d + 1));
            // used[x + 1] = 1;
            used[x + 1] = x;
            // c[x + 1] = x;
        }
        if (used[x * 2] == 0) {
            q.push(make_pair(x * 2, d + 1));
            // used[x * 2] = 1;
            used[x * 2] = x;
            // c[x * 2] = x;
        }

        if (used[x / 2] == 0) {
            q.push(make_pair(x / 2, d + 1));
            // used[x / 2] = 1;
            used[x / 2] = x; 
            // c[x / 2] = x;
        }

        if (x - 1 >= 0 && used[x - 1] == 0) {
            q.push(make_pair(x - 1, d + 1));
            // used[x - 1] = 1;
            used[x - 1] = x;
            // c[x - 1] = x;
        }
        q.pop();
    }
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << '\n';
    vector<int> result;
    result.push_back(b);
    int t = b;
    // t = 12;
    while (used[t] != t) {
        t = used[t];
        // t = 6, 3, 2;
        result.push_back(t);
    }
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " " << '\n';
    return 0; 
}