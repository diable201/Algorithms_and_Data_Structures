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
    cin >> s;
    uint32_t cnt = 0;
    vector<int> p = prefix_function(s);
    for (int i = 1; i + 1 < s.size(); i += 2) {
        uint32_t answer = i + 1;
        uint32_t q = answer - p[i];
        if (answer % q == 0 and ((answer / 2) % q) == 0)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
