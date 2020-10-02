#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    queue<int> d;
    queue<int> r;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D')
            d.push(i);
        else
            r.push(i);
    }
    while (!d.empty() && !r.empty()) {
        if (d.front() < r.front()) 
            d.push(d.front() + n);
        else
            r.push(r.front() + n);
        d.pop();
        r.pop();
    }
    if (d.empty())
        cout << "R\n";
    else
        cout << "D\n";
    return 0;
}