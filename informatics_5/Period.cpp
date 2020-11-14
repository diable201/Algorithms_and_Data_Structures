#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 and s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j; 
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    int n = s.size();
    int m = n - p[n - 1];
    if (n % m == 0) cout << n / m;
    else cout << 1;
    cout << '\n';
    return 0;
}
// ababababab
// 0 0 1 2 3 4 5 6 7 8 