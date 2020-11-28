#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    uint32_t x;
    cin >> s >> x;
    while (x--) {
        uint32_t n, m;
        string l = "";
        cin >> n >> m;
        uint32_t cnt = 0;
        for (int i = n - 1; i < m; i++)
            l += s[i];
        string text = l + "#" + s;
        vector<int> p = prefix_function(text);
        for (int i = l.size() + 1; i < text.size(); i++)
            if (p[i] == l.size()) cnt++;
        cout << cnt << '\n';
    }
    return 0;
}