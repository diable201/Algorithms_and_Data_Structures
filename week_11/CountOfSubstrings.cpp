#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    set<string> a;
    cin >> s;
    for (int i = 0; i < s.size(); i++) { // i = 1, abab
        string w = "";
        for (int j = i; j < s.size(); j++) { // w = 'bab'
            w += s[j];
            a.insert(w);
        }
    }
    cout << a.size() << '\n';
    return 0;
}
// abab
// 7
// O(n^3 * log(n^2))