#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data) 
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void branches(Node *node) {
        if (node == NULL)
            return;
        branches(node->left);
        if ((node->left == NULL and node->right != NULL)
            or (node->left != NULL and node->right == NULL))
            cout << node->data << '\n';
        branches(node->right);
    }

    void child(Node *node) {
        if (node == NULL)
            return;
        child(node->left);
        if (node->left == NULL and node->right == NULL)
            cout << node->data << '\n';
        child(node->right);
    }

    void postOrder(Node *node) {
        if (node == NULL)
            return;
        postOrder(node->right);
        cout << node->data << " ";
        postOrder(node->left);
    }

    Node *findMin(Node *node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node) {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    void forks(Node *node) {
        if (node == NULL)
            return;
        forks(node->left);
        if (node->left != NULL and node->right != NULL)
            cout << node->data << '\n';
        forks(node->right);
    }

    int count(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + count(node->left) + count(node->right);
    }

    int depth(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }

    bool isBalanced(Node *node) {
        if (node == NULL)
            return true;
        int left_depth = depth(node->left);
        int right_depth = depth(node->right);
        if (abs(left_depth - right_depth) <= 1 and isBalanced(node->left)
        and isBalanced(node->right))
            return true;
        return false;
    }

    void secondMax(Node *node) {
        if (node == NULL)
            return;
        static uint32_t cnt = 0;
        secondMax(node->right);
        cnt++;
        if (cnt == 2) {
            cout << node->data << '\n';
            // cout << cnt;
            return;
        }
        secondMax(node->left);
    }

    Node *deleteNode(Node *node, int data) {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (node->right == NULL && node->left == NULL)
                node = NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        } return node;
    } 
};

int main() {
    BST *bst = new BST();
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        else 
            bst->root = bst->insert(bst->root, n);
    }
    bst->secondMax(bst->root);
}