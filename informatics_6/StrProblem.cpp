#include <bits/stdc++.h>

using namespace std;

const int AL = 26;
vector<vector<int>> ans;
vector<int> len;

struct TNode {
    TNode *ed[AL];
    TNode *prev, *link, *t_link;
    bool t;
    int c;
    vector<int> ind;
};

TNode *trie;

TNode *new_node() {
    TNode *node = new TNode;
    node->link = nullptr;
    node->t_link = nullptr;
    node->prev = nullptr;
    node->t = false;
    node->c = -1;

    for (int i = 0; i < AL; i++)
        node->ed[i] = nullptr;
    return node;
}

void add(TNode *root, string &s, int ind) {
    for (char c : s) {
        int symb = c - 'a';
        if (!(root->ed[symb])) {
            root->ed[symb] = new_node();
            root->ed[symb]->prev = root;
            root->ed[symb]->c = symb;
        }
        root = root->ed[symb];
    }
    root->t = true;
    root->ind.push_back(ind);
}

TNode *get_link(TNode *node) {
    if (node->link)
        return node->link;
    if (!(node->prev))
        return nullptr;
    TNode *link = get_link(node->prev);
    while ((link) && (!link->ed[node->c]))
        link = get_link(link);
    if (link)
        node->link = link->ed[node->c];
    else 
        node->link = trie;
    return node->link;
}

TNode *get_t_link(TNode *node) {
    if (node->t_link)
        return node->t_link;
    if (!(node->prev))
        return nullptr;
    TNode *link = get_link(node);
    if (!(link->prev))
        node->t_link = trie;
    else if (link->t) 
        node->t_link = link;
    else {
        TNode *t_link = get_t_link(link);
        node->t_link = t_link;
    }
    return node->t_link;
}


void find_words(TNode *node, string &s) {
    int i = 0;
    while (i < s.length()) {
        char c = s[i] - 'a';
        if (!node->ed[c]) {
            node = get_link(node);
            if (!node) {
                node = trie;
                i++;
            }
        } else {
            node = node->ed[c];
            TNode *w = node;
            while (w) {
                if (w->t)
                    for (auto e : w->ind)
                        ans[e].push_back(i - len[e] + 1);
                w = get_t_link(w);
            }
            i++;
        }
    }
}


int main() {
    freopen("inputik.txt", "r", stdin);
    freopen("outputik.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    trie = new_node();
    string s, w;
    cin >> s;
    int n;
    cin >> n;
    len.resize(n);
    ans.resize(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> w;
        len[i] = w.length();
        add(trie, w, i);
    }
    find_words(trie, s);
    for (int i = 0; i < n; i++) {
        cout << ans[i].size();
        for (auto e : ans[i])
            cout << " " << e + 1;
        cout << '\n';
    }
    return 0;
}