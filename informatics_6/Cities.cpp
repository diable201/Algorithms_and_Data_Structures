#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAXN = 10;
uint_fast32_t n, m;

class Node {
public:
    char value;
    Node *ch[MAXN];
    uint_fast32_t tmp;
    string city;
    Node(char value, string city) {
        this->city = city;
        this->value = value;
        for (int i = 0; i < MAXN; i++)
            ch[i] = NULL;
        tmp = true;
    }
};

class Trie {
public:
    Node *root;
    int m;
    Trie (int m) {
        this->m = m;
        root = new Node(' ', " ");
    }

    void insert(string s, string city) {
        Node *cur = root;
        for (size_t i = 0; i < s.size(); i++) {
            if (cur->ch[s[i] - '0'] != NULL) {
                cur = cur->ch[s[i] - '0'];
                cur->tmp++;
            } else {
                Node *node = new Node(s[i], (i == s.size() - 1 ? city : " "));
                cur->ch[s[i] - '0'] = node;
                cur = node;
            }
        }
    }

    int search(Node *node, string s, int tmp = 0) {
        if (node->city == " ") {
            for (size_t i = 0; i < MAXN; i++)
                if (node->ch[i] != NULL)
                    tmp += search(node->ch[i], s + node->ch[i]->value);
            return tmp;
        } else {
            tmp = pow(10, m - s.size());
            for (size_t i = 0; i < MAXN; i++)
                if (node->ch[i] != NULL)
                    tmp -= search(node->ch[i], s + node->ch[i]->value);
            cout << node->city << " " << tmp << '\n';
            return pow(10, m - s.size());
        }
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    Trie *trie = new Trie(m);
    while (n--) {
        string phone_number, city;
        cin >> phone_number >> city;
        trie->insert(phone_number, city);
    }
    trie->search(trie->root, "");
    return 0;
}