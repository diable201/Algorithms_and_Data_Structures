#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> prefix_function(string s) {
	int n = s.size();
	vector<int> pi(n);
	pi[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 and s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    uint32_t answer;
    cin >> s >> answer;
    cin >> t;
    uint32_t n = s.size();
    string text = s + '#' + t;
    uint32_t w = text.size();
    uint32_t cnt = 0;
    vector<int> v = prefix_function(text);
    for (int i = n + 1; i < w; i++) 
        if (v[i] == n) cnt++;   
    if (cnt >= answer) 
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
