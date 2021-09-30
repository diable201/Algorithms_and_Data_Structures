#include <iostream>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
};

struct bst {
    node *root;

    bst() {
        root = NULL;
    }

    void insert(int val) {
        node* new_node = new node(val);
        if (root == NULL) {
            root = new_node;
            return;
        }
        node* cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left == NULL) {
                    cur->left = new_node;
                    return;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right == NULL) {
                    cur->right = new_node;
                    return;
                } else {
                    cur = cur->right;
                }
            }
        }
    }

    int count(node* cur) {
        if (cur == NULL) return 0;
        return 1 + count(cur->left) + count(cur->right);
    }

    int depth(node* cur) {
        if (cur == NULL) return 0;
        return 1 + max(depth(cur->left), depth(cur->right));
    }
};

int main() {
    bst* tree = new bst();
    int x; 
    while (cin >> x) {
        if (x == 0) break;
        else tree->insert(x);
    }
    cout << tree->count(tree->root) << endl;
    cout << tree->depth(tree->root) << endl;
    return 0;
}