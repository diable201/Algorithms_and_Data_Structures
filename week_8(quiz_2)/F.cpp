#include <bits/stdc++.h>

using namespace std;

int a[100500];
long long n;

class Node {
    public:
    Node *left, *right;
    int data;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* balance(long long l, long long r) {  
    if (l > r)  
        return NULL;  
    long long m = (l + r) / 2;  
    Node *node = new Node(a[m]); 
    node->right = balance(m + 1, r); 
    node->left = balance(l, m - 1);  
    return node;  
}  

void out(Node* node) {  
    if (node == NULL)  
        return;  
    cout << node->data << " ";
    out(node->right);
    out(node->left);      
} 


void QuickSort(long long l, long long r) {
    long long i = l;
    long long j = r;
    long long p = a[(l + r) / 2];
    while (i < j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        QuickSort(l, j);
    if (i < r)
        QuickSort(i, r);
}


int main() {
    cin >> n;
    int m = pow(2, n) - 1;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    QuickSort(0, m - 1);
    Node *root = balance(0, m - 1);   
    out(root);
    cout << '\n';
    return 0;
}