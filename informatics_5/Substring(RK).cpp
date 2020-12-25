#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void RabinKarp(string s, string t) {
    const uint_fast32_t p = 31;
    vector<ll> p_pow (max(s.length(), t.length()));
    p_pow[0] = 1;
    for (size_t i = 1; i < p_pow.size(); i++)
        p_pow[i] = p_pow[i - 1] * p;
    // count hashes from all prefixes of the string S
    vector<ll> hash (s.length());
    for (size_t i = 0; i < s.length(); i++) {
        hash[i] = (s[i] - 'a' + 1) * p_pow[i];
        if (i)  
        hash[i] += hash[i - 1];
    }

    // count the hash from the string T
    ll hash_t = 0;
    for (size_t i = 0; i < t.length(); i++)
        hash_t += (t[i] - 'a' + 1) * p_pow[i];
    // iterate over all substrings S of length | T | and compare them
    for (size_t i = 0; i + t.length() - 1 < s.length(); i++) {
        ll cur_hash = hash[i + t.length() - 1];
        if (i)  
        cur_hash -= hash[i - 1];
        // reduce hashes to one degree and compare
        if (cur_hash == hash_t * p_pow[i])
            cout << i << " ";
    }
    cout << '\n';
}

int main() {
    string s, t;
    cin >> s >> t;
    RabinKarp(s, t);
    return 0;
}
