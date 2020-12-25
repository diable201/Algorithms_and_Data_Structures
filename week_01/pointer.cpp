#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);

    n1->next = n2;
    n2->next = n3;
    
    cout << "n1 = " << n1 << '\n';
    cout << "n2 = " << n2 << '\n';
    cout << "n3 = " << n3 << '\n';
    cout << "n1->next = " << n1->next << '\n';
    cout << "n2->next = " << n2->next << '\n';
    cout << "n3->next = " << n3->next << '\n';
    cout << n1->next->next->data << '\n';
    return 0;
}