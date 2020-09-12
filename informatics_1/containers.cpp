#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s[n+1];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x--) {
            int y;
            cin >> y;
            s[i].push(y);
        }
    }
    if (n == 2) {
        stack<int> now = s[1], nw = s[2];
        while (!nw.empty()) {
            now.push(nw.top());
            nw.pop();
        }
        int ok = now.top(), cnt = 0;
        now.pop();
        while (!now.empty()) {
            if (ok == 0) {
                ok = now.top();
            } else {
                if (now.top() != ok) {
                    cnt++;
                    ok = now.top();
                }
            }
            now.pop();
        }
        if (cnt > 1) {
            cout << 0;
            return 0;
        }
    }
    //filling first container
    for (int i = 2; i <= n; i++) {
        while(!s[i].empty()) {
            s[1].push(s[i].top());
            s[i].pop();
            cout << i << " " << 1 << '\n';
        }
    }
    // filling all containers expect first and second
    while(!s[1].empty()) {
        int pos = s[1].top();
        if (pos <= 2) {
            s[2].push(pos);
            cout << "1 2\n";
        }
        else {
            s[pos].push(pos);
            cout << "1 " << pos << '\n';
        }
        s[1].pop();
    }
    // correctly filling first container
    while (!s[2].empty()) {
        int pos = s[2].top();
        if (pos == 2) {
            s[3].push(pos);
            cout << "2 3\n";
        }
        if (pos == 1) {
            s[1].push(pos);
            cout << "2 1\n";
        }
        s[2].pop();
    }
    // return second container elements 
    while (s[3].top() == 2) {
        s[2].push(2);
        cout << "3 2\n";
        s[3].pop();
    }
    return 0;
}
// n = 2
// 1 1 1 2
// 2 2 1
// 1 1 1 2 1 2 2
// n > 2 
// 1 1 1
// 2 2 2 2 2
// 3 3 3