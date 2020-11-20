#include <bits/stdc++.h>

using namespace std;

const int N = 26;

class Node {
    public:
    char value;
    Node *ch[N];
    int cnt;
    Node(char value) {
        cnt = 1;
        this->value = value;
        for (int i = 0; i < N; i++)
            ch[i] = NULL;
    }
};

class Trie {
    public:
    Node *root;
    int cnt;
    Trie() {
        root = new Node (' ');
        cnt = 0;
    }

    void insert(string s) {
        Node *cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - 'a'] != NULL) {
                cur = cur->ch[s[i] - 'a'];
                cur->cnt++;
            } else {
                Node *node = new Node(s[i]);
                cur->ch[s[i] - 'a'] = node;
                cur = node;
            }
        }
    }

    void search(Node *node, string s) {
        if (s != "")
            cout << s << " - " << node->cnt << '\n';
        for (int i = 0; i < N; i++)
            if (node->ch[i] != NULL) 
                search(node->ch[i], s + node->ch[i]->value);
    }
};

int main() {
    Trie *trie = new Trie();
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie->insert(s);
    }
    trie->search(trie->root, "");
    return 0;
}
/*
8
abc
abcd
abbl
abbt
ab
bab
bacc
bbb
a - 5
ab - 5
abb - 2
abbl - 1
abbt - 1
abc - 2
abcd - 1
b - 3
ba - 2
bab - 1
bac - 1
bacc - 1
bb - 1
bbb - 1
*/